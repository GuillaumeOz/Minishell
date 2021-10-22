/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_here_doc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:27:33 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/22 17:33:43 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	here_doc_gnl_recursive(int fd, char **line, int index)
{
	char	buffer;
	int		ret;

	ret = read(fd, &buffer, 1);
	if (ret == -1)
		return (-1);
	if (ret == 1 && buffer != '\n')
	{
		ret = here_doc_gnl_recursive(fd, line, index + 1);
		if (ret == -1)
			return (-1);
		(*line)[index] = buffer;
	}
	else
	{
		(*line) = (char *)malloc(sizeof(char) * (index + 1));
		if ((*line) == NULL)
			return (-1);
		(*line)[index] = '\0';
	}
	return (ret);
}

static int	here_doc_get_next_line(int fd, char **line)
{
	int	ret;

	ret = here_doc_gnl_recursive(fd, line, 0);
	if (line == NULL || ret == -1)
		return (-1);
	return (ret);
}

static void	exec_here_doc_routine(t_cmd *cmd, int *i, int weight)
{
	char	*line;
	size_t	len;

	while (here_doc_get_next_line(0, &line) > 0)//remplace by readline ?
	{
		if (ft_strcmp(line, (cmd->limiter[*i] + weight)) == 0)
		{
			free(line);
			line = NULL;
			*i += 1;
			break ;
		}
		else
		{
			if (cmd->limiter[*i][0] == 1)
				here_doc_dollar_transformation(cmd, &line);
			len = ft_strlen(line);
			write(cmd->here_doc_pipe[1], line, len);
			write(cmd->here_doc_pipe[1], "\n", 1);
			free(line);
			line = NULL;
		}
		write(1, "> ", 2);
	}
	if (line != NULL)
	{
		free(line);
		ft_putstr_fd(2, "bash: avertissement : « here-document » à la ligne 1 "
			"délimité par la fin du fichier (au lieu de « end »)\n");
	}
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

void	exec_here_doc(t_cmd *cmd, int *i)//test signal here_doc
{
	int weight;

	weight = 0;
	if (cmd->limiter[*i][0] == 1)
		weight = 1;
	cmd->here_doc = true;
	here_doc_pipe_setter(cmd);
	write(1, "> ", 2);
	exec_here_doc_routine(cmd, i, weight);
	close(cmd->here_doc_pipe[1]);
	cmd->cmd_stdin = cmd->here_doc_pipe[0];
}
