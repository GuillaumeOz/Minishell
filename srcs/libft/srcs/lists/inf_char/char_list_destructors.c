/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_list_destructors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:18:38 by ldutriez          #+#    #+#             */
/*   Updated: 2021/05/25 12:33:07 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	destroy_t_char_list(t_char_list to_delete)
{
	size_t	i;

	i = 0;
	while (to_delete.data[i] != NULL)
	{
		free(to_delete.data[i]);
		i++;
	}
	free(to_delete.data);
}

void	free_t_char_list(t_char_list *to_free)
{
	destroy_t_char_list(*to_free);
	free(to_free);
}
