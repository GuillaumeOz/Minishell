/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork_setter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:24:02 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/05 14:28:40 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_lexer_fork(t_lexer *lexer)
{
	while (lexer != NULL)
	{
		lexer->fork = false;
		lexer = lexer->next;
	}
}

void	fork_setter(t_lexer *lexer)
{
	t_lexer *tmp;

	tmp = lexer;
	while (tmp != NULL)
	{
		if (tmp->type == PIPE)
			return ;
		tmp = tmp->next;
	}
	tmp = lexer;
	while (tmp != NULL)
	{
		if (tmp->type == ARGS)
			if (ft_strcmp("export", tmp->args) == 0)
			{
				set_lexer_fork(lexer);
				return ;
			}
		tmp = tmp->next;
	}
}
