/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:12:29 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/17 00:10:38 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	line ::== cmd | line
//		 ::== cmd
//
//	cmd	 ::== exec >> io		io	::== file >> file
//		 ::== exec << io			::== file > file
//		 ::== exec < io				::== file
//		 ::== exec > io				add file << file case ??
//		 ::== exec
//
//	exec ::== execname + args	args ::== arg + args
//		 ::== execname				 ::== arg

//do simple and double quote manipulation

void	parser(t_lexer *lexer)
{
	if (lexer == NULL)
		return ;
	lexer = set_first_lexer(lexer);
	quote_transformation(lexer);
}
