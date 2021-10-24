/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_execution.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:31:23 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/24 21:26:24 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	close_father_cmd_stdin_stdout(t_cmd *cmd)
{
	free_list2(cmd->in_fd, destroy_fd_list_cmd);
	cmd->in_fd = NULL;
	free_list2(cmd->out_fd, destroy_fd_list_cmd);
	cmd->out_fd = NULL;
}

static void	close_father_pipe_cmd(t_cmd *cmd)
{
	if (cmd->pos == FIRST_POSITION && cmd->pipe != NULL)
	{
		if (cmd->here_doc == true)
			close(cmd->here_doc_pipe[0]);
		close(cmd->pipe[1]);
	}
	else if (cmd->pos == MIDDLE_POSITION)
	{
		if (cmd->here_doc == true)
			close(cmd->here_doc_pipe[0]);
		close(cmd->previous_pipe[0]);
		close(cmd->pipe[1]);
	}
	else if (cmd->pos == LAST_POSITION)
	{
		if (cmd->here_doc == true)
			close(cmd->here_doc_pipe[0]);
		close(cmd->previous_pipe[0]);
	}
}

static void	wait_childs(pid_t *pid, int nb_cmd)
{
	int		intsig;
	int	i;

	i = 0;
	intsig = g_exit_code;
	while (i < nb_cmd)
	{
		waitpid(pid[i], &g_exit_code, 0);
		if (WIFEXITED(g_exit_code) == true)
			g_exit_code = WEXITSTATUS(g_exit_code);
		if (WIFSIGNALED(g_exit_code) == true)
			g_exit_code = WTERMSIG(g_exit_code);
		if (intsig == 130)
			g_exit_code = 130;
		i++;
	}
}

static void	cmd_exec_routine(t_lexer *lexer, t_cmd *cmd, pid_t *pid, int i)
{
	cmd_builder(cmd);
	if (lexer->fork == true && cmd->error == false)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			return ;
		else if (pid[i] == 0)
			cmd_executer(cmd, lexer);
		else
		{
			close_father_cmd_stdin_stdout(cmd);
			close_father_pipe_cmd(cmd);
		}
	}
	else if (cmd->error == false)
		cmd_out_fork_executer(cmd, lexer);
}
	// test file without autorization chmod 000 < file1 cat
	// handle the case "< file << end | < file2 << end1" as same as bash

void	cmd_execution(t_lexer *lexer, t_list2 *cmd_list, pid_t *pid)
{
	t_cmd	*cmd;
	int		*previous_pipe;
	int		i;

	i = 0;
	previous_pipe = NULL;
	while (i < lexer->nb_cmd)
	{
		cmd = list2_at(cmd_list, i);
		if (cmd->pos == MIDDLE_POSITION || cmd->pos == LAST_POSITION)
			cmd->previous_pipe = previous_pipe;
		previous_pipe = cmd->pipe;
		if (is_cmd_null_case(cmd) == false)
		{
			cmd_exec_routine(lexer, cmd, pid, i);
			//add close father fd if necessary
		}
		i++;
	}
	if (pid != NULL)
		wait_childs(pid, lexer->nb_cmd);
}
