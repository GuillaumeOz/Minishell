/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lower_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:36:39 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/14 14:39:23 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*lower_token(t_lexer *lexer, char *line, int *i)
{
	t_lexer	*new_lexer;

	if (line[*i + 1] == LOWER)
	{
		(*i) += 2;
		new_lexer = init_lexer(lexer, DOUBLE_LOWER, DEFAULT);
	}
	else
	{
		(*i) += 1;
		new_lexer = init_lexer(lexer, LOWER, DEFAULT);
	}
	return (new_lexer);
}
