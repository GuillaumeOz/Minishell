/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_here_doc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:27:33 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/29 20:07:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	compute_here_doc_line(t_cmd *cmd, char **line, int *i)
{
	size_t	len;

	if (cmd->limiter[*i][0] == 1)
		here_doc_dollar_transformation(cmd, line);
	len = ft_strlen(*line);
	write(cmd->here_doc_pipe[1], *line, len);
	write(cmd->here_doc_pipe[1], "\n", 1);
	free(*line);
	*line = NULL;
}

static void	exec_here_doc_routine(t_cmd *cmd, int *i, int weight)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (line != NULL && limitercmp(line, cmd->limiter[*i], weight) == true)
		{
			free(line);
			line = NULL;
			break ;
		}
		if (line == NULL)
		{
			here_doc_warning(cmd, line, i, weight);
			break ;
		}
		if (line != NULL && ft_strlen(line) != 0)
			compute_here_doc_line(cmd, &line, i);
		else
			free(line);
	}
	free(line);
	close(cmd->here_doc_pipe[1]);
	exit(0);
}

static void	here_doc_pipe_setter(t_cmd *cmd)
{
	if (cmd->here_doc_pipe == NULL)
	{
		cmd->here_doc_pipe = (int *)malloc(sizeof(int) * 2);
		if (cmd->here_doc_pipe == NULL)
			minishell_error("int * can't be allocated");
	}
	else
		close(cmd->here_doc_pipe[0]);
	pipe(cmd->here_doc_pipe);
}

static void	here_doc_case_gestion(t_lexer *lexer,
	t_cmd *cmd, pid_t child_status, int *i)
{
	if (child_status == 33280)
	{
		g_exit_code |= 130;
		g_exit_code |= SIG_HEREDOC_INT;
		cmd->error = true;
		set_lexer_error(lexer);
		close(cmd->here_doc_pipe[1]);
		close(cmd->here_doc_pipe[0]);
	}
	else
	{
		*i += 1;
		close(cmd->here_doc_pipe[1]);
		cmd->cmd_stdin = cmd->here_doc_pipe[0];
	}
}

void	exec_here_doc(t_lexer *lexer, t_cmd *cmd, int *i)
{
	pid_t	child_pid;
	int		child_status;
	int		weight;

	weight = 0;
	child_status = 0;
	if (cmd->limiter[*i][0] == 1)
		weight = 1;
	cmd->here_doc = true;
	here_doc_pipe_setter(cmd);
	child_pid = fork();
	g_exit_code |= SIG_HEREDOC_FATHER_INT;
	if (child_pid == 0)
	{
		g_exit_code |= SIG_HEREDOC_CHILD_INT;
		exec_here_doc_routine(cmd, i, weight);
	}
	else
		waitpid(child_pid, &child_status, 0);
	g_exit_code ^= SIG_HEREDOC_FATHER_INT;
	here_doc_case_gestion(lexer, cmd, child_status, i);
}
