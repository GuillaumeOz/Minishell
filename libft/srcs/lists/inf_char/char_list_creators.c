/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list_creators.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:15:16 by ldutriez          #+#    #+#             */
/*   Updated: 2021/05/25 12:36:49 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_chartab_new(size_t nb)
{
	char	**tab;
	size_t	i;

	tab = (char **)malloc(sizeof(char *) * (nb + 1));
	i = 0;
	while (i <= nb)
	{
		tab[i] = NULL;
		i++;
	}
	return (tab);
}

t_char_list	create_char_list(size_t p_size)
{
	t_char_list	result;

	result.size = p_size;
	result.data = ft_chartab_new(p_size);
	return (result);
}

t_char_list	*malloc_char_list(size_t p_push_size)
{
	t_char_list	*char_result;

	char_result = (t_char_list *)malloc(sizeof(t_char_list));
	*char_result = create_char_list(p_push_size);
	return (char_result);
}
