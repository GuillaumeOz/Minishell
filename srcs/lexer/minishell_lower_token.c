/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lower_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:36:39 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/19 15:27:06 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*lower_token(t_lexer *lexer, char *line, int *i, char ***env)
{
	t_lexer	*new_lexer;

	if (line[*i + 1] == LOWER)
	{
		(*i) += 2;
		new_lexer = init_lexer(lexer, env, DOUBLE_LOWER, DEFAULT);
	}
	else
	{
		(*i) += 1;
		new_lexer = init_lexer(lexer, env, LOWER, DEFAULT);
	}
	return (new_lexer);
}
