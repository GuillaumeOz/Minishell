/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:56:18 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/27 18:43:47 by gozsertt         ###   ########.fr       */
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
	t_lexer *limiter, char *token)
{
	if (g_exit_code == 130)
	{
		set_lexer_limiter_error(lexer, NULL);
		return ;
	}
	set_lexer_limiter_error(lexer, limiter);
	ft_putstr_fd(2, "minishell: ");
	ft_putstr_fd(2, token);
	if (errno == 2)
		ft_putstr_fd(2, ": no such file or directory");
	else if (errno == 13)
		ft_putstr_fd(2, ": permission denied");
	ft_putstr_fd(2, "\n");
	g_exit_code = 1;
}

void	minishell_greater_fd_error(t_lexer *lexer,
	t_lexer *limiter, char *token)
{
	set_lexer_limiter_error(lexer, limiter);
	ft_putstr_fd(2, "minishell: file descriptor error at file opening ");
	ft_putstr_fd(2, "`");
	ft_putstr_fd(2, token);
	ft_putstr_fd(2, "'");
	ft_putstr_fd(2, "\n");
	g_exit_code = 1;
}

void	minishell_command_error(t_cmd *cmd, char *token)
{
	cmd->error = true;
	ft_putstr_fd(2, "minishell: ");
	ft_putstr_fd(2, token);
	ft_putstr_fd(2, ": command not found");
	ft_putstr_fd(2, "\n");
	g_exit_code = 127;
}
