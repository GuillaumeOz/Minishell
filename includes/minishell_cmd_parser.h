/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_parser.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:09:39 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/26 15:18:47 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_CMD_PARSER_H
# define MINISHELL_CMD_PARSER_H

t_bool	is_exec_case(t_lexer *lexer, t_lexer *limiter, t_lexer **reader);

void	exec_case(t_cmd *cmd, t_lexer *lexer,
			t_lexer *limiter, t_lexer **reader);
void	cmd_exec_args_handler(t_lexer *lexer, t_lexer *limiter, t_cmd *cmd);

t_bool	is_exec_greater_io_case(t_lexer *reader);
t_bool	is_exec_double_greater_io_case(t_lexer *reader);

void	exec_greater_io_case(t_cmd *cmd, t_lexer *lexer,
			t_lexer *limiter, t_lexer *reader);
void	exec_double_greater_io_case(t_cmd *cmd, t_lexer *lexer,
			t_lexer *limiter, t_lexer *reader);

void	cmd_output_gestion(t_lexer *lexer, t_lexer *limiter, t_cmd *cmd);

t_bool	is_exec_lower_io_case(t_lexer *reader);
void	exec_lower_io_case(t_cmd *cmd, t_lexer *reader);
t_bool	is_exec_here_doc_io_case(t_lexer *reader);
void	cmd_input_handler(t_lexer *lexer, t_lexer *limiter, t_cmd *cmd);

t_bool	is_exec_double_lower_io_case(t_lexer *lexer,
			t_lexer *limiter, t_lexer **reader);
void	exec_double_lower_io_case(t_cmd *cmd, t_lexer *lexer,
			t_lexer *limiter, t_lexer **reader);
void	here_doc_dollar_transformation(t_cmd *cmd, char **line);
t_bool	limitercmp(char *line, char *limiter, int weight);
void	exec_here_doc(t_lexer *lexer, t_cmd *cmd, int *i);
void	cmd_limiter_handler(t_lexer *lexer, t_lexer *limiter, t_cmd *cmd);

void	cmd_input_gestion(t_lexer *lexer, t_lexer *limiter, t_cmd *cmd);

void	cmd_input_output_gestion(t_lexer *lexer,
			t_lexer *reader, t_cmd *cmd, t_list2 *cmd_list);

t_bool	is_cmd_pipe_case(t_lexer *lexer, t_lexer **reader);

void	cmd_handler(t_lexer *lexer, t_list2 *cmd_list, char ***env);

void	cmd_gestion(t_lexer *lexer, char ***env);

#endif