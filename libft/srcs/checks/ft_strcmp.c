/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:55:32 by ncoudsi           #+#    #+#             */
/*   Updated: 2021/05/31 14:29:56 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *p_src, char *p_target)
{
	size_t	i;

	i = 0;
	while (p_src[i] != '\0' || p_target[i] != '\0')
	{
		if (p_src[i] < p_target[i])
			return (-1);
		if (p_src[i] > p_target[i])
			return (1);
		i++;
	}
	return (0);
}
