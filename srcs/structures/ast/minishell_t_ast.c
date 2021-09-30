/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_t_ast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:32:34 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/30 21:38:33 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*malloc_ast(char ***env)
{
	t_ast	*ast;

	ast = (t_ast *)malloc(sizeof(t_ast));
	if (ast == NULL)
		minishell_error("t_lexer can't be allocate");
	*ast = create_ast(env);
	return (ast);
}

	// int	*pipe;
	// char	*cmd;
	// char	**args;
	// char	*limiter;

t_ast	create_ast(char ***env)
{
	t_ast ast;

	ast.env = env;
	ast.fd = malloc_list2(10);
	ast.in_fd = 0;
	ast.out_fd = 1;
	ast.pipe = NULL;
	ast.cmd = NULL;
	ast.args = NULL;
	ast.limiter = NULL;
	return (ast);
}

void	destroy_ast(t_ast ast)
{
	//add t_list gestion
	if (ast.pipe != NULL)
		free(ast.pipe);
	if (ast.cmd != NULL)
		free(ast.cmd);
	if (ast.args != NULL)
	{
		ft_free_tab((void **)ast.args);
		free(ast.args);
	}
	if (ast.limiter != NULL)
		free(ast.limiter);
}

void	free_ast(t_ast *ast)
{
	destroy_ast(*ast);
	free(ast);
}
