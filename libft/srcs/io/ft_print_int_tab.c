/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:00:33 by ldutriez          #+#    #+#             */
/*   Updated: 2020/02/26 10:29:10 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_tab(char *p_name, int *p_tab, size_t len)
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
	while (p_tab && index < len)
	{
		ft_putnbr(index);
		ft_putstr("--->[");
		ft_putnbr(p_tab[index]);
		ft_putstr("]\n");
		index++;
	}
	ft_putstr("-----===-----\n");
}
