/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:02:51 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/26 11:26:11 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*choose_color_of_arrow(char *line)
{
	if (g_exit_code != 0)
		line = readline(_RED"➜ "_BLUE"("_RED"Minishell" _BLUE") "
				_YELLOW"✗"_WHITE" ");
	else
		line = readline(_GREEN"➜ "_BLUE"("_RED"Minishell" _BLUE") "
				_YELLOW"✗"_WHITE" ");
	return (line);
}

void	prompt(char ***env)
{
	t_lexer	*lexer;
	char	*line;

	while (1)
	{
		line = choose_color_of_arrow(line);
		lexer = tokenizer(line, env);
		if (line != NULL && ft_strcmp(line, "\n") > 0
			&& ft_str_is_only_whitespaces(line) == false)
		{
			parser(lexer);
			cmd_gestion(lexer, env);
			add_history(line);
		}
		if (line == NULL)
			break ;
		free(line);
		free_lexer(lexer);
	}
	free(line);
	quit(*env, true, lexer);
}
