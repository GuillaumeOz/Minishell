/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_quit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 00:26:04 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/13 19:54:50 by gozsertt         ###   ########.fr       */
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
