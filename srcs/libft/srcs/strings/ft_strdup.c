/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:46:00 by ncoudsi           #+#    #+#             */
/*   Updated: 2019/12/03 17:23:49 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *p_src)
{
	int		i;
	int		len;
	char	*dup;

	if (p_src == NULL)
		return (NULL);
	len = ft_strlen(p_src);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = p_src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
