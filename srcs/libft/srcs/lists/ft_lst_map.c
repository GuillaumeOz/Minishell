/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:17:49 by tguilbar          #+#    #+#             */
/*   Updated: 2021/05/25 12:31:46 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_map(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l1;
	t_list	*new;
	int		error;

	error = 0;
	if (lst == NULL)
		return (NULL);
	l1 = ft_lst_create_node((*f)(lst->data));
	if (l1 == NULL)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new = ft_lst_create_node((*f)(lst->data));
		if (new == NULL)
			error = 1;
		ft_lst_add_back(&l1, new);
		lst = lst->next;
	}
	if (!error)
		return (l1);
	ft_lst_clear(&l1, del);
	return (NULL);
}
