/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_is_case.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:38:10 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/08 18:16:00 by gozsertt         ###   ########.fr       */
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
	if (cmd->cmd == "echo"
		|| cmd->cmd == "cd"
		|| cmd->cmd == "pwd"
		|| cmd->cmd == "export"
		|| cmd->cmd == "unset"
		|| cmd->cmd == "env"
		|| cmd->cmd == "exit")
		return (true);
	else
		return (false);
}
