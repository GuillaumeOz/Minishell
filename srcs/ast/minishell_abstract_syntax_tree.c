/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_abstract_syntax_tree.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:24:18 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/18 22:48:52 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	do simple and double quote manipulation //done 
//	do more test later

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

void	abstract_syntax_tree(t_lexer *lexer)
{
    t_ast   ast;

	(void)ast;
	lexer = set_first_lexer(lexer);
	line_ast(lexer, LINE_OPTION_1);
}
