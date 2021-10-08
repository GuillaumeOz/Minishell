/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env_allocation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:17:27 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/27 12:49:06 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**alloc_env(char **env)
{
	char	**dest;
	int		i;

	if (env[0] == NULL)
		return (NULL);
	dest = (char **)ft_tab_new(ft_tab_len((void **)env));
	i = 0;
	while (env[i])
	{
		dest[i] = ft_strdup(env[i]);
		i++;
	}
	return (dest);
}
