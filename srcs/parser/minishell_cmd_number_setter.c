/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_number_setter.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 07:04:12 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/24 07:11:41 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_number_setter(t_lexer *lexer)
{
	t_lexer	*tmp;
	int		count;

	tmp = lexer;
	count = 1;
	while (tmp != NULL)
	{
		if (tmp->type == PIPE)
			count++;
		tmp->next;
	}
	tmp = lexer;
	while (tmp != NULL)
	{
		tmp->nb_cmd = count;
		tmp->next;
	}
}
