/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_exist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:44:36 by ldutriez          #+#    #+#             */
/*   Updated: 2020/02/26 16:04:32 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_file_exist(char *p_path)
{
	int	fd;

	fd = open(p_path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}
