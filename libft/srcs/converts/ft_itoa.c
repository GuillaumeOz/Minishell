/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:30:21 by ncoudsi           #+#    #+#             */
/*   Updated: 2021/05/25 14:12:45 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long long int nbr)
{
	char	*base;
	char	*result;

	base = "0123456789";
	result = ft_itoa_base(nbr, base);
	return (result);
}
