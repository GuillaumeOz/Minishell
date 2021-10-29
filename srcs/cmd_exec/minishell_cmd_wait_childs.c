/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_wait_childs.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:20:52 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/29 15:07:42 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_signal_case(int *status, int *intsig)
{
	debug
	debug
	if (WIFEXITED(*status) == true)
		g_exit_code = WEXITSTATUS(*status);
	if (g_exit_code == 13)
		g_exit_code = 126;
	else if (WIFSIGNALED(*status) == true)
		g_exit_code = WTERMSIG(*status);
	if ((*intsig) == 130 && (*status) != 0)
		g_exit_code = 130;
}

static void	signal_edge_case(int *intsig, int *error_nf)
{
	PRINTD(*(error_nf))
	PRINTD(g_exit_code)
	debug
	if (*(error_nf) == 0 && g_exit_code == 127)
		*(error_nf) = 127;
	else if (g_exit_code == 127)
		*(error_nf) = 0;
	if (*(intsig) == 0 && g_exit_code == 130)
		*(intsig) = 130;
	else if (g_exit_code != 130)
		*(intsig) = 0;
	PRINTD(g_exit_code)
	PRINTD(*(error_nf))
}

void	wait_childs(pid_t *pid, int nb_cmd)
{
	static int	intsig = 0;
	static int	error_nf = 0;
	int			status;
	int			i;

	i = 0;
	signal_edge_case(&intsig, &error_nf);
	status = 0;
	while (i < nb_cmd)
	{
		if (g_exit_code != 127)
			g_exit_code = -3;
		waitpid(pid[i], &status, 0);
		if (g_exit_code != 130 && g_exit_code != 131
			&& (g_exit_code == 127 && error_nf == 0))
			handle_signal_case(&status, &intsig);
		i++;
	}
}
