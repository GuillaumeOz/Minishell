/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:16:54 by chdespon          #+#    #+#             */
/*   Updated: 2021/09/20 12:36:37 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_exit(char **line, char **env)
{
	if (line[0] == NULL)
		quit(env, true);
	if (ft_str_is_only_digit(line[0]) == true)
	{
		if (line[1] == NULL)
		{
			return_val = ft_atoi(line[0]);
			quit(env, true);
		}
		else
		{
			return_val = 1;
			ft_putstr("exit\nminishell : exit: trop d'arguments\n");
		}
	}
	else
	{
		printf("exit\nminishell: exit: %s : argument numerique necessaire\n",
			line[0]);
		return_val = 2;
		quit(env, false);
	}
}
