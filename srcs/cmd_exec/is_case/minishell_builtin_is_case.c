/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_is_case.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:38:10 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/11 18:03:42 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_cmd_null_case(t_cmd *cmd)
{
	if (cmd->cmd == NULL)
		return (true);
	else
		return (false);
}

t_bool	is_cmd_builtin_case(t_cmd *cmd)
{
	if (ft_strcmp(cmd->cmd, "echo") == true
		|| ft_strcmp(cmd->cmd, "cd") == true
		|| ft_strcmp(cmd->cmd, "pwd") == true
		|| ft_strcmp(cmd->cmd, "export") == true
		|| ft_strcmp(cmd->cmd, "unset") == true
		|| ft_strcmp(cmd->cmd, "env") == true
		|| ft_strcmp(cmd->cmd, "exit") == true)
		return (true);
	else
		return (false);
}
