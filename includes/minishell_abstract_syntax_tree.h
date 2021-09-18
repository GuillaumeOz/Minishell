/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_abstract_syntax_tree.h                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:09:39 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/18 22:20:02 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ABSTRACT_SYNTAX_TREE_H
# define MINISHELL_ABSTRACT_SYNTAX_TREE_H


void	cmd_ast(t_lexer *lexer, t_ast_option option);
// void    line();
// void    line_pipe();

void    line_ast(t_lexer *lexer, t_ast_option option);

void	abstract_syntax_tree(t_lexer *lexer);


#endif