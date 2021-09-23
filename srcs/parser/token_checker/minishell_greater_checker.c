/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_greater_checker.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 23:45:42 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/23 23:47:52 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	previous_is_greater_checker(t_lexer *lexer)
{
	if (lexer->previous == NULL)
		return (false);
	if (lexer->previous->type == GREATER)
		return (true);
	else
		return (false);
}

t_bool	next_is_greater_checker(t_lexer *lexer)
{
	if (lexer->next == NULL)
		return (false);
	if (lexer->next->type == GREATER)
		return (true);
	else
		return (false);
}
