/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_output_is_case.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:18:07 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/05 16:19:38 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_exec_double_greater_io_case(t_lexer *lexer,
	t_lexer *limiter, t_lexer **reader)
{
	while (lexer != limiter)
	{
		if (lexer->type == DOUBLE_GREATER && lexer->over == false)
		{
			lexer->over = true;
			lexer->next->over = true;
			(*reader) = lexer->next;
			return (true);
		}
		lexer = lexer->next;
	}
	return (false);
}

t_bool	is_exec_greater_io_case(t_lexer *lexer,
	t_lexer *limiter, t_lexer **reader)
{
	while (lexer != limiter)
	{
		if (lexer->type == GREATER && lexer->over == false)
		{
			lexer->over = true;
			lexer->next->over = true;
			(*reader) = lexer->next;
			return (true);
		}
		lexer = lexer->next;
	}
	return (false);
}
