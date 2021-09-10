/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 08:24:59 by ldutriez          #+#    #+#             */
/*   Updated: 2020/02/25 11:46:49 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_add_back(t_list **p_list, t_list *p_node)
{
	t_list	*start_list;

	if (p_node == NULL || p_list == NULL)
		return ;
	if (*p_list == NULL)
	{
		*p_list = p_node;
		return ;
	}
	start_list = *p_list;
	if (start_list == NULL)
		start_list = p_node;
	else
	{
		while (start_list->next != NULL)
			start_list = start_list->next;
		start_list->next = p_node;
	}
}
