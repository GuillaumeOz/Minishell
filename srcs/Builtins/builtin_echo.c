/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:16:42 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/13 14:26:01 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_echo(char **splited_line, t_bool n_flag, char ***env)
{
	int		i;

	i = 1 + n_flag;
	if (ft_strcmp(splited_line[i], "$?") == 0)
	{
		ft_putnbr(g_exit_code);
		ft_putchar('\n');
		return (EXIT_SUCCESS);
	}
	if (ft_strcmp(splited_line[i], "~") == 0)
	{
		if (find_var_env(*env, "HOME") == -1)
			ft_putstr(getenv("HOME"));
		else
			ft_putstr((*env)[find_var_env(*env, "HOME")] + 5);
		if (n_flag == false)
			ft_putchar('\n');
		return (EXIT_SUCCESS);
	}
	while (splited_line[i] != NULL)
	{
		if (i > 1 + (int)n_flag)
			ft_putchar(' ');
		ft_putstr(splited_line[i]);
		i++;
	}
	if (n_flag == false)
		ft_putchar('\n');
	return (EXIT_SUCCESS);
}
