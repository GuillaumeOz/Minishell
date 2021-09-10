/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add_suffix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoudsi <ncoudsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:32:29 by ncoudsi           #+#    #+#             */
/*   Updated: 2019/12/11 11:21:43 by ncoudsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_add_suffix(char **p_str, char *p_suffix)
{
	char	*tmp;

	if (p_str == NULL || p_suffix == NULL)
		return ;
	tmp = ft_strdup(*p_str);
	free(*p_str);
	*p_str = ft_strjoin(tmp, p_suffix);
	free(tmp);
}
