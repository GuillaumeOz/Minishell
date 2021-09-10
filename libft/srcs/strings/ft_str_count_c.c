/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_count_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:55:11 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/02/25 11:12:51 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_count_c(char *str, char c)
{
	int	result;
	int	index;

	result = 0;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == c)
			result++;
		index++;
	}
	return (result);
}
