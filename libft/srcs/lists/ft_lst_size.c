/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:13:06 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/25 09:48:23 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_size(t_list *lst)
{
	int		compt;

	if (lst == 0)
		return (0);
	compt = 1;
	while (lst->next)
	{
		lst = lst->next;
		compt++;
	}
	return (compt);
}
