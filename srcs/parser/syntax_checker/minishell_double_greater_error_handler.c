/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_double_greater_error_handler.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:52:45 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/30 17:06:38 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool next_is_redirection(t_lexer *lexer, char **token)
{
	if (next_is_double_greater_checker(lexer) == true)
	{
		(*token) = ">>";
		return (true);
	}
	else if (next_is_double_lower_checker(lexer) == true)
	{
		(*token) = "<<";
		return (true);
	}
	else if (next_is_greater_checker(lexer) == true)
	{
		(*token) = ">";
		return (true);
	}
	else if (next_is_lower_checker(lexer) == true)
	{
		(*token) = "<";
		return (true);
	}
	return (false);
}

t_bool	double_greater_error_handler(t_lexer *lexer)
{
	char *token;

	if (next_is_null_checker(lexer) == true)
	{
		minishell_syntax_error(lexer, "newline");
		return (true);
	}
	else if (next_is_redirection(lexer, &token) == true)
	{
		minishell_syntax_error(lexer, token);
		return (true);
	}
	return (false);
}
