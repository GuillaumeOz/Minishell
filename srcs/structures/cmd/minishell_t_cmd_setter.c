/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_t_cmd_setter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:22:37 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/11 13:52:11 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_pos_setter(t_lexer *lexer, t_list2 *cmd_list)
{
	t_cmd	*cmd;
	int		i;

	i = 0;
	while (i < lexer->nb_cmd)
	{
		cmd = list2_at(cmd_list, i);
		if (i == 0)
			cmd->pos = FIRST_POSITION;
		else if (i == (lexer->nb_cmd - 1))
			cmd->pos = LAST_POSITION;
		else
			cmd->pos = MIDDLE_POSITION;
		i++;
	}
}

void	cmd_pipe_setter(t_lexer *lexer, t_list2 *cmd_list)
{
	t_cmd	*cmd;
	int		i;

	i = 0;
	while (i < (lexer->nb_cmd - 1))
	{
		cmd = list2_at(cmd_list, i);
		cmd->pipe = (int *)malloc(sizeof(int) * 2);
		if (cmd->pipe == NULL)
			minishell_error("int * can't be allocated");
		i++;
	}
}
