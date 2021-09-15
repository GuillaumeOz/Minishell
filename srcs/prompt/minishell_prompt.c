/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:02:51 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/16 00:01:33 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(char **env)
{
	t_lexer	*lexer;
	char	*line;

	(void)env;
	while (1)
	{
		line = readline(_BLUE"("_RED"Minishell" _BLUE") "_GREEN"➜"_WHITE" ");
		if (line != NULL && ft_strcmp(line, "\n") > 0
			&& ft_str_is_only_whitespaces(line) == 0)
		{
			lexer = tokenizer(line);
			add_history(line);
		}
		if (line == NULL)
			break ;
		free(line);
	}
	free(line);
}
