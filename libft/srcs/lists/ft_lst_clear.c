/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:47:03 by tguilbar          #+#    #+#             */
/*   Updated: 2021/05/25 12:32:13 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_clear(t_list **lst, void (*del)(void*))
{
	t_list	*l;

	if (*lst == NULL)
		return ;
	while (*lst)
	{
		l = *lst;
		if (del != NULL)
			(*del)(l->data);
		*lst = l->next;
		free(l);
	}
	l = NULL;
	lst = NULL;
}
