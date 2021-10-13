/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:16:54 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/12 17:44:43 by gozsertt         ###   ########.fr       */
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
			g_exit_code = ft_atoi(line[0]);
			quit(env, true);
		}
		else
		{
			g_exit_code = 1;
			ft_putstr("exit\nminishell : exit: trop d'arguments\n");
		}
	}
	else
	{
		printf("exit\nminishell: exit: %s : argument numerique necessaire\n",
			line[0]);
		g_exit_code = 2;
		quit(env, false);
	}
}
