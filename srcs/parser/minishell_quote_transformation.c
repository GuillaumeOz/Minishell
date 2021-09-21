/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_quote_transformation.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:03:19 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/21 17:30:30 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quote_dollar_transformation(t_lexer *lexer)
{
	while (lexer != NULL)
	{
		if (lexer->format == MIX_QUOTE)
			mix_quote_transformation(lexer);
		else if (lexer->format == DOUBLE_QUOTE)
			double_quote_transformation(lexer);
		else if (lexer->format == SIMPLE_QUOTE)
			simple_quote_transformation(lexer);
		else if (lexer->format == DEFAULT
			&& lexer->type == ARGS
			&& previous_is_double_lower(lexer) == false)
			dollar_transformation(lexer);
		lexer = lexer->next;
	}
}
