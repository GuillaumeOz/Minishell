/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_null_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:15:14 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/21 17:19:54 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	previous_is_null_checker(t_lexer *lexer)
{
	if (lexer->previous == NULL)
		return (true);
	else
		return (false);
}

t_bool	next_is_null_checker(t_lexer *lexer)
{
	if (lexer->next == NULL)
		return (true);
	else
		return (false);
}
