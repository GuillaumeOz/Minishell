/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rm_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 09:51:44 by tguilbar          #+#    #+#             */
/*   Updated: 2021/05/25 12:32:28 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_rm_node(t_list **lst, size_t num, void (*del)(void*))
{
	t_list	*lst1;
	t_list	*lst2;

	if (lst == NULL || *lst == NULL)
		return ;
	lst1 = *lst;
	lst2 = lst1->next;
	if (num == 0)
	{
		*lst = lst2;
		ft_lst_rm_data(lst1, del);
		return ;
	}
	while (num > 1 && lst1->next)
	{
		lst1 = lst2;
		lst2 = lst1->next;
		num--;
	}
	if (num > 1)
		return ;
	lst1->next = lst2->next;
	ft_lst_rm_data(lst2, del);
	return ;
}
