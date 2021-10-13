/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:43:51 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/13 14:54:57 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static int	replace_variable(int env_index, char ***env, char *value, char *tmp)
{
	if (env_index >= 0)
	{
		if (value != NULL)
		{
			free((*env)[env_index]);
			(*env)[env_index] = ft_strjoin(tmp, value);
			free(tmp);
		}
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	set_env(char *name, char *value, char ***env)
{
	char	*variable;
	int		env_index;
	char	*tmp;

	if (name == NULL || ft_strstr(name, "=") != NULL || ft_strlen(name) == 0
		|| ft_is_digit(name[0]) == true)
	{
		printf("minishell: export: « %s » : identifiant non valable\n", name);
		return (EXIT_FAILURE);
	}
	tmp = ft_strjoin(name, "=");
	env_index = find_var_env(*env, name);
	if (replace_variable(env_index, env, value, tmp) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	if (value == NULL)
		variable = ft_strdup(name);
	else
		variable = ft_strjoin(tmp, value);
	free(tmp);
	ft_add_to_tab((void *)variable, (void ***)env);
	return (EXIT_SUCCESS);
}

int	builtin_export(char **args, char ***env)
{
	int		i;
	char	**name;

	i = 1;
	while (args[i] != NULL)
	{
		if (ft_strstr(args[i], "=") == 0)
			g_exit_code = set_env(args[i] , NULL, env);
		else
		{
			name = NULL;
			name = ft_split(args[i], '=');
			g_exit_code = set_env(name[0] , ft_strstr(args[i], "=") + 1, env);
			ft_free_tab((void **)name);
		}
		i++;
	}
	return (g_exit_code);
}
