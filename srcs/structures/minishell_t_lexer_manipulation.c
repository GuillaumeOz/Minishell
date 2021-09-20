/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_t_lexer_manipulation.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:00:32 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/16 19:04:46 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer *set_first_lexer(t_lexer *lexer)
{
	while (lexer->previous != NULL)
		lexer = lexer->previous;
	return (lexer);
}
