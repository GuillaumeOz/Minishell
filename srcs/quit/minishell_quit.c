/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_quit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 00:26:04 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/20 14:49:21 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quit(char **env, t_bool print_exit, t_lexer *lexer)
{
	if (print_exit == true)
		ft_putstr("exit\n");
	if (env != NULL)
		ft_free_tab((void **)env);
	clear_history();
	free_lexer(lexer);
	exit(g_exit_code);
}

void	quit_execve(t_cmd *cmd, t_lexer *lexer)
{
	char	*error_msg;

	free_cmd((void *)cmd);
	free_lexer(lexer);
	ft_putstr_fd(2, "Minishell: ");
	error_msg = strerror(errno);
	ft_putstr_fd(2, error_msg);
	ft_putstr_fd(2, "\n");
	g_exit_code = errno;
	exit(g_exit_code);
}

void	quit_builtin(t_cmd *cmd, t_lexer *lexer)
{
	free_cmd((void *)cmd);
	free_lexer(lexer);
	exit(g_exit_code);	
}

