/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 00:34:12 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/17 01:46:02 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*dst;
	size_t	i;

	dst = NULL;
	dst = (char *)malloc(sizeof(char) * (ft_strnlen(src, n) + 1));
	if (dst == NULL)
		return (NULL);
	i = -1;
	while (++i < n)
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
