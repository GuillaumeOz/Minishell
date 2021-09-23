/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_double_greater_checker.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 23:44:43 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/23 23:48:51 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	previous_is_double_greater_checker(t_lexer *lexer)
{
	if (lexer->previous == NULL)
		return (false);
	if (lexer->previous->type == DOUBLE_GREATER)
		return (true);
	else
		return (false);
}

t_bool	next_is_double_greater_checker(t_lexer *lexer)
{
	if (lexer->next == NULL)
		return (false);
	if (lexer->next->type == DOUBLE_GREATER)
		return (true);
	else
		return (false);
}
