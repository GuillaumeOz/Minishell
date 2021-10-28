/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:16:54 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/28 15:31:28 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_only_digit(char **env, char **args,
	t_list2 *cmd_list, t_lexer *lexer)
{
	if (args[1] == NULL)
	{
		g_exit_code = ft_atoi(args[0]);
		free_list2(cmd_list, free_cmd);
		quit(env, true, lexer);
	}
	else
	{
		g_exit_code = 1;
		ft_putstr_fd(2, "exit\nminishell: exit: too many arguments\n");
	}
}

void	builtin_exit(char **args, char **env, t_lexer *lexer, t_list2 *cmd_list)
{
	if (args[0] == NULL)
	{
		free_list2(cmd_list, free_cmd);
		quit(env, true, lexer);
	}
	if (ft_str_is_only_digit(args[0]) == true)
		exit_only_digit(env, args, cmd_list, lexer);
	else
	{
		ft_putstr_fd(2, "exit\nminishell: exit: ");
		ft_putstr_fd(2, args[0]);
		ft_putstr_fd(2, ": numeric argument required\n");
		g_exit_code = 2;
		free_list2(cmd_list, free_cmd);
		quit(env, false, lexer);
	}
}
