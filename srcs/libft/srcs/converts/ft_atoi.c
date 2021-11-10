/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:47:17 by ncoudsi           #+#    #+#             */
/*   Updated: 2021/03/23 15:34:10 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(char *p_str)
{
	long long	result;
	int			index;
	int			sign;

	if (p_str == NULL)
		return (0);
	result = 0;
	index = 0;
	sign = 1;
	while (p_str[index] == ' ')
		index++;
	if (p_str[index] == '+')
		index++;
	else if (p_str[index] == '-')
	{
		index++;
		sign *= -1;
	}
	while (p_str[index] != '\0' && (p_str[index] >= '0' && p_str[index] <= '9'))
	{
		result = (result * 10) + (p_str[index] - 48);
		index++;
	}
	return (result * sign);
}
