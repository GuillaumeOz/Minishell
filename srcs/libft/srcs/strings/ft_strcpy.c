/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:19:55 by ncoudsi           #+#    #+#             */
/*   Updated: 2019/12/04 15:50:24 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *p_src, char *p_dest)
{
	int	i;

	i = 0;
	if (p_src == NULL || p_dest == NULL)
		return (NULL);
	while (p_src[i] != '\0')
	{
		p_dest[i] = p_src[i];
		i++;
	}
	p_dest[i] = '\0';
	return (p_dest);
}
