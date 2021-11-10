/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:56:23 by gozsertt          #+#    #+#             */
/*   Updated: 2021/11/02 18:24:45 by gozsertt         ###   ########.fr       */
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
	if (g_exit_code & SIG_HEREDOC_FATHER_INT)
		return ;
	if (g_exit_code & SIG_QUIT)
	{
		ft_putchar('\n');
		g_exit_code |= 130;
		return ;
	}
	if (sig == SIGINT)
	{
		ft_putchar('\n');
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_code |= 130;
	}
}

void	handle_sigquit(int sig)
{
	if (sig == SIGQUIT)
	{
		if (g_exit_code & SIG_QUIT)
		{
			ft_putstr_fd(2, "Quit (core dumped)\n");
			g_exit_code ^= SIG_QUIT;
			g_exit_code |= 131;
		}
		else if (g_exit_code ^ SIG_HEREDOC_FATHER_INT)
			ft_putstr_fd(2, "\b\b  \b\b");
	}
}
