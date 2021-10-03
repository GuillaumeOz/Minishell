/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_t_cmd.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:15:51 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/03 19:31:17 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_T_CMD_H
# define MINISHELL_T_CMD_H

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

typedef struct s_cmd
{
	char	***env;
	t_list2	*in_fd;
	t_list2	*out_fd;
	int		*pipe;
	t_bool	here_doc;
	int		here_doc_pipe[2];
	char	*cmd;
	char	**args;
	char	**limiter;
}				t_cmd;

t_cmd	*malloc_cmd(char ***env);
t_cmd	create_cmd(char ***env);
void	destroy_fd_list_cmd(void *to_destroy);
void	destroy_cmd(t_cmd cmd);
void	free_cmd(t_cmd *ast);

#endif