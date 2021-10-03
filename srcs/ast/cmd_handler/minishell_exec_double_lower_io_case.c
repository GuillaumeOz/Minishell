/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_double_lower_io_case.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:28:50 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/03 17:02:11 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_double_lower_io_case(t_ast *ast, t_lexer *lexer,
	t_lexer *limiter, t_lexer **reader)
{
	// PRINTS("DOUBLE LOWER")
	ast->here_doc = true;
	if (ast->limiter == NULL)
	{
		ast->limiter = (char **)ft_tab_new(1);
		ft_add_to_tab((*reader)->args, (void ***)&(ast->limiter));
	}
	else
		ft_add_to_tab((*reader)->args, (void ***)&(ast->limiter));
	cmd_input_gestion(lexer, limiter, ast);
}
