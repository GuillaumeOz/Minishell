/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_t_lexer.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:50:00 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/14 20:08:49 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_T_LEXER_H
# define MINISHELL_T_LEXER_H

typedef enum e_type
{
	TYPE_SPACE,
	TYPE_PIPE,
	TYPE_PIPE,

	
};

typedef enum e_format
{
	FORMAT_DEFAULT,
	FORMAT_SIMPLE_QUOTE,
	FORMAT_DOUBLE_QUOTE,
};

typedef struct s_lexer
{
	enum e_type		type;
	enum e_format	format;

	struct s_lexer	*previous;
	struct s_lexer	*next;
}				t_lexer;

#endif