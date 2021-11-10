/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:44:08 by tguilbar          #+#    #+#             */
/*   Updated: 2020/02/25 11:51:28 by tguilbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_rm_data(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	del(lst->data);
	free(lst);
	lst = NULL;
}
