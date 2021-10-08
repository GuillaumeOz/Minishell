/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork_setter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:24:02 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/08 18:15:55 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_lexer_fork(t_lexer *lexer)
{
	while (lexer != NULL)
	{
		lexer->fork = false;
		lexer = lexer->next;
	}
}

static t_bool	builtin_checker(t_lexer *lexer)
{
	if (ft_strcmp("echo", lexer->args) == 0)
		return (true);
	else if (ft_strcmp("cd", lexer->args) == 0)
		return (true);
	else if (ft_strcmp("pwd", lexer->args) == 0)
		return (true);
	else if (ft_strcmp("export", lexer->args) == 0)
		return (true);
	else if (ft_strcmp("unset", lexer->args) == 0)
		return (true);
	else if (ft_strcmp("env", lexer->args) == 0)
		return (true);
	else if (ft_strcmp("exit", lexer->args) == 0)
		return (true);
	else
		return (false);
}

void	fork_setter(t_lexer *lexer)
{
	t_lexer *tmp;

	tmp = lexer;
	while (tmp != NULL)
	{
		if (tmp->type == PIPE)
			return ;
		tmp = tmp->next;
	}
	tmp = lexer;
	while (tmp != NULL)
	{
		if (tmp->type == ARGS)
			if (builtin_checker(tmp) == true)
			{
				set_lexer_fork(lexer);
				return ;
			}
		tmp = tmp->next;
	}
}
