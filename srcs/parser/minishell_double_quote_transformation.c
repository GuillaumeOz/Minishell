/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_double_quote_transformation.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:09:35 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/17 05:56:18 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	compute_dollar(t_lexer *lexer, int *i)
{
	char	*before;
	char	*env;
	char	*after;
	char	*converted_env;
	int		j;

	j = 0;
	before = ft_strndup(lexer->args, (*i));
	while (ft_is_whitespaces(lexer->args[(*i) + j + 1]) == false
		&& lexer->args[(*i) + j + 1] != QUOTES
		&& lexer->args[(*i) + j + 1] != '\0')
		j++;
	env = ft_strndup(lexer->args + (*i) + 1, j);
	converted_env = getenv(env);
	free(env);
	after = ft_strdup(lexer->args + (*i) + 1 + j);
	free(lexer->args);
	if (converted_env != NULL)
	{
		converted_env = ft_strappend(before, converted_env, true, false);
		lexer->args = ft_strappend(converted_env, after, true, true);
	}
	else
		lexer->args = ft_strappend(before, after, true, true);
}

void    compute_double_quote(t_lexer *lexer, int *i)
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
		if (lexer->args[*i] == '$')
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
	int i;

	i = 0;
	while (lexer->args[i] != '\0')
	{
		if (lexer->args[i] == QUOTES)
			compute_double_quote(lexer, &i);
		else
			i++;
	}
	lexer->format = DEFAULT;
}
