/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lower_error_handler.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:36:34 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/24 01:03:28 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	lower_error_handler(t_lexer *lexer)
{
	if (next_is_null_checker(lexer) == true)
	{
		minishell_syntax_error(lexer, "newline");
		return (true);
	}
	return (false);
}
