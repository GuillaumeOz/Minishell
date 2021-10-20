/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:16:42 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/20 11:53:21 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handling_case_tilde(char ***env, t_bool n_flag)
{
	if (find_var_env(*env, "HOME") == -1)
		ft_putstr(getenv("HOME"));
	else
		ft_putstr((*env)[find_var_env(*env, "HOME")] + 5);
	if (n_flag == false)
		ft_putchar('\n');
	return (EXIT_SUCCESS);
}

static t_bool	check_nflag(char **args)
{
	char	*tmp;
	t_bool	n_flag;

	if (args[1] != NULL && ft_strncmp(args[1], "-n", 2) == 0)
	{
		tmp = ft_rm_charset(args[1], "-n");
		if (tmp[0] == '\0')
			n_flag = true;
		else
			n_flag = false;
		free(tmp);
	}
	else
		n_flag = false;
	return (n_flag);
}

int	print_echo(char **args, char ***env)
{
	int		i;
	t_bool	n_flag;

	n_flag = check_nflag(args);
	i = 1 + n_flag;
	if (args[i] != NULL && ft_strcmp(args[i], "~") == 0)
		return (handling_case_tilde(env, n_flag));
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
