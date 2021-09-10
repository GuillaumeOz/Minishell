/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned_deci.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:42:31 by ncoudsi           #+#    #+#             */
/*   Updated: 2021/05/25 14:11:05 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbrlen(unsigned long long int nbr, size_t base_len)
{
	size_t	nbr_len;

	nbr_len = 1;
	while (nbr >= base_len)
	{
		nbr /= base_len;
		nbr_len++;
	}
	return (nbr_len);
}

char	*ft_itoa_unsigned_deci(unsigned int nbr)
{
	char	*base;
	size_t	base_len;
	size_t	nbr_len;
	char	*result;

	base = "0123456789";
	base_len = ft_strlen(base);
	nbr_len = nbrlen(nbr, base_len);
	result = ft_strnew(nbr_len);
	result[nbr_len] = '\0';
	nbr_len--;
	while (nbr >= base_len)
	{
		result[nbr_len] = base[nbr % base_len];
		nbr /= base_len;
		nbr_len--;
	}
	result[nbr_len] = base[nbr % base_len];
	return (result);
}
