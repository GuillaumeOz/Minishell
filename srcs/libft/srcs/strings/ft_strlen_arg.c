/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:18:38 by tguilbar          #+#    #+#             */
/*   Updated: 2021/05/25 12:39:09 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_arg(char *p_str, char p_c)
{
	size_t	i;
	size_t	size;

	size = 0;
	i = 0;
	if (p_str == NULL)
		return (0);
	while (p_str[i])
	{
		if (p_str[i] != p_c)
			size++;
		i++;
	}
	return (size);
}
