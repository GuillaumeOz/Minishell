/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:24:40 by ncoudsi           #+#    #+#             */
/*   Updated: 2019/12/11 18:36:08 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *p_str1, char *p_str2)
{
	int		result_len;
	int		index;
	int		str1_len;
	char	*result;

	if (p_str1 == NULL || p_str2 == NULL)
		return (NULL);
	result_len = (ft_strlen(p_str1) + ft_strlen(p_str2));
	index = 0;
	str1_len = ft_strlen(p_str1);
	result = ft_strnew(result_len);
	if (result == NULL)
		return (NULL);
	while (index < str1_len)
	{
		result[index] = p_str1[index];
		index++;
	}
	index = 0;
	while (p_str2[index] != '\0')
	{
		result[index + str1_len] = p_str2[index];
		index++;
	}
	return (result);
}
