/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:01:57 by chdespon          #+#    #+#             */
/*   Updated: 2020/09/28 14:02:10 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int fd, int nb)
{
	if (nb < 0)
	{
		ft_putchar_fd(fd, '-');
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(fd, nb / 10);
	}
	ft_putchar_fd(fd, (nb % 10) + '0');
}
