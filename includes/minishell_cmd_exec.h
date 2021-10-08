/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_exec.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:21:39 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/08 17:44:11 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_CMD_EXEC_H
# define MINISHELL_CMD_EXEC_H

// t_bool	is_builtin_case(t_lexer *lexer, t_lexer *limiter, t_lexer **reader);

t_bool	is_cmd_null_case(t_cmd *cmd);
t_bool	is_cmd_builtin_case(t_cmd *cmd);

int		find_var_env(char **env, char *find);

void	cmd_builder(t_cmd *cmd);

void	cmd_execution(t_lexer *lexer, t_list2 *cmd_list, pid_t *pid);

#endif