/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run_single_cmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:38:58 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/13 11:54:07 by gozsertt         ###   ########.fr       */
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
	free_list2(cmd->in_fd, destroy_fd_list_cmd);;
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

void	run_single_cmd(t_cmd *cmd)
{
	single_cmd_stdin_gestion(cmd);
	single_cmd_stdout_gestion(cmd);
	close_cmd_stdin(cmd);
	close_cmd_stdout(cmd);
	execve(cmd->cmd, cmd->args, *cmd->env);
	free_cmd((void *)cmd);
	//free lexer ?
}
		// close(pipex->pipe[0][0]);
		// it_is_here_doc_child(pipex);
		// dup2(pipex->pipe[0][1], STDOUT_FILENO);
		// if (pipex->here_doc == false)
		// 	close(pipex->fd_file1);
		// close(pipex->pipe[0][1]);
		// execve(pipex->cmds[0], pipex->args[0], env);
		// free_pipex(pipex);
		// pipex_error();
	
	// 	close(pipex->pipe[i][0]);
	// 	dup2(pipex->pipe[i - 1][0], STDIN_FILENO);
	// 	dup2(pipex->pipe[i][1], STDOUT_FILENO);
	// 	close(pipex->pipe[i - 1][0]);
	// 	close(pipex->pipe[i][1]);
	// 	execve(pipex->cmds[i], pipex->args[i], env);
	// 	free_pipex(pipex);
	// 	pipex_error();
	// }
	// else
	// {
	// 	close(pipex->pipe[i - 1][0]);
	// 	close(pipex->pipe[i][1]);
	// }