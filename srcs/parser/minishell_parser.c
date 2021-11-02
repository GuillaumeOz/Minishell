/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:12:29 by gozsertt          #+#    #+#             */
/*   Updated: 2021/11/02 10:52:42 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(t_lexer *lexer)
{
	if (lexer == NULL)
		return ;
	lexer = set_first_lexer(lexer);
	syntax_checker(lexer);
	if (lexer->error == false)
	{
		quote_dollar_transformation(lexer);
		fork_setter(lexer);
		cmd_number_setter(lexer);
	}
}
