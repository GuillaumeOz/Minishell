/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:02:51 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/08 17:41:15 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quit(char **env, t_bool print_exit)
{
	if (print_exit == true)
		ft_putstr("exit\n");
	if (env != NULL)
		ft_free_tab((void **)env);
	clear_history();
	exit(return_val);
}

void	prompt(char ***env)
{
	t_lexer	*lexer;
	char	*line;

	while (1)
	{
		line = readline(_BLUE"("_RED"Minishell" _BLUE") "_GREEN"➜"_WHITE" ");
		if (line != NULL && ft_strcmp(line, "\n") > 0
			&& ft_str_is_only_whitespaces(line) == false)
		{
			lexer = tokenizer(line);
			parser(lexer);
			cmd_gestion(lexer, env);
			// lexer = tokenizer(line);
			// parser(lexer);
			// print_token(lexer);
			parse_line(line, env, 0);
			add_history(line);
			free_lexer(lexer);
		}
		if (line == NULL)
			break ;
		free(line);
	}
	free(line);
	quit(*env, true);
}
