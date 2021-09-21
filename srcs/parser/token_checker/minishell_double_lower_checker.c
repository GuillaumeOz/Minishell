/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_double_lower_checker.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:11:17 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/21 17:17:54 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	previous_is_double_lower(t_lexer *lexer)
{
	if (lexer->previous == NULL)
		return (false);
	if (lexer->previous->type == DOUBLE_LOWER)
		return (true);
	else
		return (false);
}

t_bool	next_is_double_lower(t_lexer *lexer)
{
	if (lexer->next == NULL)
		return (false);
	if (lexer->next->type == DOUBLE_LOWER)
		return (true);
	else
		return (false);
}
