/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_syntax_checker.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:14:42 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/24 22:23:22 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntax_checker(t_lexer *lexer)
{
	t_lexer	*tmp;

	tmp = lexer;
	while (tmp != NULL && lexer->error == false)
	{
		if (tmp->type == PIPE && pipe_error_handler(tmp) == true)
			set_lexer_error(lexer);
		else if (tmp->type == LOWER && lower_error_handler(tmp) == true)
			set_lexer_error(lexer);
		else if (tmp->type == GREATER && greater_error_handler(tmp) == true)
			set_lexer_error(lexer);
		else if (tmp->type == DOUBLE_LOWER
			&& double_lower_error_handler(tmp) == true)
			set_lexer_error(lexer);
		else if (tmp->type == DOUBLE_GREATER
			&& double_greater_error_handler(tmp) == true)
			set_lexer_error(lexer);
		else if (tmp->type == ARGS
			&& args_error_handler(tmp) == true)
			set_lexer_error(lexer);
		tmp = tmp->next;
	}
}
