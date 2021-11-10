/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:47:00 by chdespon          #+#    #+#             */
/*   Updated: 2021/06/11 16:53:28 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *p_src, char *p_target, int len)
{
	int	i;

	i = 0;
	while ((p_src[i] != '\0' || p_target[i] != '\0') && i < len)
	{
		if (p_src[i] < p_target[i])
			return (-1);
		if (p_src[i] > p_target[i])
			return (1);
		i++;
	}
	return (0);
}
