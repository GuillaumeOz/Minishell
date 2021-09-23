/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork_setter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:24:02 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/22 12:49:16 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_lexer_fork(t_lexer *lexer)
{
	while (lexer != NULL)
	{
		lexer->fork = true;
		lexer = lexer->next;
	}
}

void	fork_setter(t_lexer *lexer)//change the pipe gestion / parse the number of cmds
{
	t_lexer *tmp;

	tmp = lexer;
	while (tmp != NULL)
	{
		if (tmp->type == PIPE)
		{
			set_lexer_fork(lexer);
			return ;
		}
		tmp = tmp->next;
	}
}