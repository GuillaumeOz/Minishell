/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lexer_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:08:30 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/26 13:58:21 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_lexer_error(t_lexer *lexer)
{
	while (lexer->previous != NULL)
		lexer = lexer->previous;
	while (lexer != NULL)
	{
		lexer->error = true;
		lexer = lexer->next;
	}
}

void	minishell_error(char *error_msg)
{
	ft_putstr_fd(2, "Minishell: critical error, ");
	ft_putstr_fd(2, error_msg);
	ft_putstr_fd(2, "\n");
	exit(-1);
}

void	minishell_syntax_error(t_lexer *lexer, char *token)
{
	set_lexer_error(lexer);
	ft_putstr_fd(2, "Minishell: syntax error near unexpected token ");
	ft_putstr_fd(2, "`");
	ft_putstr_fd(2, token);
	ft_putstr_fd(2, "'");
	ft_putstr_fd(2, "\n");
	g_exit_code = 2;
}

void	minishell_multiline_error(t_lexer *lexer, char *token)
{
	set_lexer_error(lexer);
	ft_putstr_fd(2, "Minishell: parsing error, multiline detected with token ");
	ft_putstr_fd(2, "`");
	ft_putstr_fd(2, token);
	ft_putstr_fd(2, "'");
	ft_putstr_fd(2, "\n");
	g_exit_code = -1;
}
