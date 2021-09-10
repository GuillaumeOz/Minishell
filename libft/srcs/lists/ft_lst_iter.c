/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:31:29 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/25 11:14:58 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_iter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	while (lst->next)
	{
		(*f)(lst->data);
		lst = lst->next;
	}
	(*f)(lst->data);
}
