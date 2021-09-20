/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 00:05:11 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/20 12:20:10 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfre(char *s1, char *s2, int free_s1, int free_s2)
{
	char	*new_str;

	new_str = ft_strjoin(s1, s2);
	if (s1 && free_s1)
		free((void *)s1);
	if (s2 && free_s2)
		free((void *)s2);
	return (new_str);
}
