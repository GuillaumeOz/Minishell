/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_tab_fp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:40:26 by chdespon          #+#    #+#             */
/*   Updated: 2021/05/25 12:49:13 by chdespon         ###   ########.fr       */
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

static void	print_tab(int fd, char *p_name, char **p_tab)
{
	size_t	index;

	index = 0;
	if (p_name != NULL)
	{
		ft_putchar_fd(fd, '{');
		ft_putstr_fd(fd, p_name);
		ft_putstr_fd(fd, "}\n");
	}
	ft_putstr_fd(fd, "-----===-----\n");
	while (p_tab && p_tab[index])
	{
		ft_putnbr_fd(fd, index);
		ft_putstr_fd(fd, "--->[");
		ft_putstr_fd(fd, p_tab[index]);
		ft_putstr_fd(fd, "]\n");
		index++;
	}
	ft_putstr_fd(fd, "-----===-----\n");
}

void	ft_print_str_tab_fp(char *path, char *p_name,
													char **p_tab, char *mode)
{
	int	fd;

	fd = -1;
	if (mode == NULL || path == NULL)
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
		print_tab(fd, p_name, p_tab);
	close(fd);
}
