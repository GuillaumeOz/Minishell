/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tokenizer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:32:24 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/16 19:05:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

	// t_token_type		type;
	// t_token_format		format;
	// char				*args;
	// struct s_lexer		*previous;
	// struct s_lexer		*next;

void print_token(t_lexer *lexer)
{
	int i;

	i = 1;
	while (lexer->previous != NULL)
		lexer = lexer->previous;
	while (lexer != NULL)
	{
		PRINTS("-------------------------------------------------\n")
		PRINTD(i)
		if (lexer->type == NONE)
			PRINTS("type : [NONE]\n")
		else if (lexer->type == ARGS)
			PRINTS("type : [ARGS]\n")
		else if (lexer->type == SPACE)
			PRINTS("type : [SPACE]\n")
		else if (lexer->type == TAB)
			PRINTS("type : [TAB]\n")
		else if (lexer->type == PIPE)
			PRINTS("type : [PIPE]\n")
		else if (lexer->type == LOWER)
			PRINTS("type : [LOWER]\n")
		else if (lexer->type == GREATER)
			PRINTS("type : [GREATER]\n")
		else if (lexer->type == DOUBLE_LOWER)
			PRINTS("type : [DOUBLE_LOWER]\n")
		else if (lexer->type == DOUBLE_GREATER)
			PRINTS("type : [DOUBLE_GREATER]\n")
		
		if (lexer->format == DEFAULT)
			PRINTS("format : [DEFAULT]\n")
		else if (lexer->format == SIMPLE_QUOTE)
			PRINTS("format : [SIMPLE_QUOTE]\n")
		else if (lexer->format == DOUBLE_QUOTE)
			PRINTS("format : [DOUBLE_QUOTE]\n")
		else if (lexer->format == MIX_QUOTE)
			PRINTS("format : [MIX_QUOTE]\n")
		
		if (lexer->args == NULL)
			PRINTS("args : [NULL]\n")
		else
			printf("args : %s\n", lexer->args);
		i++;
		lexer = lexer->next;
	}
}

t_lexer	*tokenizer(char *line)
{
	t_lexer *lexer;
	int i;

	i = 0;
	lexer = NULL;
	while (line[i] != '\0')
	{
		if (ft_is_whitespaces(line[i]) == true)
			white_space_token(line, &i);
		else if (line[i] == PIPE)//special
			lexer = pipe_token(lexer, &i);
		else if (line[i] == LOWER)
			lexer = lower_token(lexer, line, &i);
		else if (line[i] == GREATER)
			lexer = greater_token(lexer, line, &i);//special
		else
			lexer = args_token(lexer, line, &i);
	}
	return (lexer);
}
