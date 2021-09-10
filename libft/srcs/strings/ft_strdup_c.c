/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:57:19 by ncoudsi           #+#    #+#             */
/*   Updated: 2019/12/02 18:03:36 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_c(char p_c)
{
	char	*dup;

	dup = (char *)malloc(sizeof(char) * 2);
	if (dup == NULL)
		return (NULL);
	dup[0] = p_c;
	dup[1] = '\0';
	return (dup);
}
