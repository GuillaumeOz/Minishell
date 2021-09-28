/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_is_case.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 03:56:41 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/28 17:37:52 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_exec_double_greater_io_case(t_lexer *lexer,
	t_lexer *limiter, t_lexer **reader)
{
	while (lexer != limiter)
	{
		if (lexer->type == DOUBLE_GREATER)
		{
			(*reader) = lexer->next;
			return (true);
		}
		lexer = lexer->next;
	}
	return (false);
}

t_bool	is_exec_double_lower_io_case(t_lexer *lexer,
	t_lexer *limiter, t_lexer **reader)
{
	while (lexer != limiter)
	{
		if (lexer->type == DOUBLE_LOWER)
		{
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
		if (lexer->type == GREATER)
		{
			(*reader) = lexer->next;
			return (true);
		}
		lexer = lexer->next;
	}
	return (false);
}

t_bool	is_exec_lower_io_case(t_lexer *lexer,
	t_lexer *limiter, t_lexer **reader)
{
	while (lexer != limiter)
	{
		if (lexer->type == LOWER)
		{
			(*reader) = lexer->next;
			return (true);
		}
		lexer = lexer->next;
	}
	return (false);
}

t_bool	is_exec_case(t_lexer *lexer, t_lexer *limiter, t_lexer **reader)
{
	while (lexer != limiter)
	{
		if (lexer->type == ARGS)
		{
			(*reader) = lexer->next;
			return (true);
		}
		lexer = lexer->next;
	}
	return (false);
}
