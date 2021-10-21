/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_input_is_case.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:19:09 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/21 14:08:05 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_exec_double_lower_io_case(t_lexer *lexer,
	t_lexer *limiter, t_lexer **reader)
{
	while (lexer != limiter)
	{
		if (lexer->type == DOUBLE_LOWER && lexer->next->over == false)
		{
			lexer->next->over = true;
			(*reader) = lexer->next;
			return (true);
		}
		lexer = lexer->next;
	}
	return (false);
}

t_bool	is_exec_lower_io_case(t_lexer *reader)
{
	if (reader->type == LOWER && reader->over == false)
	{
		reader->over = true;
		reader->next->over = true;
		return (true);
	}
	return (false);
}

t_bool	is_exec_here_doc_io_case(t_lexer *reader)
{
	if (reader->type == DOUBLE_LOWER && reader->over == false)
	{
		reader->over = true;
		return (true);
	}
	return (false);
}
