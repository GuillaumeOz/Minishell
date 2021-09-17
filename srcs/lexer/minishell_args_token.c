/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_args_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 23:10:52 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/16 14:59:44 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void token_format_setter(t_lexer *lexer, t_token_format format)
{
	if (lexer->format == SIMPLE_QUOTE || lexer->format == DOUBLE_QUOTE)
		lexer->format = MIX_QUOTE;
	else if (lexer->format == DEFAULT)
		lexer->format = format;
}

static void simple_quote_control(t_lexer *lexer, char *line, int *i)
{
	token_format_setter(lexer, SIMPLE_QUOTE);
	(*i) += 1;
	while (line[(*i)] != QUOTE && line[(*i)] != '\0')
		(*i) += 1;
	if (line[(*i)] == '\0')
	{
		minishell_error("unclosed quotes detected");
		minishell_quit(lexer, EXIT_FAILURE);
	}
	(*i) += 1;
}

static void	double_quote_control(t_lexer *lexer, char *line, int *i)
{
	token_format_setter(lexer, DOUBLE_QUOTE);
	(*i) += 1;
	while (line[(*i)] != QUOTES && line[(*i)] != '\0')
		(*i) += 1;
	if (line[(*i)] == '\0')
	{
		minishell_error("unclosed quotes detected");
		minishell_quit(lexer, EXIT_FAILURE);
	}
	(*i) += 1;
}

static void	fill_args(t_lexer *lexer, char *line, int *i)
{
	int	start;

	start = *i;
	while (ft_is_whitespaces(line[*i]) == false && line[*i] != PIPE
		&& line[*i] != LOWER && line[*i] != GREATER && line[*i] != '\0')
	{
		if (line[*i] == QUOTE)
			simple_quote_control(lexer, line, i);
		else if (line[*i] == QUOTES)
			double_quote_control(lexer, line, i);
		else
			(*i) += 1;
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
