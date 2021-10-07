/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:21:13 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/07 16:23:56 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_exec_args_handler(t_lexer *lexer, t_lexer *limiter, t_cmd *cmd)
{
	t_lexer *reader;

	reader = lexer;
	if (lexer->error == true)
		return ;
	else if (is_exec_case(lexer, limiter, &reader) == true)
		exec_case(cmd, lexer, limiter, &reader);
}

void	cmd_output_gestion(t_lexer *lexer, t_lexer *limiter, t_cmd *cmd)
{
	t_lexer *reader;

	reader = lexer;
	if (lexer->error == true)
		return ;
	else if (is_exec_double_greater_io_case(lexer, limiter, &reader) == true)
		exec_double_greater_io_case(cmd, lexer, limiter, &reader);
	else if (is_exec_greater_io_case(lexer, limiter, &reader) == true)
		exec_greater_io_case(cmd, lexer, limiter, &reader);
}

void	cmd_input_gestion(t_lexer *lexer, t_lexer *limiter, t_cmd *cmd)
{
	t_lexer *reader;

	reader = lexer;
	if (lexer->error == true)
		return ;
	if (is_exec_double_lower_io_case(lexer, limiter, &reader) == true)
		exec_double_lower_io_case(cmd, lexer, limiter, &reader);
	else if (cmd->limiter != NULL)
		exec_here_doc(cmd, lexer, limiter);//add expantion gestion inside line catcher
	else if (is_exec_lower_io_case(lexer, limiter, &reader) == true)
		exec_lower_io_case(cmd, lexer, limiter, &reader);
}

void	cmd_handler(t_lexer *lexer, t_list2 *cmd_list, char ***env)
{
	t_lexer *reader;
	t_cmd	*cmd;

	reader = lexer;
	if (is_cmd_pipe_case(lexer, &reader) == true)
	{
		cmd = malloc_cmd(env);// handle the case "< file << end | < file2 << end1" as same as bash
		cmd_input_gestion(lexer, reader, cmd);
		cmd_output_gestion(lexer, reader, cmd);
		cmd_exec_args_handler(lexer, reader, cmd);
		list2_push_back(cmd_list, cmd);
		cmd_handler(reader, cmd_list, env);
	}
	else
	{
		cmd = malloc_cmd(env);
		cmd_input_gestion(lexer, NULL, cmd);
		cmd_output_gestion(lexer, NULL, cmd);
		cmd_exec_args_handler(lexer, NULL, cmd);
		list2_push_back(cmd_list, cmd);
	}
}
