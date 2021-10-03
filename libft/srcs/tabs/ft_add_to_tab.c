/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:09:42 by ncoudsi           #+#    #+#             */
/*   Updated: 2021/10/03 16:25:41 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_to_tab(void *to_add, void ***tab)
{
	void	**tmp;

	tmp = *tab;
	*tab = ft_tab_new(ft_tab_len(tmp) + 1);
	if (tmp != NULL)
	{
		ft_tab_cpy(*tab, tmp);
		free(tmp);
	}
	(*tab)[ft_tab_len(*tab)] = to_add;
}
