/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:56:18 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/20 11:46:02 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_lexer_limiter_error(t_lexer *lexer, t_lexer *limiter)
{
	while (lexer != limiter && lexer != NULL)
	{
		lexer->error = true;
		lexer = lexer->next;
	}
}

void	minishell_lower_fd_error(t_lexer *lexer,
	t_lexer *limiter, char *token)//rename ?
{
	set_lexer_limiter_error(lexer, limiter);
	ft_putstr_fd(2, "Minishell: ");
	ft_putstr_fd(2, token);
	// ft_putstr_fd(2, ": Permission denied");//choose handle this case ?
	ft_putstr_fd(2, ": No such file or directory");
	ft_putstr_fd(2, "\n");
	g_exit_code = errno;
}

void	minishell_greater_fd_error(t_lexer *lexer,
	t_lexer *limiter, char *token)//rename ?
{
	set_lexer_limiter_error(lexer, limiter);
	ft_putstr_fd(2, "Minishell: file descriptor error at file opening ");
	ft_putstr_fd(2, "`");
	ft_putstr_fd(2, token);
	ft_putstr_fd(2, "'");
	ft_putstr_fd(2, "\n");
	g_exit_code = errno;
}

void	minishell_command_error(t_cmd *cmd, char *token)//suppr this ?
{
	cmd->error = true;
	ft_putstr_fd(2, "Minishell: ");
	ft_putstr_fd(2, token);
	ft_putstr_fd(2, ": command not found");
	ft_putstr_fd(2, "\n");
	g_exit_code = 127;
}
