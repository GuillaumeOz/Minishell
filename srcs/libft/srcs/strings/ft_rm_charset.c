/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_charset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:59:06 by ldutriez          #+#    #+#             */
/*   Updated: 2021/05/25 12:38:02 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	is_not_in_cs(char p_c, char *p_charset)
{
	int	index;

	index = 0;
	while (p_charset && p_charset[index])
	{
		if (p_c == p_charset[index])
			return (false);
		index++;
	}
	return (true);
}

static int	str_len_without_cs(char *p_str, char *p_charset)
{
	int	result;
	int	index;

	result = 0;
	index = 0;
	while (p_str && p_str[index])
	{
		if (is_not_in_cs(p_str[index], p_charset))
			result++;
		index++;
	}
	return (result);
}

char	*ft_rm_charset(char *p_str, char *p_charset)
{
	char	*result;
	int		index;
	int		index2;
	int		len_without_c;

	index = 0;
	index2 = 0;
	len_without_c = str_len_without_cs(p_str, p_charset);
	result = ft_strnew(len_without_c);
	if (result == NULL)
		return (NULL);
	while (p_str && p_str[index])
	{
		if (is_not_in_cs(p_str[index], p_charset))
		{
			result[index2] = p_str[index];
			index2++;
		}
		index++;
	}
	return (result);
}
