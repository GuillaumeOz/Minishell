/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_round.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguilbar <tguilbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:54:18 by tguilbar          #+#    #+#             */
/*   Updated: 2020/01/12 13:46:25 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_f_round(float p_value)
{
	float	floor;
	float	roof;

	floor = ft_f_floor(p_value);
	roof = ft_f_roof(p_value);
	if ((p_value - floor) < (roof - p_value))
		return (floor);
	else
		return (roof);
}
