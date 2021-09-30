/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:43:51 by chdespon          #+#    #+#             */
/*   Updated: 2021/09/27 17:15:33 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_swap(char **x, char **y)
{
	char	*tmp;

	tmp = NULL;
	if (x == NULL || y == NULL)
		return ;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

static void	print_env_ascii(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		ft_putstr("declare -x ");
		ft_putstr(env[i]);
		ft_putchar('\n');
		i++;
	}
}

int	export_whiout_argument(char **env)
{
	int		i;
	int		j;
	char	**tmp;

	if (env == NULL)
		return (-1);
	tmp = alloc_env(env);
	i = 0;
	while (tmp[i + 1] != NULL)
	{
		j = i + 1;
		while (tmp[j] != NULL)
		{
			if (ft_strcmp(tmp[i], tmp[j]) > 0)
				ft_swap(&tmp[i], &tmp[j]);
			j++;
		}
		i++;
	}
	print_env_ascii(tmp);
	ft_free_tab((void **)tmp);
	return (EXIT_SUCCESS);
}

int	set_env(const char *name, const char *value, char ***env)
{
	char	*variable;

	if (name == NULL)
		return (-1);
	if (find_var_env(*env, (char *)name) >= 0)
	{
		if (value != NULL)
		{
			free(*env[find_var_env(*env, (char *)name)]);
			*env[find_var_env(*env, (char *)name)] = ft_strjoin((char *)name,
				(char *)value);
		}
		return (EXIT_SUCCESS);
	}
	if (value == NULL)
		variable = ft_strdup((char *)name);
	else
		variable = ft_strjoin((char *)name, (char *)value);
	ft_add_to_tab((void *)variable, (void ***)env);
	return (EXIT_SUCCESS);
}
