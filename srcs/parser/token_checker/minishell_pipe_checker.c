/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pipe_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 00:18:30 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/24 00:22:51 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	previous_is_pipe_checker(t_lexer *lexer)
{
	if (lexer->previous == NULL)
		return (false);
	if (lexer->previous->type == PIPE)
		return (true);
	else
		return (false);
}

t_bool	next_is_pipe_checker(t_lexer *lexer)
{
	if (lexer->next == NULL)
		return (false);
	if (lexer->next->type == PIPE)
		return (true);
	else
		return (false);
}
