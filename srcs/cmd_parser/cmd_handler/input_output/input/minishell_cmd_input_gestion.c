/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_input_gestion.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:54:22 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/26 19:53:46 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cmd_limiter_cleaner(t_cmd *cmd)
{
	ft_free_tab((void **)cmd->limiter);
	cmd->limiter = NULL;
}

void	cmd_limiter_handler(t_lexer *lexer, t_lexer *limiter, t_cmd *cmd)
{
	t_lexer	*reader;

	reader = lexer;
	if (is_exec_double_lower_io_case(lexer, limiter, &reader) == true)
		exec_double_lower_io_case(cmd, lexer, limiter, &reader);
}

void	cmd_input_handler(t_lexer *lexer, t_lexer *limiter, t_cmd *cmd)
{
	t_lexer	*reader;
	char	*error_token;
	int		i;

	i = 0;
	error_token = NULL;
	reader = lexer;
	while (reader != limiter && lexer->error == false)
	{
		if (is_exec_lower_io_case(reader) == true)
			exec_lower_io_case(cmd, reader->next);
		else if (is_exec_here_doc_io_case(reader) == true)
			exec_here_doc(lexer, cmd, &i);
		if (lexer->error == true)
			return (cmd_limiter_cleaner(cmd));
		if (error_token == NULL && cmd->error == true)
			error_token = reader->args;
		reader = reader->next;
	}
	if (cmd->error == true)
		minishell_lower_fd_error(lexer, limiter, error_token);
	if (cmd->here_doc == true)
		cmd_limiter_cleaner(cmd);
}

void	cmd_input_gestion(t_lexer *lexer, t_lexer *limiter, t_cmd *cmd)
{
	if (lexer->error == true)
		return ;
	cmd_limiter_handler(lexer, limiter, cmd);
	cmd_input_handler(lexer, limiter, cmd);
}
