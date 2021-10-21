/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_t_cmd_constructor.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 20:57:07 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/21 14:21:18 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*malloc_cmd(char ***env, t_cmd_postion pos)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (cmd == NULL)
		minishell_error("t_lexer can't be allocate");
	*cmd = create_cmd(env, pos);
	return (cmd);
}

static void	create_in_out_file_cmd(t_cmd *cmd)
{
	int	*in_std;
	int	*out_std;

	in_std = (int *)malloc(sizeof(int));
	out_std = (int *)malloc(sizeof(int));
	if (in_std == NULL || out_std == NULL)
		minishell_error("int * cannot be allocated");
	*in_std = 0;
	*out_std = 1;
	cmd->in_fd = malloc_list2(1);
	list2_push_back(cmd->in_fd, in_std);
	cmd->out_fd = malloc_list2(1);
	list2_push_back(cmd->out_fd, out_std);
}

t_cmd	create_cmd(char ***env, t_cmd_postion pos)
{
	t_cmd	cmd;

	cmd.pos = pos;
	cmd.env = env;
	create_in_out_file_cmd(&cmd);
	cmd.cmd_stdin = 0;
	cmd.cmd_stdout = 1;
	cmd.pipe = NULL;
	cmd.previous_pipe = NULL;
	cmd.here_doc = false;
	cmd.here_doc_pipe = NULL;
	cmd.limiter = NULL;
	cmd.cmd = NULL;
	cmd.args = NULL;
	cmd.error = false;
	return (cmd);
}
