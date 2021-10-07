/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_line_gestion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:24:18 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/07 17:37:35 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	wait_childs(pid_t *pid, int nb_cmd)
{
	int	i;

	i = 0;
	while (i < nb_cmd)
	{
		waitpid(pid[i], &g_exit_code, 0);
		i++;
	}
}

static void	cmd_cleaner(pid_t *pid, t_list2 *cmd_list)
{
	if (pid != NULL)
		free(pid);
	free_list2(cmd_list, free_cmd);
}

void	cmd_gestion(t_lexer *lexer, char ***env)
{
	t_list2 *cmd_list;
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
	// cmd_execution(cmd_list, );
	wait_childs(pid, lexer->nb_cmd);
	cmd_cleaner(pid, cmd_list);
}
