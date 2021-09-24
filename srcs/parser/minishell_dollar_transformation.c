/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_dollar_transformation.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:51:13 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/24 01:46:24 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	is_dollar_limit(t_lexer *lexer, int *i, int j)
{
	if (ft_is_whitespaces(lexer->args[(*i) + j + 1]) == false
		&& lexer->args[(*i) + j + 1] != QUOTES
		&& lexer->args[(*i) + j + 1] != QUOTE
		&& lexer->args[(*i) + j + 1] != DOLLAR
		&& lexer->args[(*i) + j + 1] != '\0')
		return (false);
	else
		return (true);
}

static void	compute_dollar_question_mark(t_lexer *lexer, int *i)
{
	char	*before;
	char	*exit_code;
	char	*after;

	before = ft_strndup(lexer->args, (*i));
	exit_code = ft_itoa(g_exit_code);
	after = ft_strdup(lexer->args + (*i) + 1 + 1);
	free(lexer->args);
	lexer->args = ft_strappend(before, exit_code, true, true);
	lexer->args = ft_strappend(lexer->args, after, true, true);
}

void	compute_dollar(t_lexer *lexer, int *i)
{
	char	*before;
	char	*env;
	char	*after;
	char	*converted_env;
	int		j;

	j = 0;
	if (lexer->args[(*i) + 1] == '?')
		return (compute_dollar_question_mark(lexer, i));
	before = ft_strndup(lexer->args, (*i));
	while (is_dollar_limit(lexer, i, j) == false)
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

void	dollar_transformation(t_lexer *lexer)
{
	int i;

	i = 0;
	while (lexer->args[i] != '\0')
	{
		if (lexer->args[i] == DOLLAR)
			compute_dollar(lexer, &i);
		else
			i++;
	}
}
