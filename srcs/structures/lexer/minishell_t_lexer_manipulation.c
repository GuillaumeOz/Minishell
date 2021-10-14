/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_t_lexer_manipulation.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:00:32 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/14 14:29:18 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*set_first_lexer(t_lexer *lexer)
{
	while (lexer->previous != NULL)
		lexer = lexer->previous;
	return (lexer);
}
