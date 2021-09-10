/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_only_whitespaces.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:44:35 by ncoudsi           #+#    #+#             */
/*   Updated: 2021/07/16 14:35:48 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_is_only_whitespaces(char *str)
{
	size_t	index;

	index = 0;
	if (str == NULL)
		return (false);
	while (str[index] != '\0')
	{
		if (ft_is_whitespaces(str[index]) == false)
			return (false);
		index++;
	}
	return (true);
}
