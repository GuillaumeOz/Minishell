/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_wait_childs.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:20:52 by gozsertt          #+#    #+#             */
/*   Updated: 2021/11/02 14:40:53 by chdespon         ###   ########.fr       */
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

static t_bool	is_signal_edge_case(void)
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
	if (g_exit_code == 131)
		return ;
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
		g_exit_code |= SIG_QUIT;
		waitpid(pid[i], &status, 0);
		if (is_signal_edge_case() == false)
			handle_casual_status(status);
		if (g_exit_code & SIG_CMDNOTFOUND)
			g_exit_code ^= SIG_CMDNOTFOUND;
		i++;
	}
}
