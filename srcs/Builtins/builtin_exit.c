/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:16:54 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/14 11:53:40 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_only_digit(char **env, char **args, t_cmd *cmd, t_lexer *lexer)
{
	if (args[1] == NULL)
	{
		free_cmd(cmd);
		g_exit_code = ft_atoi(args[0]);
		quit(env, true, lexer);
	}
	else
	{
		g_exit_code = 1;
		ft_putstr_fd(2, "exit\nminishell : exit: too many arguments\n");
	}
}

void	builtin_exit(char **args, char **env, t_lexer *lexer, t_cmd *cmd)
{
	if (args[0] == NULL)
	{
		free_cmd(cmd);
		quit(env, true, lexer);
	}
	if (ft_str_is_only_digit(args[0]) == true)
		exit_only_digit(env, args, cmd, lexer);
	else
	{
		printf("exit\nminishell: exit: %s : numeric argument required\n",
			args[0]);
		g_exit_code = 2;
		free_cmd(cmd);
		quit(env, false, lexer);
	}
}
