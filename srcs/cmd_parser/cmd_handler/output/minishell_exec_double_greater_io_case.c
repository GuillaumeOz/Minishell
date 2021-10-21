/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_double_greater_io_case.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:29:11 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/21 14:51:58 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_double_greater_io_case(t_cmd *cmd, t_lexer *lexer,
	t_lexer *limiter, t_lexer *reader)
{
	int	*fd;

	fd = (int *)malloc(sizeof(int));
	if (fd == NULL)
		minishell_error("int * cannot be allocated");
	*fd = open(reader->args, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (*fd == -1)
		minishell_greater_fd_error(lexer, limiter, reader->args);
	list2_push_back(cmd->out_fd, fd);
	cmd->cmd_stdout = *fd;
}
