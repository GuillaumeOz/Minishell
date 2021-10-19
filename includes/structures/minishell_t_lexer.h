/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_t_lexer.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:50:00 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/13 10:56:05 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_T_LEXER_H
# define MINISHELL_T_LEXER_H

typedef enum e_token_type
{
	NONE,
	ARGS,
	space, //use this ? Maybe use undercase
	tab, //use this ? Maybe use undercase
	PIPE = '|',
	QUOTE = '\'',
	QUOTES = '\"',
	DOLLAR = '$',
	LOWER = '<',
	GREATER = '>',
	DOUBLE_LOWER,
	DOUBLE_GREATER,
}				t_token_type;

typedef enum e_token_format
{
	DEFAULT,
	SIMPLE_QUOTE,
	DOUBLE_QUOTE,
	MIX_QUOTE,
}				t_token_format;

typedef struct s_lexer
{
	t_token_type	type;
	t_token_format	format;
	t_bool			fork;
	t_bool			error;
	int				nb_cmd;
	char			*args;
	t_bool			over;
	char			***env;
	struct s_lexer	*previous;
	struct s_lexer	*next;
}					t_lexer;

t_lexer	*malloc_lexer(t_token_type type, t_token_format format);
t_lexer	create_lexer(t_token_type type, t_token_format format);
void	destroy_lexer(t_lexer to_destroy);
void	free_lexer(t_lexer *to_free);

t_lexer	*init_lexer(t_lexer *lexer, t_token_type type, t_token_format format);
t_lexer	*set_first_lexer(t_lexer *lexer);

#endif