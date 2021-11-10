/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_structures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 08:21:26 by ldutriez          #+#    #+#             */
/*   Updated: 2021/09/30 19:49:26 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCTURES_H
# define LIBFT_STRUCTURES_H

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

#endif
