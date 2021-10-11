/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_execution.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:31:23 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/11 18:32:50 by gozsertt         ###   ########.fr       */
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
	if (lexer->fork == true && cmd->error == false)
	{
		pid[i] = fork();
		// 	{
		// 		free_pipex(pipex);
		// 		pipex_error();
		// 	} for pid < 0
		if (pid[i] < 0)
			return ;// improve later ?
		else if (pid[i] == 0)
			cmd_executer(cmd);//keep working on it

		
	}// test case << end cat > file1 | cat --> close entré pipe cat affiche rien
	//test file without autorization chmod 000 < file1 cat
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

// static void	it_is_here_doc_parent(t_pipex *pipex)
// {
// 	if (pipex->here_doc == false)
// 		close(pipex->fd_file1);
// 	else
// 		close(pipex->here_doc_pipe[0]);
// }

// static void	it_is_here_doc_child(t_pipex *pipex)
// {
// 	if (pipex->here_doc == false)
// 		dup2(pipex->fd_file1, STDIN_FILENO);
// 	else
// 		dup2(pipex->here_doc_pipe[0], STDIN_FILENO);
// }



// 	else POS 1
// 	{
// 		it_is_here_doc_parent(pipex);
// 		close(pipex->pipe[0][1]);
// 	}
// }