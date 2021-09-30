/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_ast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:21:13 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/30 21:35:03 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	cmd	 ::== exec >> io
//		 ::== exec << io
//		 ::== exec < io
//		 ::== exec > io
//		 ::== exec
//
//	io	 ::== file >> file
//       ::== file << file
//       ::== file < file
//       ::== file > file
//       ::== file
//
//	exec ::== execname + args	args ::== arg + args
//		 ::== execname				 ::== arg

void	cmd_ast(t_lexer *lexer, t_lexer *limiter,
	t_ast *ast, t_ast_option option)
{
	t_lexer *reader;

	reader = NULL;
	(void)ast;
	if (option == CMD_OPTION_1)
		if (is_exec_double_greater_io_case(lexer, limiter, &reader) == true)
			exec_double_greater_io_case(ast, lexer, limiter, &reader);
		else
			cmd_ast(lexer, limiter, ast, CMD_OPTION_2);
	else if (option == CMD_OPTION_2)
		if (is_exec_double_lower_io_case(lexer, limiter, &reader) == true)
			exec_double_lower_io_case();
		else
			cmd_ast(lexer, limiter, ast, CMD_OPTION_3);
	else if (option == CMD_OPTION_3)
		if (is_exec_greater_io_case(lexer, limiter, &reader) == true)
			exec_greater_io_case();
		else
			cmd_ast(lexer, limiter, ast, CMD_OPTION_4);
	else if (option == CMD_OPTION_4)
		if (is_exec_lower_io_case(lexer, limiter, &reader) == true)
			exec_lower_io_case();
		else
			cmd_ast(lexer, limiter, ast, CMD_OPTION_5);
	else if (option == CMD_OPTION_5)
		if (is_exec_case(lexer, limiter, &reader) == true)
			exec_case();
}
