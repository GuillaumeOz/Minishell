/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:09:58 by chdespon          #+#    #+#             */
/*   Updated: 2021/09/22 17:32:24 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_env(char *name, char ***env)
{
	int		env_index;
	char	**tmp;
	int		i;
	int		j;

	tmp = *env;
	env_index = find_var_env(tmp, name);
	if (env_index == -1)
	{
		printf("minishell: unset: « %s » : identifiant non valable\n", name);
		return (-1);
	}
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
	return (EXIT_SUCCESS);
	ft_free_tab((void **)tmp);
}
