/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_is_case.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:38:10 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/13 15:15:48 by gozsertt         ###   ########.fr       */
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
	if (ft_strcmp(cmd->cmd, "echo") == 0
		|| ft_strcmp(cmd->cmd, "cd") == 0
		|| ft_strcmp(cmd->cmd, "pwd") == 0
		|| ft_strcmp(cmd->cmd, "export") == 0
		|| ft_strcmp(cmd->cmd, "unset") == 0
		|| ft_strcmp(cmd->cmd, "env") == 0
		|| ft_strcmp(cmd->cmd, "exit") == 0)
		return (true);
	else
		return (false);
}

t_bool	is_here_doc_case(t_cmd *cmd)
{
	if (cmd->here_doc == true)
		return (true);
	else
		return (false);
}
