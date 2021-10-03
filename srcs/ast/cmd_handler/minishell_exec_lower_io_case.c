/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_lower_io_case.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:26:43 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/03 17:02:50 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_lower_io_case(t_ast *ast, t_lexer *lexer,
	t_lexer *limiter, t_lexer **reader)
{
	int *fd;

	// PRINTS("LOWER")
	fd = (int *)malloc(sizeof(int));
		if (fd == NULL)
			minishell_error("int * cannot be allocated");
	*fd = open((*reader)->args, O_RDONLY);
	if (*fd == -1)
		minishell_fork_lower_fd_error(lexer, limiter, (*reader)->args);
	list2_push_back(ast->in_fd, fd);
	cmd_input_gestion(lexer, limiter, ast);
}
