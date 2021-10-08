/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:47:23 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/08 13:00:02 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_cd(char ***env, char **splited_line)
{
	char	*pwd;

	if (find_var_env(*env, "PWD") == -1)
	{
		pwd = get_pwd();
		set_env("PWD", pwd, env);
		free(pwd);
	}
	if (splited_line[1] == NULL)
	{
		if (find_var_env(*env, "HOME") == -1)
		{
			ft_putstr("minishell: cd: HOME not set\n");
			return (EXIT_FAILURE);
		}
		if (chdir((*env)[find_var_env(*env, "HOME")] + 5) != 0)
			return (EXIT_FAILURE);
		change_pwd(env);
		return (EXIT_SUCCESS);
	}
	if (splited_line[2] != NULL)
	{
		ft_putstr("cd: trop d'arguments\n");
		return (EXIT_FAILURE);
	}
	else if (chdir(splited_line[1]) != 0)
	{
		printf("cd: %s: Aucun fichier ou dossier de ce type\n",
			splited_line[1]);
		return (EXIT_FAILURE);
	}
	change_pwd(env);
	return (EXIT_SUCCESS);
}
