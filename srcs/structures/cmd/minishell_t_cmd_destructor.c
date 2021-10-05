/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_t_cmd_destructor.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 20:57:36 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/05 17:17:01 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_fd_list_cmd(void *to_destroy)
{
	// int *fd;

	// fd = (int *)(to_destroy);
	close((int)to_destroy);
	free(to_destroy);
}

void	destroy_cmd(t_cmd cmd)
{
	free_list2(cmd.in_fd, destroy_fd_list_cmd);// case when there are no in out fd
	free_list2(cmd.out_fd, destroy_fd_list_cmd);
	if (cmd.pipe != NULL)
		free(cmd.pipe);
	if (cmd.cmd != NULL)
		free(cmd.cmd);
	if (cmd.args != NULL)
		ft_free_tab((void **)cmd.args);
}

void	free_cmd(t_cmd *cmd)
{
	destroy_cmd(*cmd);
	free(cmd);
}
