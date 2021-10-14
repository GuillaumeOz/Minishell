/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_lower_io_case.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:26:43 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/14 14:41:41 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_lower_io_case(t_cmd *cmd, t_lexer *reader)
{
	int	*fd;

	if (cmd->error == true)
		return ;
	fd = (int *)malloc(sizeof(int));
	if (fd == NULL)
		minishell_error("int * cannot be allocated");
	*fd = open(reader->args, O_RDONLY);
	if (*fd == -1)
		cmd->error = true;
	list2_push_back(cmd->in_fd, fd);
	cmd->cmd_stdin = *fd;
}
