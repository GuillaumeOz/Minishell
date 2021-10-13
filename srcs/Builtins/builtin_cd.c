/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:47:23 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/13 17:57:42 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handling_case_minus(char ***env)
{
	if (find_var_env(*env, "OLDPWD") == -1)
	{
		ft_putstr("minishell: cd: « OLDPWD » not set\n");
		return (EXIT_FAILURE);
	}
	if (chdir((*env)[find_var_env(*env, "OLDPWD")] + 7) != 0)
		return (EXIT_FAILURE);
	change_pwd(env);
	return (EXIT_SUCCESS);
}

static int	handling_case_tilde(char ***env)
{
	if (find_var_env(*env, "HOME") == -1)
	{
		if (chdir(getenv("HOME")) != 0)
			return (EXIT_FAILURE);
	}
	else if (chdir((*env)[find_var_env(*env, "HOME")] + 5) != 0)
	{
		printf("cd: %s: No such file or directory\n",
			(*env)[find_var_env(*env, "HOME")] + 5);
		return (EXIT_FAILURE);
	}
	change_pwd(env);
	return (EXIT_SUCCESS);
}

static int	handling_case_minuses(char ***env)
{
	if (find_var_env(*env, "HOME") == -1)
	{
		ft_putstr("minishell: cd: « HOME » not set\n");
		return (EXIT_FAILURE);
	}
	if (chdir((*env)[find_var_env(*env, "HOME")] + 5) != 0)
	{
		printf("cd: %s: No such file or directory\n",
			(*env)[find_var_env(*env, "HOME")] + 5);
		return (EXIT_FAILURE);
	}
	change_pwd(env);
	return (EXIT_SUCCESS);
}

static void	set_pwd(char ***env)
{
	char	*pwd;

	pwd = get_pwd();
	set_env("PWD", pwd, env);
	free(pwd);
}

int	builtin_cd(char ***env, char **args)
{
	if (find_var_env(*env, "PWD") == -1)
		set_pwd(env);
	if (args[1] == NULL || ft_strcmp(args[1], "--") == 0)
		return (handling_case_minuses(env));
	if (ft_strcmp(args[1], "~") == 0)
		return (handling_case_tilde(env));
	if (ft_strcmp(args[1], "-") == 0)
		return (handling_case_minus(env));
	if (args[2] != NULL)
	{
		ft_putstr("cd: too many arguments\n");
		return (EXIT_FAILURE);
	}
	else if (chdir(args[1]) != 0)
	{
		printf("cd: %s: No such file or directory\n", args[1]);
		return (EXIT_FAILURE);
	}
	change_pwd(env);
	return (EXIT_SUCCESS);
}
