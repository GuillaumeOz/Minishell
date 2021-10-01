/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_t_ast_constructor.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 20:57:07 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/01 21:01:14 by gozsertt         ###   ########.fr       */
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

static void create_in_out_file_ast(t_ast *ast)
{
	int	*in_std;
	int	*out_std;

	in_std = (int *)malloc(sizeof(int));
	out_std = (int *)malloc(sizeof(int));
	if (in_std == NULL || out_std == NULL)
		minishell_error("int * cannot be allocated");
	*in_std = 0;
	*out_std = 1;
	ast->in_fd = malloc_list2(10);
	list2_push_back(ast->in_fd, in_std);
	ast->out_fd = malloc_list2(10);
	list2_push_back(ast->out_fd, out_std);
}

t_ast	create_ast(char ***env)
{
	t_ast	ast;

	ast.env = env;
	create_in_out_file_ast(&ast);
	ast.here_doc = false;
	ast.pipe = NULL;
	ast.cmd = NULL;
	ast.args = NULL;
	ast.limiter = NULL;
	return (ast);
}
