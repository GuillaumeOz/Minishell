/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:44:18 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/25 12:50:34 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	file_overwrite(char *path)
{
	int	fd;

	fd = -1;
	if (ft_file_exist(path))
		fd = open(path, O_WRONLY | O_TRUNC);
	return (fd);
}

static int	file_append(char *path)
{
	int	fd;

	fd = -1;
	if (ft_file_exist(path))
		fd = open(path, O_WRONLY | O_APPEND);
	return (fd);
}

static int	file_create(char *path)
{
	int	fd;

	fd = -1;
	if (ft_file_exist(path) == false)
		fd = open(path, O_WRONLY | O_APPEND | O_CREAT, 00700);
	return (fd);
}

void	ft_putstr_fp(char *path, char *str, char *mode)
{
	int	fd;

	fd = -1;
	if (str == NULL || mode == NULL || path == NULL)
		return ;
	if (ft_strcmp(mode, "OVERWRITE"))
	{
		fd = file_overwrite(path);
	}
	else if (ft_strcmp(mode, "APPEND"))
	{
		fd = file_append(path);
	}
	else if (ft_strcmp(mode, "CREATE"))
	{
		fd = file_create(path);
	}
	if (fd != -1)
		write(fd, str, ft_strlen(str));
	close(fd);
}
