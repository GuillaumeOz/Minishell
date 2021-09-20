/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_greater_token.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:38:19 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/15 22:50:09 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*greater_token(t_lexer *lexer, char *line, int *i)
{
    t_lexer *new_lexer;

	if (line[*i + 1] == GREATER)
    {
        (*i) += 2;
        new_lexer = init_lexer(lexer, DOUBLE_GREATER, DEFAULT);
    }
    else
    {
        (*i) += 1;
        new_lexer = init_lexer(lexer, GREATER, DEFAULT);
    }
    return (new_lexer);
}
