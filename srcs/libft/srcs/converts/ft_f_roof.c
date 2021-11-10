/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_roof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:11:18 by ldutriez          #+#    #+#             */
/*   Updated: 2021/05/25 14:12:24 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_f_roof(float p_value)
{
	float	rounded_value;
	int		i_value;

	if (p_value == 0)
		return (p_value);
	i_value = p_value;
	if (p_value < 0)
	{
		rounded_value = i_value;
		return (rounded_value);
	}
	rounded_value = p_value - i_value;
	if (rounded_value == 0)
	{
		rounded_value = p_value;
		return (rounded_value);
	}
	else
		rounded_value = i_value + 1;
	return (rounded_value);
}
