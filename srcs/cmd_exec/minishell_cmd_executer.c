/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_executer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:56:38 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/12 20:06:42 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_executer(t_cmd *cmd, int nb_cmd)
{
	if (nb_cmd == 1)
		run_single_cmd(cmd);
	// else
	// 	run_multiple_cmd();
}
