/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pipe_error_handler.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 22:00:16 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/21 22:09:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	pipe_error_handler(t_lexer *lexer)
{
	if (previous_is_null_checker(lexer) == true)
		return (true);
	else if (next_is_null_checker(lexer) == true)
		return (true);
	else if ()
}
