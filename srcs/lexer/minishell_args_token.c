/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_args_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 23:10:52 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/16 00:50:38 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void simple_quote_gestion(t_lexer *lexer, char *line, int *i)
{
	int	start;

	start = (*i);
	while (line[(*i)] != QUOTE && line[(*i)] != '\0')
	{
		getenv()
	}
	if ()
}

static void	fill_args(t_lexer *lexer, char *line, int *i)
{
	int	start;

	start = *i;
	while (ft_is_whitespaces(line[*i]) == false && line[*i] != '\0')
	{
		if (line[*i] == QUOTE)
			simple_quote_gestion(lexer, line, i);
		else if (line[*i] == QUOTES)
			double_quote_gestion(lexer, line, i);
		else
		{
			/* code */
			(*i) += 1;
		}
	}
	lexer->args = ft_strndup(line + start, (*i) - start);
}

t_lexer	*args_token(t_lexer *lexer, char *line, int *i)
{
	t_lexer *new_lexer;

	new_lexer = init_lexer(lexer, ARGS, DEFAULT);
	fill_args(new_lexer, line, i);
	return (new_lexer);
}
