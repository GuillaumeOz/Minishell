/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_line_ast.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:06:04 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/18 22:20:32 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	line ::== cmd | line
//		 ::== cmd

static t_bool is_line_pipe(t_lexer *lexer, t_lexer **reader)
{
	while (lexer != NULL)
	{
		if (lexer->type == PIPE)// check the '|' end token
		{
			(*reader) = lexer->next;
			return (true);
		}
		lexer = lexer->next;
	}
	return (false);
}

void	line_ast(t_lexer *lexer, t_ast_option option)
{
	t_lexer *reader;

	reader = NULL;
	if (option == LINE_OPTION_1)
	{
		if (is_line_pipe(lexer, &reader) == true)
		{
			cmd_ast(lexer, CMD_OPTION_1);
			print_token(reader);
			line_ast(reader, LINE_OPTION_1);
		}
		else
			line_ast(reader, LINE_OPTION_2);
	}
	else if (option == LINE_OPTION_2)
		cmd_ast(lexer, CMD_OPTION_1);
}
