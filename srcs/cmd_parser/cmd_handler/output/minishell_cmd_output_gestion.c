/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_output_gestion.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:26:31 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/11 17:57:57 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_output_gestion(t_lexer *lexer, t_lexer *limiter, t_cmd *cmd)
{
	t_lexer *reader;

	reader = lexer;
	while (reader != limiter)
	{
		if (lexer->error == true)
			return ;
		if (is_exec_double_greater_io_case(reader) == true)
			exec_double_greater_io_case(cmd, lexer, limiter, reader->next);
		else if (is_exec_greater_io_case(reader) == true)
			exec_greater_io_case(cmd, lexer, limiter, reader->next);
		reader = reader->next;
	}
}
