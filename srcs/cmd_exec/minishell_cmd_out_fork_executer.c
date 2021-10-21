/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_out_fork_executer.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:35:33 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/21 20:26:52 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	close_cmd_stdout(t_cmd *cmd)
{
	free_list2(cmd->out_fd, destroy_fd_list_cmd);
	cmd->out_fd = NULL;
}

static void	close_cmd_stdin(t_cmd *cmd)
{
	free_list2(cmd->in_fd, destroy_fd_list_cmd);
	cmd->in_fd = NULL;
}

static int	single_cmd_stdout_gestion(t_cmd *cmd, int *stdout_dup)
{
	int stdout_ret;

	stdout_ret = 1;
	if (cmd->cmd_stdout != STDOUT_FILENO)
	{
		*(stdout_dup) = dup(STDOUT_FILENO);
		dup2(cmd->cmd_stdout, STDOUT_FILENO);
		stdout_ret = cmd->cmd_stdout;
	}
	return (stdout_ret);
}

static int	single_cmd_stdin_gestion(t_cmd *cmd, int *stdin_dup)
{
	int stdin_ret;

	stdin_ret = 0;
	if (cmd->here_doc == true && cmd->here_doc_pipe[0] == cmd->cmd_stdin)
	{
		*(stdin_dup) = dup(STDIN_FILENO);
		dup2(cmd->here_doc_pipe[0], STDIN_FILENO);
		stdin_ret = cmd->here_doc_pipe[0];
		return (stdin_ret);
	}
	else if (cmd->here_doc == true)
		close(cmd->here_doc_pipe[0]);
	if (cmd->cmd_stdin != STDIN_FILENO)
	{
		*(stdin_dup) = dup(STDIN_FILENO);
		dup2(cmd->cmd_stdin, STDIN_FILENO);
		stdin_ret = cmd->cmd_stdin;
	}
	return (stdin_ret);
}

void	cmd_out_fork_executer(t_cmd *cmd, t_lexer *lexer)
{
	int stdin_ret;
	int stdout_ret;
	int stdin_dup;
	int stdout_dup;

	stdin_ret = 0;
	stdout_ret = 1;
	stdin_ret = single_cmd_stdin_gestion(cmd, &stdin_dup);
	stdout_ret = single_cmd_stdout_gestion(cmd, &stdout_dup);
	cmd_builtin_executer(cmd, lexer);
	close_cmd_stdin(cmd);
	close_cmd_stdout(cmd);
	if (stdin_ret != 0)
	{
		dup2(stdin_dup, STDIN_FILENO);
		close(stdin_dup);
	}
	if (stdout_ret != 1)
	{
		dup2(stdout_dup, STDOUT_FILENO);
		close(stdout_dup);
	}
}


// ...

// int saved_stdout;

// ...

// /* Save current stdout for use later */
// saved_stdout = dup(1);
// dup2(my_temporary_stdout_fd, 1);

// ... do some work on your new stdout ...

// /* Restore stdout */
// dup2(saved_stdout, 1);
// close(saved_stdout);