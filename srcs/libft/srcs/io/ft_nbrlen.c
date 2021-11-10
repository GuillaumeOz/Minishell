/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:14:11 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/14 12:10:06 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_nbrlen(int nbr)
{
	unsigned long long		i;
	unsigned long long int	abs_nbr;

	i = 1;
	if (nbr < 0)
	{
		i++;
		abs_nbr = -nbr;
	}
	else
		abs_nbr = nbr;
	while (abs_nbr >= 10)
	{
		abs_nbr /= 10;
		i++;
	}
	return (i);
}
