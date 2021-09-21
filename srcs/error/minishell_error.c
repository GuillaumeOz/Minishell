/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:08:30 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/21 20:23:05 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_error(char *error_msg)
{
	ft_putstr_fd(2, "Error : ");
	ft_putstr_fd(2, error_msg);
	ft_putstr_fd(2, "\n");
	exit(EXIT_FAILURE);//remove exit later
}

void	minishell_syntax_error(char *token)
{
	ft_putstr_fd(2, "Minishell: syntax error near unexpected token");
	ft_putstr_fd(2, "`");
	ft_putstr_fd(2, token);
	ft_putstr_fd(2, "'");
	ft_putstr_fd(2, "\n");
}
