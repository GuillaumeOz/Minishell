/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:12:29 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/18 18:47:40 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(t_lexer *lexer)
{
	if (lexer == NULL)
		return ;
	lexer = set_first_lexer(lexer);
	quote_transformation(lexer);
	//add some token modification if needed later
}
