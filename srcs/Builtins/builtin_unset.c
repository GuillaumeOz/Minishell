/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:09:58 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/13 12:34:06 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	realloc_env(char ***env, char **tmp, int env_index)
{
	int	i;
	int	j;

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
}

int	unset_env(char *name, char ***env)
{
	int		env_index;
	char	**tmp;

	if (name == NULL || ft_strstr(name, "=") != NULL || ft_strlen(name) == 0
		|| ft_is_digit(name[0]) == true)
	{
		printf("minishell: unset: « %s » : identifiant non valable\n", name);
		return (EXIT_FAILURE);
	}
	env_index = find_var_env(*env, name);
	if (env_index == -1)
		return (EXIT_SUCCESS);
	tmp = *env;
	*env = (char **)ft_tab_new(ft_tab_len((void **)tmp));
	realloc_env(env, tmp, env_index);
	ft_free_tab((void **)tmp);
	return (EXIT_SUCCESS);
}

int	builtin_unset(char **args, char ***env)
{
	int	i;

	i = 1;
	while (args[i] != NULL)
	{
		if (unset_env(args[i], env) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
