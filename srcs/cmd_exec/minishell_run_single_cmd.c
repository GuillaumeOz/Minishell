/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run_single_cmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:38:58 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/20 11:54:42 by gozsertt         ###   ########.fr       */
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

static void	single_cmd_stdout_gestion(t_cmd *cmd)
{
	if (cmd->cmd_stdout != STDOUT_FILENO)
		dup2(cmd->cmd_stdout, STDOUT_FILENO);
}

static void	single_cmd_stdin_gestion(t_cmd *cmd)
{
	if (cmd->here_doc == true && cmd->here_doc_pipe[0] == cmd->cmd_stdin)
	{
		dup2(cmd->here_doc_pipe[0], STDIN_FILENO);
		return ;
	}
	else if (cmd->here_doc == true)
		close(cmd->here_doc_pipe[0]);
	if (cmd->cmd_stdin != STDIN_FILENO)
		dup2(cmd->cmd_stdin, STDIN_FILENO);
}

void	run_single_cmd(t_cmd *cmd, t_lexer *lexer)
{
	single_cmd_stdin_gestion(cmd);
	single_cmd_stdout_gestion(cmd);
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
