/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_output_is_case.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:18:07 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/11 17:55:04 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	is_exec_double_greater_io_case(t_lexer *reader)
{
	if (reader->type == DOUBLE_GREATER && reader->over == false)
	{
		reader->over = true;
		reader->next->over = true;
		return (true);
	}
	return (false);
}

t_bool	is_exec_greater_io_case(t_lexer *reader)
{
	if (reader->type == GREATER && reader->over == false)
	{
		reader->over = true;
		reader->next->over = true;
		return (true);
	}
	return (false);
}
