/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_line_is_case.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 02:03:30 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/03 17:42:56 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool is_cmd_pipe_case(t_lexer *lexer, t_lexer **reader)
{
	while (lexer != NULL)
	{
		if (lexer->type == PIPE)
		{
			(*reader) = lexer->next;
			return (true);
		}
		lexer = lexer->next;
	}
	return (false);
}
