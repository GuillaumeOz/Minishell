/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tokenizer.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:05:05 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/07 17:38:10 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TOKENIZER_H
# define MINISHELL_TOKENIZER_H

t_lexer	*args_token(t_lexer *lexer, char *line, int *i);
t_lexer	*greater_token(t_lexer *lexer, char *line, int *i);
t_lexer	*lower_token(t_lexer *lexer, char *line, int *i);
t_lexer	*pipe_token(t_lexer *lexer, int *i);

void	white_space_token(char *line, int *i);

t_lexer	*tokenizer(char *line);

#endif