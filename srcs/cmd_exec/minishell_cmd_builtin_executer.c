/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_builtin_executer.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:11:03 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/21 20:44:02 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_builtin_executer(t_cmd *cmd, t_lexer *lexer)
{
	if (ft_strcmp(cmd->cmd, "echo") == 0)
		g_exit_code = print_echo(cmd->args, cmd->env);
	else if (ft_strcmp(cmd->cmd, "cd") == 0)
		g_exit_code = builtin_cd(cmd->env, cmd->args);
	else if (ft_strcmp(cmd->cmd, "env") == 0 && cmd->args[1] == NULL)
		g_exit_code = print_env(*(cmd->env));
	else if (ft_strcmp(cmd->cmd, "pwd") == 0 && cmd->args[1] == NULL)
		g_exit_code = print_pwd(cmd->env);
	else if (ft_strcmp(cmd->cmd, "unset") == 0 && cmd->args[1] != NULL)
		g_exit_code = builtin_unset(cmd->args, cmd->env);
	else if (ft_strcmp(cmd->cmd, "export") == 0 && cmd->args[1] != NULL)
		g_exit_code = builtin_export(cmd->args, cmd->env);
	else if (ft_strcmp(cmd->cmd, "export") == 0 && cmd->args[1] == NULL)
		g_exit_code = export_without_argument(*(cmd->env));
	else if (ft_strcmp(cmd->cmd, "exit") == 0)
		builtin_exit(cmd->args + 1, *(cmd->env), lexer, cmd);
}
