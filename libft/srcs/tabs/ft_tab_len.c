/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:13:14 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/09/14 11:39:31 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tab_len(void **tab)
{
	int	index;

	index = 0;
	if (tab == NULL)
	{
		return (index);
	}
	while (tab[index] != NULL)
		index++;
	return (index);
}
