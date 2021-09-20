/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parsing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:08:34 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/20 12:24:48 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSING_H
# define MINISHELL_PARSING_H

void	compute_simple_quote(t_lexer *lexer, int *i);
void	compute_double_quote(t_lexer *lexer, int *i);
void	simple_quote_transformation(t_lexer *lexer);
void	double_quote_transformation(t_lexer *lexer);
void	mix_quote_transformation(t_lexer *lexer);
void	quote_transformation(t_lexer *lexer);

void	parser(t_lexer *lexer);

#endif
