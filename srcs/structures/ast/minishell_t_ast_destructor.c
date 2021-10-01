/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_t_ast_destructor.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 20:57:36 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/01 21:34:58 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_fd_list_ast(void *to_destroy)
{
	int *fd;

	fd = (int *)(to_destroy);
	close(*fd);
	free(to_destroy);
}

void	destroy_ast(t_ast ast)
{
	free_list2(ast.in_fd, free);// case when there are no in out fd
	free_list2(ast.out_fd, free);
	if (ast.pipe != NULL)
		free(ast.pipe);
	if (ast.cmd != NULL)
		free(ast.cmd);
	if (ast.args != NULL)
		ft_free_tab((void **)ast.args);
}
typedef void	(*t_list2_destroy_funct)(void *to_destroy);

void	free_ast(t_ast *ast)
{
	destroy_ast(*ast);
	free(ast);
}
