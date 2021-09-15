/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:55:32 by ncoudsi           #+#    #+#             */
/*   Updated: 2021/09/15 21:48:06 by gozsertt         ###   ########.fr       */
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
