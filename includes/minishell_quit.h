/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_quit.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 00:21:50 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/20 11:50:21 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_QUIT_H
# define MINISHELL_QUIT_H

void	quit(char **env, t_bool print_exit, t_lexer *lexer);
void	quit_execve(t_cmd *cmd, t_lexer *lexer);
void	quit_builtin(t_cmd *cmd, t_lexer *lexer);

#endif