/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:34:11 by ncoudsi           #+#    #+#             */
/*   Updated: 2020/09/28 13:42:00 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_get_file(char *path)
{
	char	**result;
	int		fd;
	char	*line;

	result = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 3)
	{
		printf("%s\n", "Error : Bad fd");
		return (NULL);
	}
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		ft_add_to_tab((void *)line, (void ***)&result);
	}
	close(fd);
	return (result);
}
