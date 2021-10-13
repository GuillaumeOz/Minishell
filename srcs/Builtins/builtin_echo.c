/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:16:42 by chdespon          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/10/13 14:26:01 by gozsertt         ###   ########.fr       */
=======
/*   Updated: 2021/10/13 11:10:03 by chdespon         ###   ########.fr       */
>>>>>>> e1a883084f303a51426be2bf7b4fec914f5d406e
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_echo(char **args, t_bool n_flag, char ***env)
{
	int	i;

	i = 1 + n_flag;
	if (ft_strcmp(args[i], "$?") == 0)
	{
		ft_putnbr(g_exit_code);
		ft_putchar('\n');
		return (EXIT_SUCCESS);
	}
	if (ft_strcmp(args[i], "~") == 0)
	{
		if (find_var_env(*env, "HOME") == -1)
			ft_putstr(getenv("HOME"));
		else
			ft_putstr((*env)[find_var_env(*env, "HOME")] + 5);
		if (n_flag == false)
			ft_putchar('\n');
		return (EXIT_SUCCESS);
	}
	while (args[i] != NULL)
	{
		if (i > 1 + (int)n_flag)
			ft_putchar(' ');
		ft_putstr(args[i]);
		i++;
	}
	if (n_flag == false)
		ft_putchar('\n');
	return (EXIT_SUCCESS);
}
