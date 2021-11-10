/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 11:49:49 by tguilbar          #+#    #+#             */
/*   Updated: 2021/05/25 14:12:00 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbrlen(long long int nbr, size_t base_len)
{
	size_t					nbr_len;
	unsigned long long int	abs_nbr;

	nbr_len = 1;
	if (nbr < 0)
	{
		nbr_len++;
		abs_nbr = -nbr;
	}
	else
		abs_nbr = nbr;
	while (abs_nbr >= base_len)
	{
		abs_nbr /= base_len;
		nbr_len++;
	}
	return (nbr_len);
}

char	*ft_itoa_base(long long int nbr, char *base)
{
	size_t					base_len;
	size_t					nbr_len;
	char					*result;
	unsigned long long int	abs_nbr;

	base_len = ft_strlen(base);
	nbr_len = nbrlen(nbr, base_len);
	result = ft_strnew(nbr_len);
	if (nbr < 0)
	{
		result[0] = '-';
		abs_nbr = -nbr;
	}
	else
		abs_nbr = nbr;
	result[nbr_len] = '\0';
	nbr_len--;
	while (abs_nbr >= base_len)
	{
		result[nbr_len] = base[abs_nbr % base_len];
		abs_nbr /= base_len;
		nbr_len--;
	}
	result[nbr_len] = base[abs_nbr % base_len];
	return (result);
}
