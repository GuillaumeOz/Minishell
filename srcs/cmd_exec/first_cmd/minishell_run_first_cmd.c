/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run_first_cmd.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:38:14 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/11 18:49:48 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	it_is_here_doc_child(t_cmd *cmd)
{
	if (cmd->here_doc == true)
		if (cmd->here_doc_pipe[0] == cmd->cmd_stdin)
			dup2(cmd->here_doc_pipe[0], STDIN_FILENO);
	else
		dup2(cmd->cmd_stdin, STDIN_FILENO);
}

void	run_fisrt_cmd(t_cmd *cmd)
{	
	close(cmd->pipe[0]);
	it_is_here_doc_child(cmd);
	dup2(cmd->pipe[1], STDOUT_FILENO);
// 		if (pipex->here_doc == false)
// 			close(pipex->fd_file1);
// 		close(pipex->pipe[0][1]);
// 		execve(pipex->cmds[0], pipex->args[0], env);
// 		free_pipex(pipex);
// 		pipex_error();
}
