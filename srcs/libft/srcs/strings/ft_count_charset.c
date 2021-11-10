/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:40:36 by chdespon          #+#    #+#             */
/*   Updated: 2020/10/15 14:17:41 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_charset(char *p_src, char p_c)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (p_src[i] != '\0')
	{
		if (p_src[i] == p_c)
			res++;
		i++;
	}
	return (res);
}
