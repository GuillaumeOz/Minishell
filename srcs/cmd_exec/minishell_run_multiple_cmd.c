/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run_multiple_cmd.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:45:08 by gozsertt          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/10/21 13:50:33 by gozsertt         ###   ########.fr       */
=======
/*   Updated: 2021/10/21 13:02:35 by chdespon         ###   ########.fr       */
>>>>>>> 2a23804e6ddbff4bd9f2717b59d69c2dd6bf5153
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	close_cmd_stdin(t_cmd *cmd)
{
	free_list2(cmd->in_fd, destroy_fd_list_cmd);
	cmd->in_fd = NULL;
}

static void	close_cmd_stdout(t_cmd *cmd)
{
	free_list2(cmd->out_fd, destroy_fd_list_cmd);
	cmd->out_fd = NULL;
}

static void	multiple_cmd_stdin_gestion(t_cmd *cmd)
{
	if (cmd->here_doc == true && cmd->here_doc_pipe[0] == cmd->cmd_stdin)
	{
		dup2(cmd->here_doc_pipe[0], STDIN_FILENO);
		if (cmd->pos == MIDDLE_POSITION || cmd->pos == LAST_POSITION)
			close(cmd->previous_pipe[0]);
		return ;
	}
	else if (cmd->here_doc == true)
		close(cmd->here_doc_pipe[0]);
	if ((cmd->pos == MIDDLE_POSITION || cmd->pos == LAST_POSITION)
		&& cmd->cmd_stdin == STDIN_FILENO)
		dup2(cmd->previous_pipe[0], STDIN_FILENO);
	else if (cmd->cmd_stdin != STDIN_FILENO)
	{
		dup2(cmd->cmd_stdin, STDIN_FILENO);
		if (cmd->pos == MIDDLE_POSITION || cmd->pos == LAST_POSITION)
			close(cmd->previous_pipe[0]);
	}
}

static void	multiple_cmd_stdout_gestion(t_cmd *cmd)
{
	if ((cmd->pos == FIRST_POSITION || cmd->pos == MIDDLE_POSITION)
		&& cmd->cmd_stdout == STDOUT_FILENO)
		dup2(cmd->pipe[1], STDOUT_FILENO);
	else if (cmd->cmd_stdout != STDOUT_FILENO)
	{
		dup2(cmd->cmd_stdout, STDOUT_FILENO);
		if (cmd->pos == FIRST_POSITION || cmd->pos == MIDDLE_POSITION)
			close(cmd->pipe[1]);
	}
}

void	run_multiple_cmd(t_cmd *cmd, t_lexer *lexer)
{
	multiple_cmd_stdin_gestion(cmd);
	multiple_cmd_stdout_gestion(cmd);
	close_cmd_stdin(cmd);
	close_cmd_stdout(cmd);
	if (is_cmd_builtin_case(cmd) == true)
	{
		cmd_builtin_executer(cmd, lexer);
		quit_builtin(cmd, lexer);
	}
	else
	{
		execve(cmd->cmd, cmd->args, *cmd->env);
		quit_execve(cmd, lexer);
	}
}
