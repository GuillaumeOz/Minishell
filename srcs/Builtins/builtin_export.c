/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:43:51 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/05 15:42:10 by chdespon         ###   ########.fr       */
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
	int		i;
	int		j;
	t_bool	find_equal;

	i = 0;
	while (env[i] != NULL)
	{
		find_equal = false;
		ft_putstr("declare -x ");
		j = 0;
		while (env[i][j])
		{
			ft_putchar(env[i][j]);
			if (env[i][j] == '=')
			{
				ft_putchar('"');
				find_equal = true;
			}
			j++;
		}
		if (find_equal == true)
			ft_putchar('"');
		ft_putchar('\n');
		i++;
	}
}

int	export_without_argument(char **env)
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

int	set_env(char *name, char *value, char ***env)
{
	char	*variable;
	int		env_index;

	if (name == NULL || name[0] == '=' || ft_is_digit(name[0]) == true)
	{
		printf("minishell: unset: « %s » : identifiant non valable\n", name);
		return (EXIT_FAILURE);
	}
	env_index = find_var_env(*env, name);
	if (env_index >= 0)
	{
		if (value != NULL)
		{
			free((*env)[env_index]);
			(*env)[env_index] = ft_strjoin(ft_strjoin(name, "="), value);
		}
		return (EXIT_SUCCESS);
	}
	if (value == NULL)
		variable = ft_strdup(name);
	else
		variable = ft_strjoin(name, value);
	ft_add_to_tab((void *)variable, (void ***)env);
	return (EXIT_SUCCESS);
}
