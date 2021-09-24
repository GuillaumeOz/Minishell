/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_abstract_syntax_tree.h                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:09:39 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/24 07:16:17 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ABSTRACT_SYNTAX_TREE_H
# define MINISHELL_ABSTRACT_SYNTAX_TREE_H



t_bool	is_exec_double_greater_io_case(t_lexer *lexer,
			t_lexer *limiter, t_lexer **reader);
t_bool	is_exec_double_lower_io_case(t_lexer *lexer,
			t_lexer *limiter, t_lexer **reader);
t_bool	is_exec_greater_io_case(t_lexer *lexer,
			t_lexer *limiter, t_lexer **reader);
t_bool	is_exec_lower_io_case(t_lexer *lexer,
			t_lexer *limiter, t_lexer **reader);
t_bool	is_exec_case(t_lexer *lexer, t_lexer *limiter, t_lexer **reader);
void	cmd_ast(t_lexer *lexer,
			t_lexer *limiter, t_ast * ast, t_ast_option option);

t_bool	is_cmd_pipe_line_case(t_lexer *lexer, t_lexer **reader);
void	line_ast(t_lexer *lexer, pid_t *pid, t_ast_option option);

void	abstract_syntax_tree(t_lexer *lexer, char ***env);


#endif