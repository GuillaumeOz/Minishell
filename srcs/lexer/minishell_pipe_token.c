/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pipe_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:53:36 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/19 19:47:38 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*pipe_token(t_lexer *lexer, int *i, char ***env)
{
	t_lexer	*new_lexer;

	(*i) += 1;
	new_lexer = init_lexer(lexer, env, PIPE, DEFAULT);
	return (new_lexer);
}
