/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_line_ast.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:06:04 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/24 07:18:45 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
//	line ::== cmd | line
//		 ::== cmd
*/

void	line_ast(t_lexer *lexer, pid_t *pid, t_ast_option option)
{
	t_ast	*ast;
	t_lexer *reader;

	reader = NULL;
	ast = NULL;
	if (option == LINE_OPTION_1)
	{
		if (is_cmd_pipe_line_case(lexer, &reader) == true)
		{
			fork();
			ast = malloc_ast();
			cmd_ast(lexer, reader, ast, CMD_OPTION_1);
			// print_token(reader);
			line_ast(reader, pid + 1, LINE_OPTION_1);
		}
		else
			line_ast(lexer, LINE_OPTION_2);
	}
	else if (option == LINE_OPTION_2)
	{
		if (lexer->fork == false)
			cmd_ast(lexer, reader, ast, CMD_OPTION_1);
		else
		{
			fork();
			cmd_ast(lexer, reader, ast, CMD_OPTION_1);

		}
	}
}
