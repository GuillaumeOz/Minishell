/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_greater_error_handler.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:45:53 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/23 20:09:06 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	greater_error_handler(t_lexer *lexer)
{
	if (next_is_null_checker(lexer) == true)
	{
		minishell_syntax_error(lexer, "newline");
		return (true);
	}
	return (false);
}
