/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_executer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:56:38 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/11 18:39:23 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_executer(t_cmd *cmd)
{
	if (cmd->pos == FIRST_POSITION)
		run_fisrt_cmd(cmd);
	// else if (cmd->pos == LAST_POSITION)
	// 	run_last_cmd();
	// else
	// 	run_middle_cmd();


}
