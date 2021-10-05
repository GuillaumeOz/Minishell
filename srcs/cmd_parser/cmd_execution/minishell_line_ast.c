/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_line_ast.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:06:04 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/05 17:23:33 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
//	line ::== cmd | line
//		 ::== cmd
*/

void	line_ast(t_lexer *lexer, pid_t *pid, char ***env)
{
	t_lexer	*reader;

	reader = NULL;
	if (is_cmd_pipe_case(lexer, &reader) == true)
		cmd_pipe_case(lexer, reader, pid, env);
	else
		cmd_case(lexer, reader, pid, env);
}
