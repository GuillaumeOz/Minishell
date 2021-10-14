/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_mix_quote_transformation.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:09:18 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/14 14:31:57 by chdespon         ###   ########.fr       */
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
		else if (lexer->args[i] == DOLLAR)
			compute_dollar(lexer, &i);
		else
			i++;
	}
	lexer->format = DEFAULT;
}
