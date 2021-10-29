/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:56:23 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/29 20:50:24 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint(int sig)
{
	if (g_exit_code & SIG_HEREDOC_CHILD_INT)
	{
		ft_putchar('\n');
		exit(130);
	}
	if (g_exit_code == SIG_HEREDOC_FATHER_INT)
		return ;
	if (sig == SIGINT)
	{
		ft_putchar('\n');
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_code |= 130;
		// g_exit_code |= SIG_INT; Activate if needed
		// g_exit_code ^= SIG_INT; Same
	}
}

void	handle_sigquit(int sig)
{
	if (sig == SIGQUIT)
	{
		// signal_maker_remover();
		// if (g_exit_code == 0)
		// {
		// 	ft_putstr_fd(2, "Quit (core dumped)\n");
		// 	PRINTD(g_exit_code)
		// 	g_exit_code = 131;
		// }
		// else if (g_exit_code != 0)
		// 	ft_putstr_fd(1, "\b\b  \b\b");redo
		
	}
}
