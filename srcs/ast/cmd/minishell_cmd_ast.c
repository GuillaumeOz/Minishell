/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_ast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:21:13 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/24 06:46:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



	// t_lexer *reader;

	// reader = NULL;
	// if (option == LINE_OPTION_1)
	// {
	// 	if (is_line_pipe(lexer, &reader) == true)
	// 	{
	// 		cmd_ast(lexer, CMD_OPTION_1);
	// 		print_token(reader);
	// 		line_ast(reader, LINE_OPTION_1);
	// 	}
	// 	else
	// 		line_ast(reader, LINE_OPTION_2);
	// }
	// else if (option == LINE_OPTION_2)
	// 	cmd_ast(lexer, CMD_OPTION_1);

//	cmd	 ::== exec >> io
//		 ::== exec << io
//		 ::== exec > io
//		 ::== exec < io
//		 ::== exec

void	cmd_ast(t_lexer *lexer, t_lexer *limiter,
	t_ast *ast, t_ast_option option)
{
	t_lexer *reader;

	reader = NULL;
	if (option == CMD_OPTION_1)
		is_exec_double_greater_io_case(lexer, limiter, &reader);
	else if (option == CMD_OPTION_2)
		is_exec_double_lower_io_case(lexer, limiter, &reader);
	else if (option == CMD_OPTION_3)
		is_exec_greater_io_case(lexer, limiter, &reader);
	else if (option == CMD_OPTION_4)
		is_exec_lower_io_case(lexer, limiter, &reader);
	else if (option == CMD_OPTION_5)
		is_exec_case(lexer, limiter, &reader);
}
