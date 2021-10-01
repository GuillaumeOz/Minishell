/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:56:18 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/01 21:02:05 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_lexer_fork_error(t_lexer *lexer, t_lexer *limiter)
{
	while (lexer->previous != NULL && lexer->previous != limiter)
		lexer = lexer->previous;
	while (lexer != NULL && lexer != limiter)
	{
		lexer->error = true;
		lexer = lexer->next;
	}
}

void	minishell_fork_lower_fd_error(t_lexer *lexer,
	t_lexer *limiter, char *token)
{
	set_lexer_fork_error(lexer, limiter);
	ft_putstr_fd(2, "Minishell: ");
	ft_putstr_fd(2, token);
	ft_putstr_fd(2, ": No such file or directory");
	ft_putstr_fd(2, "\n");
	g_exit_code = errno;
}

void	minishell_fork_greater_fd_error(t_lexer *lexer,
	t_lexer *limiter, char *token)
{
	set_lexer_fork_error(lexer, limiter);
	ft_putstr_fd(2, "Minishell: file descriptor error at file opening ");
	ft_putstr_fd(2, "`");
	ft_putstr_fd(2, token);
	ft_putstr_fd(2, "'");
	ft_putstr_fd(2, "\n");
	g_exit_code = errno;
}
