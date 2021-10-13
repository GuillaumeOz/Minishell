/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_t_lexer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:00:05 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/13 18:00:05 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*malloc_lexer(t_token_type type, t_token_format format)
{
	t_lexer *lexer;

	lexer = (t_lexer *)malloc(sizeof(t_lexer));
	if (lexer == NULL)
		minishell_error("t_lexer can't be allocate");
	*lexer = create_lexer(type, format);
	return (lexer);
}

t_lexer	create_lexer(t_token_type type, t_token_format format)
{
	t_lexer lexer;

	lexer.type = type;
	lexer.format = format;
	lexer.fork = true;
	lexer.error = false;
	lexer.nb_cmd = 0;
	lexer.args = NULL;
	lexer.over = false;
	lexer.previous = NULL;
	lexer.next = NULL;
	return (lexer);
}

void	destroy_lexer(t_lexer to_destroy)
{
	(void)to_destroy;//check leaks later
	// if (to_destroy.args != NULL)
	// 	free(to_destroy.args);
}

void	free_lexer(t_lexer *to_free)
{
	t_lexer *tmp;

	if (to_free == NULL)
		return ;
	while (to_free->previous != NULL)
		to_free = to_free->previous;
	while (to_free != NULL)
	{
		tmp = to_free->next;
		destroy_lexer(*to_free);
		free(to_free);
		to_free = tmp;
	}
}

t_lexer	*init_lexer(t_lexer *lexer, t_token_type type, t_token_format format)
{
	t_lexer *new_lexer;

	if (lexer == NULL)
		new_lexer = malloc_lexer(type, format);
	else
	{
		new_lexer = malloc_lexer(type, format);
		new_lexer->previous = lexer;
		lexer->next = new_lexer;
	}
	return (new_lexer);
}
