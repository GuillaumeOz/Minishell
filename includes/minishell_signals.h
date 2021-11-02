/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signals.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:54:35 by gozsertt          #+#    #+#             */
/*   Updated: 2021/11/02 14:42:43 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_SIGNALS_H
# define MINISHELL_SIGNALS_H

# define ONELEFTMASK 2147483648

enum	e_minishell_signal
{
	NO_SIGNAL = 0,
	SIG_HEREDOC_CHILD_INT = (ONELEFTMASK >> 0),
	SIG_HEREDOC_FATHER_INT = (ONELEFTMASK >> 1),
	SIG_HEREDOC_INT = (ONELEFTMASK >> 4),
	SIG_INT = (ONELEFTMASK >> 5),
	SIG_QUIT = (ONELEFTMASK >> 6),
	SIG_CMDNOTFOUND = (ONELEFTMASK >> 7),
};

void	signal_maker_remover(void);
void	handle_sigint(int sig);
void	handle_sigquit(int sig);

#endif