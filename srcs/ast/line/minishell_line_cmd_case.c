/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_line_cmd_case.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:41:18 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/03 19:38:13 by gozsertt         ###   ########.fr       */
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
		cmd_handler(lexer);//redocall cmd here
		free_ast(ast);
	}
	else
	{
		*pid = fork();
		if (*pid == 0)
		{
			ast = malloc_ast(env);
			cmd_handler(lexer);//redo call cmd here
			free_ast(ast);
			exit(0);//remove this later execve
		}
	}
}
