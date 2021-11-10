/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:55:01 by ncoudsi           #+#    #+#             */
/*   Updated: 2019/12/04 16:56:59 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char *p_src, size_t p_start, size_t p_len)
{
	size_t	i;
	char	*result;

	i = 0;
	result = NULL;
	if (p_src == NULL || p_start > ft_strlen(p_src) || p_len == 0)
		return (NULL);
	result = ft_strnew(p_len);
	while (i < p_len)
	{
		result[i] = p_src[p_start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
