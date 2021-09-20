/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lower_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:37:07 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/15 23:05:12 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*lower_token(t_lexer *lexer, char *line, int *i)
{
	t_lexer *new_lexer;

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
