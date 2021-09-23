/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lower_checker.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 23:33:21 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/23 23:40:36 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	previous_is_lower_checker(t_lexer *lexer)
{
	if (lexer->previous == NULL)
		return (false);
	if (lexer->previous->type == LOWER)
		return (true);
	else
		return (false);
}

t_bool	next_is_lower_checker(t_lexer *lexer)
{
	if (lexer->next == NULL)
		return (false);
	if (lexer->next->type == LOWER)
		return (true);
	else
		return (false);
}
