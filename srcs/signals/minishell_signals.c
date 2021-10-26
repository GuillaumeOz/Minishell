/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:56:23 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/26 19:48:40 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint(int sig)
{
	if (g_exit_code == -1)
	{
		ft_putchar('\n');
		exit(130);
	}
	if (g_exit_code == -2)
		return ;
	if (g_exit_code == -3)
	{
		ft_putchar('\n');
		g_exit_code = 130;
	}
	else if (sig == SIGINT)
	{
		ft_putchar('\n');
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_code = 130;
	}
}
