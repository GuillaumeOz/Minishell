/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pipe_error_handler.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 22:00:16 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/24 00:27:26 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	pipe_previous_is_lower_greater_checker(t_lexer *lexer)
{
	if (previous_is_lower_checker(lexer) == true
		|| previous_is_double_lower_checker(lexer) == true)
	{
		minishell_syntax_error(lexer, "|");
		return (true);
	}
	else if (previous_is_greater_checker(lexer) == true
		|| previous_is_double_greater_checker(lexer))
	{
		minishell_syntax_error(lexer, "|");
		return (true);
	}
	return (false);
}

t_bool	pipe_error_handler(t_lexer *lexer)
{
	if (previous_is_null_checker(lexer) == true)
	{
		minishell_syntax_error(lexer, "|");
		return (true);
	}
	else if (pipe_previous_is_lower_greater_checker(lexer) == true)
		return (true);
	else if (next_is_null_checker(lexer) == true)
	{
		minishell_multiline_error(lexer, "|");
		return (true);
	}
	else if (next_is_pipe_checker(lexer) == true)
	{
		minishell_syntax_error(lexer, "|");
		return (true);
	}
	return (false);
}
