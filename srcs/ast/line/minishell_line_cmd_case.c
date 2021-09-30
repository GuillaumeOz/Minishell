/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_line_cmd_case.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:41:18 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/30 15:17:17 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_case(t_lexer *lexer, t_lexer *reader, pid_t *pid, char ***env)
{
	t_ast	*ast;

	ast = NULL;
	if (lexer->fork == false)
	{
		ast = malloc_ast(env);
		cmd_ast(lexer, reader, ast, CMD_OPTION_1);
		free_ast(ast);
	}
	else
	{
		*pid = fork();
		if (*pid == 0)
		{
			ast = malloc_ast(env);
			cmd_ast(lexer, reader, ast, CMD_OPTION_1);
			free_ast(ast);
			exit(0);
		}
	}
}
