/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_mix_quote_transformation.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:09:18 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/21 14:05:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mix_quote_transformation(t_lexer *lexer)
{
	int	i;

	i = 0;
	while (lexer->args[i] != '\0')
	{
		if (lexer->args[i] == QUOTE)
			compute_simple_quote(lexer, &i);
		else if (lexer->args[i] == QUOTES)
			compute_double_quote(lexer, &i);
		else if (lexer->args[i] == DOLLAR
			&& previous_is_double_lower_checker(lexer) == false)
			compute_dollar(lexer, &i);
		else
			i++;
	}
	lexer->here_doc_exp = false;
	lexer->format = DEFAULT;
}
