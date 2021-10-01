/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:51:40 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/01 21:32:52 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list2	*malloc_list2(size_t p_push_size)
{
	t_list2	*result;

	result = (t_list2 *)malloc(sizeof(t_list2));
	if (result == NULL)
	{
		ft_putstr_fd(2, "Error\n ");
		ft_putstr_fd(2, "A int_vector2 can't be malloc");
		exit(-1);
	}
	*result = create_list2(p_push_size);
	return (result);
}

t_list2	create_list2(size_t p_push_size)
{
	t_list2	result;

	result.content = NULL;
	result.size = 0;
	result.push_size = p_push_size;
	result.nb_line = 0;
	result.max_size = 0;
	return (result);
}

void	clear_list2(t_list2 *to_clear, t_list2_destroy_funct funct)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (funct != NULL && i < to_clear->nb_line)
	{
		j = 0;
		while (j < to_clear->push_size)
		{
			funct(to_clear->content[i][j]);
			j++;
		}
		i++;
	}
	to_clear->size = 0;
}

void	destroy_list2(t_list2 to_destroy, t_list2_destroy_funct funct)
{
	size_t	i;

	i = 0;
	clear_list2(&to_destroy, funct);
	while (i < to_destroy.nb_line)
		free(to_destroy.content[i++]);
	free(to_destroy.content);
}

void	free_list2(t_list2 *to_free, t_list2_destroy_funct funct)
{
	destroy_list2(*to_free, funct);
	free(to_free);
}
