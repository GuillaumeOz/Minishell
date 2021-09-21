/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parsing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:08:34 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/21 17:19:38 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSING_H
# define MINISHELL_PARSING_H

t_bool	previous_is_null_checker(t_lexer *lexer);
t_bool	next_is_null_checker(t_lexer *lexer);

t_bool	previous_is_double_lower(t_lexer *lexer);
t_bool	next_is_double_lower(t_lexer *lexer);

void	compute_dollar(t_lexer *lexer, int *i);
void    dollar_transformation(t_lexer *lexer);

void    compute_simple_quote(t_lexer *lexer, int *i);
void    compute_double_quote(t_lexer *lexer, int *i);
void	simple_quote_transformation(t_lexer *lexer);
void	double_quote_transformation(t_lexer *lexer);
void	mix_quote_transformation(t_lexer *lexer);

void	quote_dollar_transformation(t_lexer *lexer);

void	parser(t_lexer *lexer);

#endif
