/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:27:56 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/25 14:26:59 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_message(char *name, char *builtin)
{
	ft_putstr_fd(2, "minishell: ");
	ft_putstr_fd(2, builtin);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, name);
	ft_putstr_fd(2, " : option non valable\nexport : utilisation : ");
	ft_putstr_fd(2, builtin);
	ft_putstr_fd(2, " [-fn] [nom[=valeur] ...] ou export -p\n");
	return (2);
}

void	ft_swap(char **x, char **y)
{
	char	*tmp;

	tmp = NULL;
	if (x == NULL || y == NULL)
		return ;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
