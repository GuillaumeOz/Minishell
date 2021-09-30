/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_abstract_syntax_tree.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:24:18 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/30 19:39:36 by gozsertt         ###   ########.fr       */
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

void	abstract_syntax_tree(t_lexer *lexer, char ***env)
{
	pid_t	*pid;

	if (lexer == NULL || lexer->error == true)
		return ;
	pid = (pid_t *)malloc(sizeof(pid_t) * lexer->nb_cmd);
	if (pid == NULL)
		minishell_error("too many commands");
	lexer = set_first_lexer(lexer);
	line_ast(lexer, pid, env, LINE_OPTION_1);
	wait_childs(pid, lexer->nb_cmd);
}
