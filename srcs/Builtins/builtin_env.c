/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:18:47 by chdespon          #+#    #+#             */
/*   Updated: 2021/09/23 15:53:26 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_var_env(char **env, char *find)
{
	int		i;
	char	*to_find;

	to_find = ft_strdup(find);
	ft_str_add_suffix(&to_find, "=");
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
		ft_putstr(env[i]);
		ft_putchar('\n');
		i++;
	}
	return (EXIT_SUCCESS);
}
