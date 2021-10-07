/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:46:29 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/05 19:04:44 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LIST_H
# define T_LIST_H

typedef struct s_list2
{
	void		***content;
	size_t		size;
	size_t		max_size;
	size_t		nb_line;
	size_t		push_size;
}				t_list2;

typedef struct s_int_vector2
{
	int	x;
	int	y;
}				t_int_vector2;

t_int_vector2		*malloc_int_vector2(int x, int y);
t_int_vector2		create_int_vector2(int x, int y);
void				destroy_int_vector2(t_int_vector2 to_destroy);
void				free_int_vector2(t_int_vector2 *to_free);

typedef void	(*t_list2_destroy_funct)(void *to_destroy);

t_list2			create_list2(size_t p_push_size);
t_list2			*malloc_list2(size_t p_push_size);
void			destroy_list2(t_list2 to_destroy, t_list2_destroy_funct funct);
void			free_list2(t_list2 *to_free, t_list2_destroy_funct funct);

t_int_vector2	list2_calc_index_coord(t_list2 *list, size_t index);
void			list2_push_back(t_list2 *list, void *to_add);
void			*list2_at(t_list2 *list, size_t index);
void			**list2_get(t_list2 *list, size_t index);
void			clear_list2(t_list2 *to_clear, t_list2_destroy_funct funct);

#endif
