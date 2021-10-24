/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_exec.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:21:39 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/24 22:08:25 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_CMD_EXEC_H
# define MINISHELL_CMD_EXEC_H

t_bool	is_cmd_null_case(t_cmd *cmd);
t_bool	is_here_doc_case(t_cmd *cmd);
t_bool	is_cmd_builtin_case(t_cmd *cmd);

void	run_multiple_cmd(t_cmd *cmd, t_lexer *lexer);

void	run_single_cmd(t_cmd *cmd, t_lexer *lexer);

void	cmd_out_fork_executer(t_cmd *cmd, t_lexer *lexer);
void	cmd_executer(t_cmd *cmd, t_lexer *lexer);

t_bool	is_cmd_null_case(t_cmd *cmd);
t_bool	is_cmd_builtin_case(t_cmd *cmd);

char	*find_cmd(char **env, char *param);

void	cmd_builder(t_cmd *cmd);
void	cmd_builtin_executer(t_cmd *cmd, t_lexer *lexer);

void	cmd_execution(t_lexer *lexer, t_list2 *cmd_list, pid_t *pid);

#endif