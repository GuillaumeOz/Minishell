/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pipe_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:53:36 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/14 14:33:06 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*pipe_token(t_lexer *lexer, int *i)
{
	t_lexer	*new_lexer;

	(*i) += 1;
	new_lexer = init_lexer(lexer, PIPE, DEFAULT);
	return (new_lexer);
}
