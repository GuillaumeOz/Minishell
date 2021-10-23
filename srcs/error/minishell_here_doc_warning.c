/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_here_doc_warning.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:18:05 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/23 20:23:51 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	here_doc_warning(t_cmd *cmd, char *line, int *i, int weight)
{
	ft_putstr_fd(2, "Minishell: warning: ");
	ft_putstr_fd(2, "here-document delimited by end-of-file (wanted `");
	ft_putstr_fd(2, (cmd->limiter[*i] + weight));
	ft_putstr_fd(2, "')");
	ft_putstr_fd(2, "\n");
	free(line);
}