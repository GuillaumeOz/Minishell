/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_simple_quote_transformation.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:09:03 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/21 13:04:03 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	compute_simple_quote(t_lexer *lexer, int *i)
{
	char	*before;
	char	*inside;
	char	*after;
	int		start;
	size_t	j;

	before = ft_strndup(lexer->args, *i);
	(*i) += 1;
	start = (*i);
	while (lexer->args[(*i)] != QUOTE)
		(*i) += 1;
	inside = ft_strndup(lexer->args + start, (*i) - start);
	(*i) += 1;
	inside = ft_strappend(before, inside, true, true);
	j = ft_strlen(lexer->args + (*i));
	after = ft_strndup(lexer->args + (*i), j);
	free(lexer->args);
	(*i) -= 2;
	// (*i) += ft_strlen(inside);
	lexer->args = ft_strappend(inside, after, true, true);
}

void	simple_quote_transformation(t_lexer *lexer)
{
	int	i;

	i = 0;
	while (lexer->args[i] != '\0')
	{
		if (lexer->args[i] == QUOTE)
			compute_simple_quote(lexer, &i);
		else if (lexer->args[i] == DOLLAR)
			compute_dollar(lexer, &i);
		else
			i++;
	}
	lexer->format = DEFAULT;
}
