/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_here_doc_utils.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:03:49 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/26 10:45:36 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	limitercmp(char *line, char *limiter, int weight)
{
	char *current_limiter;

	if (weight == 0)
		current_limiter = limiter;
	else
		current_limiter = &(limiter[1]);
	if (ft_strcmp(line, current_limiter) == 0)
		return (true);
	else
		return (false);
}
