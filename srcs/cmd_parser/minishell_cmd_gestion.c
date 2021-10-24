/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_gestion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:24:18 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/24 15:17:44 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cmd_cleaner(pid_t *pid, t_list2 *cmd_list)
{
	if (pid != NULL)
		free(pid);
	free_list2(cmd_list, free_cmd);
}

void	cmd_gestion(t_lexer *lexer, char ***env)
{
	t_list2	*cmd_list;
	pid_t	*pid;

	pid = NULL;
	if (lexer == NULL || lexer->error == true)
		return ;
	if (lexer->fork == true)
	{
		pid = (pid_t *)malloc(sizeof(pid_t) * lexer->nb_cmd);
		if (pid == NULL)
			minishell_error("too many commands");
	}
	lexer = set_first_lexer(lexer);
	cmd_list = malloc_list2(1);
	cmd_handler(lexer, cmd_list, env);
	cmd_pos_setter(lexer, cmd_list);
	cmd_pipe_setter(lexer, cmd_list);
	cmd_execution(lexer, cmd_list, pid);
	cmd_cleaner(pid, cmd_list);
}
