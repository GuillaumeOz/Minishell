/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_double_greater_io_case.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:29:11 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/01 21:02:43 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_double_greater_io_case(t_ast *ast, t_lexer *lexer,
	t_lexer *limiter, t_lexer **reader)
{
	int *fd;

	fd = (int *)malloc(sizeof(int));
		if (fd == NULL)
			minishell_error("int * cannot be allocated");
	*fd = open((*reader)->args, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (*fd == -1)
		minishell_fork_greater_fd_error(lexer, limiter, (*reader)->args);
	list2_push_back(ast->out_fd, fd);
	cmd_output_gestion(lexer, limiter, ast);
}
