/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_quit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 00:26:04 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/20 13:08:01 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_quit(t_lexer *lexer, int exit_code)
{
	free_lexer(lexer);
	exit(exit_code);
}
