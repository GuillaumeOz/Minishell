/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_case.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:26:04 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/01 14:41:55 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_case(t_ast *ast)
{
	(void)ast;
	PRINTS("EXEC")
	// cmd_ast(lexer, limiter, ast);
}
