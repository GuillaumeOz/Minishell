/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_double_lower_io_case.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:28:50 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/11 16:22:47 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_double_lower_io_case(t_cmd *cmd, t_lexer *lexer,
	t_lexer *limiter, t_lexer **reader)
{
	cmd->here_doc = true;
	if (cmd->limiter == NULL)
	{
		cmd->limiter = (char **)ft_tab_new(1);
		ft_add_to_tab((*reader)->args, (void ***)&(cmd->limiter));
	}
	else
		ft_add_to_tab((*reader)->args, (void ***)&(cmd->limiter));
	cmd_limiter_handler(lexer, limiter, cmd);
}
