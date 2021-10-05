/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_line_gestion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:24:18 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/05 17:25:16 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	line ::== cmd | line
//		 ::== cmd
//
//	cmd	 ::== exec >> io
//		 ::== exec << io
//		 ::== exec < io
//		 ::== exec > io
//		 ::== exec
//
//	io	 ::== file >> file
//       ::== file > file
//       ::== file
//       add file << file case ??
//
//	exec ::== execname + args	args ::== arg + args
//		 ::== execname				 ::== arg

// static void	wait_childs(pid_t *pid, int nb_cmd)
// {
// 	int	i;

// 	i = 0;
// 	while (i < nb_cmd)
// 	{
// 		waitpid(pid[i], &g_exit_code, 0);
// 		i++;
// 	}
// }

void	cmd_gestion(t_lexer *lexer, char ***env)
{
	t_list2 *cmd_list;
	// pid_t	*pid;

	// pid = NULL;
	if (lexer == NULL || lexer->error == true)
		return ;
	// if (lexer->fork = true)
	// {
	// 	pid = (pid_t *)malloc(sizeof(pid_t) * lexer->nb_cmd);
	// 	if (pid == NULL)
	// 		minishell_error("too many commands");
	// }
	lexer = set_first_lexer(lexer);
	cmd_list = malloc_list2(5);
	cmd_handler(lexer, cmd_list, env);

	//cmd_execution();

	// line_ast(lexer, pid, env);
	// wait_childs(pid, lexer->nb_cmd);
	// if (pid != NULL)
	// 	free(pid);
	free_list2(cmd_list, destroy_cmd);
}
