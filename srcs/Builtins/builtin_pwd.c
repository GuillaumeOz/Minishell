/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:15:15 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/21 18:28:19 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_pwd(char ***env)
{
	char	*pwd;

	pwd = get_pwd();
	if (pwd != NULL)
	{
		set_env("OLDPWD", (*env)[find_var_env(*env, "PWD")] + 4, env);
		set_env("PWD", pwd, env);
	}
	free(pwd);
}

char	*get_pwd(void)
{
	char	*buf;

	buf = NULL;
	buf = getcwd(buf, 999999);
	return (buf);
}

int	print_pwd(char ***env)
{
	char	*pwd;

	if (find_var_env(*env, "PWD") == -1)
	{
		pwd = get_pwd();
		ft_str_add_suffix(&pwd, "\n");
		ft_putstr_fd(1, pwd);
		free(pwd);
	}
	ft_putstr_fd(1, (*env)[find_var_env(*env, "PWD")] + 4);
	ft_putchar_fd(1, '\n');
	return (EXIT_SUCCESS);
}
