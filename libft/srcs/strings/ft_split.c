/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:57:07 by ncoudsi           #+#    #+#             */
/*   Updated: 2021/05/25 12:41:10 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char *p_src, char p_sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (p_src[i] != '\0')
	{
		if (p_src[i] == p_sep)
			i++;
		if (p_src[i] != '\0' && p_src[i] != p_sep)
		{
			count++;
			while (p_src[i] != '\0' && p_src[i] != p_sep)
				i++;
		}
	}
	return (count);
}

static void	*ft_clear(char **p_tab, int p_j)
{
	while (p_j >= 0)
	{
		free(p_tab[p_j]);
		p_j--;
	}
	free(p_tab);
	return (NULL);
}

static size_t	ft_wordlen(char *p_src, char p_sep)
{
	size_t	result;

	result = 0;
	while (p_src[result] != '\0' && p_src[result] != p_sep)
		result++;
	return (result);
}

static char	**ft_fill_tab(char **p_tab, char *p_src,
													char p_sep, size_t tab_size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < tab_size)
	{
		while (p_src[i] != '\0' && p_src[i] == p_sep)
			i++;
		if (p_src[i] != '\0')
		{
			p_tab[j] = ft_strsub(p_src, i, ft_wordlen(p_src + i, p_sep));
			if (p_tab[j] == NULL)
				return (ft_clear(p_tab, j));
		}
		while (p_src[i] != '\0' && p_src[i] != p_sep)
			i++;
		j++;
	}
	p_tab[j] = NULL;
	return (p_tab);
}

char	**ft_split(char *p_src, char p_sep)
{
	size_t	tab_size;
	char	**result;

	if (p_src == NULL || p_sep == '\0')
		return (NULL);
	tab_size = ft_word_count(p_src, p_sep);
	result = (char **)malloc(sizeof(char *) * (tab_size + 1));
	if (result == NULL)
		return (NULL);
	if (ft_fill_tab(result, p_src, p_sep, tab_size) == NULL)
		return (NULL);
	return (result);
}
