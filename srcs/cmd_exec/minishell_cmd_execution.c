/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_execution.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:31:23 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/08 20:00:56 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	wait_childs(pid_t *pid, int nb_cmd)
{
	int	i;

	i = 0;
	while (i < nb_cmd)
	{
		waitpid(pid[i], &g_exit_code, 0);
		i++;
	}
}

static void	cmd_exec_routine(t_lexer *lexer, t_cmd *cmd, pid_t *pid, int i)
{
	cmd_builder(cmd);
	if (lexer->fork == true)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			return ;// improve later ?
		else if (pid[i] == 0)
			cmd_executer();//keep working on it
		
	}
	// cmd_
}

void	cmd_execution(t_lexer *lexer, t_list2 *cmd_list, pid_t *pid)
{
	t_cmd	*cmd;
	int		i;

	i = 0;
	while (i < lexer->nb_cmd)
	{
		cmd = list2_at(cmd_list, i);
		if (is_cmd_null_case(cmd) == false)
			cmd_exec_routine(lexer, cmd, pid, i);
		i++;
	}
	if (pid != NULL)
		wait_childs(pid, lexer->nb_cmd);
}

	// 	close(pipex->pipe[0][0]);
	// 	it_is_here_doc_child(pipex);
	// 	dup2(pipex->pipe[0][1], STDOUT_FILENO);
	// 	if (pipex->here_doc == false)
	// 		close(pipex->fd_file1);
	// 	close(pipex->pipe[0][1]);
	// 	execve(pipex->cmds[0], pipex->args[0], env);
	// 	free_pipex(pipex);
	// 	pipex_error();
	// }
	// else
	// {
	// 	it_is_here_doc_parent(pipex);
	// 	close(pipex->pipe[0][1]);
	// }
