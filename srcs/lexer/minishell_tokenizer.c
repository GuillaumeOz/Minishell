/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tokenizer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:32:24 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/07 16:30:14 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*tokenizer(char *line)
{
	t_lexer *lexer;
	int i;

	i = 0;
	lexer = NULL;
	while (line[i] != '\0')
	{
		if (lexer != NULL && lexer->error == true)
			return (lexer);
		else if (ft_is_whitespaces(line[i]) == true)
			white_space_token(line, &i);
		else if (line[i] == PIPE)
			lexer = pipe_token(lexer, &i);
		else if (line[i] == LOWER)
			lexer = lower_token(lexer, line, &i);
		else if (line[i] == GREATER)
			lexer = greater_token(lexer, line, &i);
		else
			lexer = args_token(lexer, line, &i);
	}
	return (lexer);
}
