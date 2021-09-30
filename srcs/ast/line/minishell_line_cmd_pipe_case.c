/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_line_cmd_pipe_case.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:38:54 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/30 16:40:35 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_pipe_case(t_lexer *lexer, t_lexer *reader, pid_t *pid, char ***env)
{
	t_ast	*ast;

	ast = NULL;
	*pid = fork();
	if (*pid == 0)
	{
		ast = malloc_ast(env);
		cmd_ast(lexer, reader, ast, CMD_OPTION_1);
		free_ast(ast);
		exit(0);//delete this
	}
	line_ast(reader, pid + 1, env, LINE_OPTION_1);
}
