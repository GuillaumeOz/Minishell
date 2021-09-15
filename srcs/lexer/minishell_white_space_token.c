/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_white_space_token.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:58:19 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/15 22:15:13 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	white_space_token(char *line, int *i)
{
	while (ft_is_whitespaces(line[*i]) == true)
		(*i) += 1;
}
