/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_roof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 08:52:38 by ldutriez          #+#    #+#             */
/*   Updated: 2021/05/25 14:12:55 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_i_roof(float p_value)
{
	int	i_value;

	if (p_value == 0)
		return (0);
	i_value = p_value;
	if (p_value < 0)
		return (i_value);
	else
		return (i_value + 1);
}
