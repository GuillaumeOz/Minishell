/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_greater_io_case.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:27:50 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/24 22:17:31 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_greater_io_case(t_cmd *cmd, t_lexer *lexer,
	t_lexer *limiter, t_lexer *reader)
{
	int	*fd;

	fd = (int *)malloc(sizeof(int));
	if (fd == NULL)
		minishell_error("int * cannot be allocated");
	*fd = open(reader->args, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (*fd == -1)
		minishell_greater_fd_error(lexer, limiter, reader->args);
	list2_push_back(cmd->in_fd, fd);
	cmd->cmd_stdout = *fd;
}
