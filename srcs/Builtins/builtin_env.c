/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:18:47 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/19 18:25:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_line(char **env, char *to_find)
{
	int	i;

	if (env == NULL)
		return (-1);
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(to_find, env[i], ft_strlen(to_find)) == 0)
		{
			free(to_find);
			return (i);
		}
		i++;
	}
	return (-1);
}

int	find_var_env(char **env, char *find)
{
	int		line;
	char	*to_find;

	to_find = ft_strdup(find);
	ft_str_add_suffix(&to_find, "=");
	line = find_line(env, to_find);
	if (line >= 0)
		return (line);
	free(to_find);
	to_find = ft_strdup(find);
	ft_str_add_suffix(&to_find, "\0");
	line = find_line(env, to_find);
	if (line >= 0)
		return (line);
	free(to_find);
	return (-1);
}

int	print_env(char **env)
{
	int	i;

	if (env == NULL)
		return (-1);
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strstr(env[i], "=") != NULL)
		{
			ft_putstr(env[i]);
			ft_putchar('\n');
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
