/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_here_doc_dollar_transformation.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:40:31 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/21 16:45:34 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	here_doc_is_dollar_limit(char *new_line, int *i, int j)
{
	if (ft_is_whitespaces(new_line[(*i) + j + 1]) == false
		&& new_line[(*i) + j + 1] != QUOTES
		&& new_line[(*i) + j + 1] != QUOTE
		&& new_line[(*i) + j + 1] != DOLLAR
		&& new_line[(*i) + j + 1] != '\0')
		return (false);
	else
		return (true);
}

static void	here_doc_compute_dollar_question_mark(char *new_line, int *i)
{
	char	*before;
	char	*exit_code;
	char	*after;

	before = ft_strndup(new_line, (*i));
	exit_code = ft_itoa(g_exit_code);
	after = ft_strdup(new_line + (*i) + 1 + 1);
	free(new_line);
	new_line = ft_strappend(before, exit_code, true, true);
	new_line = ft_strappend(new_line, after, true, true);
}

static char	*here_doc_get_key_env(t_cmd *cmd, char *key)
{
	char	**env;
	char	*value;
	int		index;

	value = NULL;
	env = (*cmd->env);
	index = find_var_env(env, key);
	if (index == -1)
		return (value);
	value = ft_strdup(env[index] + ft_strlen(key) + 1);
	return (value);
}

static void	here_doc_compute_dollar(t_cmd *cmd, char **new_line, int *i)
{
	char	*before;
	char	*key;
	char	*after;
	char	*converted_env;
	int		j;

	j = 0;
	converted_env = NULL;
	if ((*new_line)[(*i) + 1] == '?')
		return (here_doc_compute_dollar_question_mark((*new_line), i));
	before = ft_strndup((*new_line), (*i));
	while (here_doc_is_dollar_limit((*new_line), i, j) == false)
		j++;
	key = ft_strndup((*new_line) + (*i) + 1, j);
	converted_env = here_doc_get_key_env(cmd, key);
	free(key);
	after = ft_strdup((*new_line) + (*i) + 1 + j);
	free((*new_line));
	if (converted_env != NULL)
	{
		converted_env = ft_strappend(before, converted_env, true, true);
		(*new_line) = ft_strappend(converted_env, after, true, true);
	}
	else
		(*new_line) = ft_strappend(before, after, true, true);
}

void	here_doc_dollar_transformation(t_cmd *cmd, char **line)
{
	int		i;

	i = 0;
	while ((*line)[i] != '\0')
	{
		if ((*line)[i] == DOLLAR)
			here_doc_compute_dollar(cmd, line, &i);
		else
			i++;
	}
}
