/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_alpha_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:30:13 by ldutriez          #+#    #+#             */
/*   Updated: 2020/02/25 12:36:38 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_is_alpha_num(char p_c)
{
	if (ft_is_digit(p_c) || ft_is_alpha(p_c))
		return (true);
	return (false);
}
