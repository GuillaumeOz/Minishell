/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_wait_childs.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:20:52 by gozsertt          #+#    #+#             */
/*   Updated: 2021/11/02 10:57:08 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_maker_remover(void)
{
	if (g_exit_code & SIG_HEREDOC_INT)
		g_exit_code ^= SIG_HEREDOC_INT;
	if (g_exit_code & SIG_INT)
		g_exit_code ^= SIG_INT;
}

static t_bool is_signal_edge_case(void)//it is usefull
{
	if (g_exit_code & SIG_HEREDOC_INT)
	{
		g_exit_code ^= SIG_HEREDOC_INT;
		return (true);
	}
	if (g_exit_code & SIG_INT)
	{
		g_exit_code ^= SIG_INT;
		return (true);
	}
	if (g_exit_code & SIG_CMDNOTFOUND)
	{
		g_exit_code ^= SIG_CMDNOTFOUND;
		return (true);
	}
	return (false);
}

static void	handle_casual_status(int status)
{
	if (WIFEXITED(status) == true)
		g_exit_code = WEXITSTATUS(status);
	if (g_exit_code == 13)
		g_exit_code = 126;
	else if (WIFSIGNALED(status) == true)
		g_exit_code = WTERMSIG(status);
}

void	wait_childs(pid_t *pid, int nb_cmd)
{
	int			status;
	int			i;

	i = 0;
	status = 0;
	signal_maker_remover();
	while (i < nb_cmd)
	{
		waitpid(pid[i], &status, 0);
		if (is_signal_edge_case() == false)// we need this ?
			handle_casual_status(status);
		if (g_exit_code & SIG_CMDNOTFOUND)
			g_exit_code ^= SIG_CMDNOTFOUND;
		// < a cases
		i++;
	}
}
