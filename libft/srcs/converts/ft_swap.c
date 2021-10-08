/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:35:23 by chdespon          #+#    #+#             */
/*   Updated: 2021/09/23 15:42:17 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Thoses functions will use the XOR bit operator
**	to swap two integers values.
*/

void	ft_swap_int(int *x, int *y)
{
	if (x == NULL || y == NULL)
		return ;
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

void	ft_swap_char(char *x, char *y)
{
	if (x == NULL || y == NULL)
		return ;
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}
