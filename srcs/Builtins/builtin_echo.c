/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:16:42 by chdespon          #+#    #+#             */
/*   Updated: 2021/09/13 16:16:28 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_echo(char **splited_line, t_bool n_flag)
{
	int		i;
	char	*tmp;

	i = 1 + n_flag;
	while (splited_line[i] != NULL)
	{
		if (i > 1 + (int)n_flag)
			ft_putchar(' ');
		tmp = ft_rm_charset(splited_line[i], "\"\'");
		ft_putstr(tmp);
		free(tmp);
		i++;
	}
	if (n_flag == false)
		ft_putchar('\n');
}
