/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_only_digit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:44:35 by ncoudsi           #+#    #+#             */
/*   Updated: 2021/05/25 12:42:15 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_is_only_digit(char *str)
{
	size_t	index;

	index = 0;
	if (str == NULL)
		return (false);
	while (str[index] != '\0')
	{
		if (ft_is_digit(str[index]) == false)
			return (false);
		index++;
	}
	return (true);
}
