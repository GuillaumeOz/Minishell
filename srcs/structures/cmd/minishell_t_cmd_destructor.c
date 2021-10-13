/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_t_cmd_destructor.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 20:57:36 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/13 11:51:43 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_fd_list_cmd(void *to_destroy)
{
	int *fd;

	fd = (int *)(to_destroy);
	if (*fd != 0 && *fd != 1)
		close(*fd);
	free(to_destroy);
}

	// t_cmd_postion		pos;
	// char				***env;
	// t_list2				*in_fd;
	// t_list2				*out_fd;
	// int					cmd_stdin;
	// int					cmd_stdout;
	// int					*pipe;
	// t_bool				here_doc;
	// int					*here_doc_pipe;
	// char				**limiter;
	// char				*cmd;
	// char				**args;
	// t_bool				error;

void	destroy_cmd(t_cmd cmd)
{
	// PRINTD(*((int*)list2_at(cmd.in_fd, 0)))
	// PRINTD(*((int*)list2_at(cmd.out_fd, 0)))
	// exit(0);
	if (cmd.in_fd != NULL)
		free_list2(cmd.in_fd, destroy_fd_list_cmd);// case when there are no in out fd
	if (cmd.out_fd != NULL)
		free_list2(cmd.out_fd, destroy_fd_list_cmd);
	if (cmd.pipe != NULL)
		free(cmd.pipe);
	if (cmd.cmd != NULL)
		free(cmd.cmd);
	// if (cmd.args != NULL)
	// 	ft_free_tab((void **)cmd.args);
}

void	free_cmd(void *p_cmd)
{
	t_cmd *cmd;

	cmd = (t_cmd *)p_cmd;
	destroy_cmd(*cmd);
	free(cmd);
}
