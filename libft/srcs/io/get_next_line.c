/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:59:27 by ldutriez          #+#    #+#             */
/*   Updated: 2021/05/25 12:48:19 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_line(int fd, char **line)
{
	static char	*bucket;
	char		*cup;
	int			line_state;

	line_state = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (IS_AN_ERROR);
	cup = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (cup == NULL)
		return (IS_AN_ERROR);
	while (!ft_slen_eol(bucket, EOL) && line_state != IS_AN_END)
	{
		line_state = read(fd, cup, BUFFER_SIZE);
		if (line_state == IS_AN_ERROR)
			return (IS_AN_ERROR);
		cup[line_state] = '\0';
		bucket = ft_stradd(bucket, cup);
	}
	free(cup);
	*line = ft_makeline(bucket);
	bucket = ft_rm_line(bucket);
	if (line_state == IS_AN_END)
		return (IS_AN_END);
	return (IS_A_LINE);
}
