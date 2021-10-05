/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_is_case.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 03:56:41 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/05 16:22:28 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_exec_case(t_lexer *lexer, t_lexer *limiter, t_lexer **reader)
{
	while (lexer != limiter)
	{
		if (lexer->type == ARGS && lexer->over == false)
		{
			lexer->over = true;
			(*reader) = lexer;
			return (true);
		}
		lexer = lexer->next;
	}
	return (false);
}
