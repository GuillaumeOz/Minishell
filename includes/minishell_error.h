/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_error.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:06:17 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/08 19:41:35 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ERROR_H
# define MINISHELL_ERROR_H

void	set_lexer_fork_error(t_lexer *lexer, t_lexer *limiter);

void	minishell_fork_greater_fd_error(t_lexer *lexer,
			t_lexer *limiter, char *token);//suppr
void	minishell_fork_lower_fd_error(t_lexer *lexer,
			t_lexer *limiter, char *token);//suppr

void	set_lexer_error(t_lexer *lexer);

void	minishell_command_error(t_cmd *cmd, char *token);
void	minishell_multiline_error(t_lexer *lexer, char *token);
void	minishell_syntax_error(t_lexer *lexer, char *token);
void	minishell_error(char *error_msg);

#endif