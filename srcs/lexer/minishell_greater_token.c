/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_greater_token.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:38:28 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/19 15:29:04 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*greater_token(t_lexer *lexer, char *line, int *i, char ***env)
{
	t_lexer	*new_lexer;

	if (line[*i + 1] == GREATER)
	{
		(*i) += 2;
		new_lexer = init_lexer(lexer, env, DOUBLE_GREATER, DEFAULT);
	}
	else
	{
		(*i) += 1;
		new_lexer = init_lexer(lexer, env, GREATER, DEFAULT);
	}
	return (new_lexer);
}
