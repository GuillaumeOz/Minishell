/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_double_quote_transformation.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:09:35 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/21 16:47:36 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	compute_double_quote(t_lexer *lexer, int *i)
{
	char	*before;
	char	*inside;
	char	*after;
	int		start;
	size_t	j;

	before = ft_strndup(lexer->args, *i);
	(*i) += 1;
	start = (*i);
	while (lexer->args[(*i)] != QUOTES)
	{
		if (lexer->args[*i] == DOLLAR
			&& previous_is_double_lower_checker(lexer) == false)
			compute_dollar(lexer, i);
		else
			(*i) += 1;
	}
	inside = ft_strndup(lexer->args + start, (*i) - start);
	(*i) += 1;
	inside = ft_strappend(before, inside, true, true);
	j = ft_strlen(lexer->args + (*i));
	after = ft_strndup(lexer->args + (*i), j);
	free(lexer->args);
	(*i) -= 2;
	lexer->args = ft_strappend(inside, after, true, true);
}

void	double_quote_transformation(t_lexer *lexer)
{
	int	i;

	i = 0;
	while (lexer->args[i] != '\0')
	{
		if (lexer->args[i] == QUOTES)
			compute_double_quote(lexer, &i);
		else if (lexer->args[i] == DOLLAR
			&& previous_is_double_lower_checker(lexer) == false)
			compute_dollar(lexer, &i);
		else
			i++;
	}
	lexer->here_doc_exp = false;
	lexer->format = DEFAULT;
}
