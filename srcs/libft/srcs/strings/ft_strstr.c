/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:29:15 by ldutriez          #+#    #+#             */
/*   Updated: 2021/05/25 12:38:52 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *p_haystack, char *p_needle)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (!*p_needle)
		return ((char *)p_haystack);
	while (p_haystack[i] != '\0')
	{
		if (p_needle[0] == p_haystack[i])
		{
			n = 1;
			while (p_needle[n] != '\0'
				&& p_haystack[i + n] == p_needle[n])
				n++;
			if (p_needle[n] == '\0')
				return ((char *)&p_haystack[i]);
		}
		i++;
	}
	return (0);
}
