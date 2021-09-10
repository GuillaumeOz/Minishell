/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_structures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 08:21:26 by ldutriez          #+#    #+#             */
/*   Updated: 2021/05/25 12:28:59 by chdespon         ###   ########.fr       */
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
