/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:14:19 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/02/25 12:10:59 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tab_cpy(void **dst, void **src)
{
	int	index;

	index = 0;
	while (src[index] != NULL)
	{
		dst[index] = src[index];
		index++;
	}
}
