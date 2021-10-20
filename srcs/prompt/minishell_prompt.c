/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:02:51 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/20 16:38:28 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(char ***env)
{
	t_lexer	*lexer;
	char	*line;

	while (1)
	{
		line = readline(_GREEN"➜ "_BLUE"("_RED"Minishell" _BLUE") "
			_YELLOW"✗"_WHITE" ");
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
