/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_t_ast.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:15:51 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/18 21:39:28 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_T_AST_H
# define MINISHELL_T_AST_H

	// int		cmd_nb;
	// int		pipe_nb;
	// int		path_nb;
	// char	**env;
	// char	***args;
	// char	**cmds;
	// pid_t	*child;
	// int		**pipe;
	// int		fd_file1;
	// int		fd_file2;
	// bool	here_doc;
	// int		here_doc_pipe[2];
	// char	*limiter;

typedef enum e_ast_option
{
	ERROR,//its usefull ?
	LINE_OPTION_1,
	LINE_OPTION_2,

	CMD_OPTION_1,

}				t_ast_option;

typedef struct s_ast
{
	int		*pipe;
	char	*cmd;
	char	**args;
	char	*limiter;
}				t_ast;

t_ast	*malloc_ast(void);
t_ast	create_ast(void);
void	destroy_ast(t_ast ast);
void	free_ast(t_ast *ast);

#endif