/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_case.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:26:04 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/07 16:22:55 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void args_gestion(t_cmd *cmd, t_lexer **reader)
{
	if (cmd->args == NULL)
	{
		cmd->args = (char **)ft_tab_new(1);
		ft_add_to_tab((*reader)->args, (void ***)&(cmd->args));
	}
	else
		ft_add_to_tab((*reader)->args, (void ***)&(cmd->args));
}

void	exec_case(t_cmd *cmd,
	t_lexer *lexer, t_lexer *limiter, t_lexer **reader)
{
	if (cmd->cmd == NULL)
		cmd->cmd = ft_strdup((*reader)->args);
	else
		args_gestion(cmd, reader);
	cmd_exec_args_handler(lexer, limiter, cmd);
}
