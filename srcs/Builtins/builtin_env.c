/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:18:47 by chdespon          #+#    #+#             */
/*   Updated: 2021/09/10 17:40:43 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_env(const char *name, const char *value, char ***env)
{
	char	*variable;

	if (name == NULL)
		return (-1);
	if (value == NULL)
		variable = ft_strdup((char *)name);
	else
		variable = ft_strjoin((char *)name, (char *)value);
	ft_add_to_tab((void *)variable, (void ***)env);
	return (0);
}

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

void	unset_env(char *name, char ***env)
{
	int		env_index;
	char	**tmp;
	int		i;
	int		j;

	tmp = *env;
	env_index = find_var_env(tmp, name);
	printf("%d\n", env_index);
	if (env_index == -1)
		return ;
	*env = (char **)ft_tab_new(ft_tab_len((void **)tmp));
	i = 0;
	j = 0;
	while (tmp[i])
	{
		if (i != env_index)
		{
			(*env)[j] = ft_strdup(tmp[i]);
			j++;
		}
		i++;
	}
	// ft_free_tab((void **)tmp);
}

void	print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		ft_putstr(env[i]);
		ft_putchar('\n');
		i++;
	}
}
