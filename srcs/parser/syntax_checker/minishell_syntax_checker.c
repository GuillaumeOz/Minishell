/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_syntax_checker.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:14:42 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/21 22:08:07 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_lexer_error(t_lexer *lexer)
{
	while (lexer != NULL)
	{
		lexer->error = true;
		lexer = lexer->next;
	}
}

void	syntax_checker(t_lexer *lexer)
{
	t_lexer *tmp;

	tmp = lexer;
	while (tmp != NULL || tmp->error == false)
	{
		if (tmp->type == PIPE)
			if (pipe_error_handler(tmp) == true);
				set_lexer_error(lexer);
			//pipe error handler
		else if (tmp->type)
			//other error handler
		else if (tmp->type == ARGS)

		tmp = tmp->next;
	}
}
