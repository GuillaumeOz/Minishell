/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_here_doc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:27:33 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/03 16:41:09 by gozsertt         ###   ########.fr       */
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

static void	exec_here_doc_routine(t_ast *ast)
{
	char	*line;
	size_t	len;
	int		i;

	i = 0;
	while (here_doc_get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, ast->limiter[i]) == 0)
		{
			// write(1, "\n", 1);
			free(line);
			i++;
			if (ast->limiter[i] == NULL)
				break ;
		}
		else
		{
			len = ft_strlen(line);
			write(ast->here_doc_pipe[1], line, len);
			write(ast->here_doc_pipe[1], "\n", 1);
			free(line);
		}
		write(1, "> ", 2);
	}
}

void	exec_here_doc(t_ast *ast, t_lexer *lexer, t_lexer *limiter)
{
	pipe(ast->here_doc_pipe);
	write(1, "> ", 2);
	exec_here_doc_routine(ast);
	close(ast->here_doc_pipe[1]);
	ft_free_tab((void **)ast->limiter);
	ast->limiter = NULL;
	cmd_input_gestion(lexer, limiter, ast);
}
