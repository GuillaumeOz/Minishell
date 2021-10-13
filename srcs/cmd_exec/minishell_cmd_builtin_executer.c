/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_builtin_executer.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:11:03 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/13 17:52:19 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_builtin_executer(t_cmd *cmd)
{
	if (ft_strcmp(cmd->cmd, "echo") == 0)
	{
		if (cmd->args[1] != NULL && ft_strcmp(cmd->args[1], "-n") == 0)
			g_exit_code = print_echo(cmd->args, true, cmd->env);
		else
			g_exit_code = print_echo(cmd->args, false, cmd->env);
	}
	else if (ft_strcmp(cmd->cmd, "cd") == 0)
		g_exit_code = builtin_cd(cmd->env, cmd->args);
	else if (ft_strcmp(cmd->cmd, "env") == 0
		&& cmd->args[1] == NULL)
		g_exit_code = print_env(*(cmd->env));
	else if (ft_strcmp(cmd->cmd, "pwd") == 0 && cmd->args[1] == NULL)
		g_exit_code = print_pwd();
	else if (ft_strcmp(cmd->cmd, "unset") == 0
		&& cmd->args[1] != NULL)
		g_exit_code = unset_env(cmd->args[1], cmd->env);
	else if (ft_strcmp(cmd->cmd, "export") == 0
		&& cmd->args[1] != NULL)
		g_exit_code = set_env(cmd->args[1] , NULL, cmd->env);
	else if (ft_strcmp(cmd->cmd, "export") == 0 && cmd->args[1] == NULL)
		g_exit_code = export_without_argument(*(cmd->env));
	else if (ft_strcmp(cmd->cmd, "exit") == 0)
		builtin_exit(cmd->args, *(cmd->env));
}
