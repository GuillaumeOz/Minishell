/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_executer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:56:38 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/28 15:28:59 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_executer(t_cmd *cmd, t_list2 *cmd_list, t_lexer *lexer)
{
	if (lexer->nb_cmd == 1)
		run_single_cmd(cmd, cmd_list,lexer);
	else
		run_multiple_cmd(cmd, cmd_list, lexer);
}
