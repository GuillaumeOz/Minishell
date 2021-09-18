/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:12:29 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/18 14:37:20 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//do simple and double quote manipulation //done 
//do more test later

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

void	parser(t_lexer *lexer)
{
	if (lexer == NULL)
		return ;
	lexer = set_first_lexer(lexer);
	quote_transformation(lexer);
}
