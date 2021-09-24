/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parsing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:08:34 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/24 07:03:25 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSING_H
# define MINISHELL_PARSING_H

t_bool	previous_is_double_greater_checker(t_lexer *lexer);
t_bool	next_is_double_greater_checker(t_lexer *lexer);

t_bool	previous_is_double_lower_checker(t_lexer *lexer);
t_bool	next_is_double_lower_checker(t_lexer *lexer);

t_bool	previous_is_greater_checker(t_lexer *lexer);
t_bool	next_is_greater_checker(t_lexer *lexer);

t_bool	previous_is_lower_checker(t_lexer *lexer);
t_bool	next_is_lower_checker(t_lexer *lexer);

t_bool	previous_is_pipe_checker(t_lexer *lexer);
t_bool	next_is_pipe_checker(t_lexer *lexer);

t_bool	previous_is_null_checker(t_lexer *lexer);
t_bool	next_is_null_checker(t_lexer *lexer);

t_bool	args_error_handler(t_lexer *lexer);
t_bool	double_greater_error_handler(t_lexer *lexer);
t_bool	double_lower_error_handler(t_lexer *lexer);
t_bool	greater_error_handler(t_lexer *lexer);
t_bool	lower_error_handler(t_lexer *lexer);
t_bool	pipe_error_handler(t_lexer *lexer);

void	syntax_checker(t_lexer *lexer);

void	cmd_number_setter(t_lexer *lexer);

void	fork_setter(t_lexer *lexer);

void	compute_dollar(t_lexer *lexer, int *i);
void	dollar_transformation(t_lexer *lexer);

void	compute_simple_quote(t_lexer *lexer, int *i);
void	compute_double_quote(t_lexer *lexer, int *i);
void	simple_quote_transformation(t_lexer *lexer);
void	double_quote_transformation(t_lexer *lexer);
void	mix_quote_transformation(t_lexer *lexer);

void	quote_dollar_transformation(t_lexer *lexer);

void	parser(t_lexer *lexer);

#endif
