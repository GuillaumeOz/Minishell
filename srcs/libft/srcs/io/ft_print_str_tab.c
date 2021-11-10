/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:11:20 by ldutriez          #+#    #+#             */
/*   Updated: 2020/02/26 10:29:14 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_str_tab(char *p_name, char **p_tab)
{
	size_t		index;

	index = 0;
	if (p_name != NULL)
	{
		ft_putchar('{');
		ft_putstr(p_name);
		ft_putstr("}\n");
	}
	ft_putstr("-----===-----\n");
	while (p_tab && p_tab[index])
	{
		ft_putnbr(index);
		ft_putstr("--->[");
		ft_putstr(p_tab[index]);
		ft_putstr("]\n");
		index++;
	}
	ft_putstr("-----===-----\n");
}
