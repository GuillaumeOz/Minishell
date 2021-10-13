/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_t_cmd.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:15:51 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/13 14:40:16 by gozsertt         ###   ########.fr       */
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

typedef enum e_cmd_position
{
	NO_POSITION,
	FIRST_POSITION,
	MIDDLE_POSITION,
	LAST_POSITION,
}				t_cmd_postion;

typedef struct s_cmd
{
	t_cmd_postion		pos;
	char				***env;
	t_list2				*in_fd;
	t_list2				*out_fd;
	int					cmd_stdin;
	int					cmd_stdout;
	int					*pipe;
	int					*previous_pipe;
	t_bool				here_doc;
	int					*here_doc_pipe;
	char				**limiter;
	char				*cmd;
	char				**args;
	t_bool				error;
}				t_cmd;

t_cmd	*malloc_cmd(char ***env, t_cmd_postion pos);
t_cmd	create_cmd(char ***env, t_cmd_postion pos);
void	destroy_fd_list_cmd(void *to_destroy);
void	destroy_cmd(t_cmd cmd);
void	free_cmd(void *cmd);

void	cmd_pipe_setter(t_lexer *lexer,t_list2 *cmd_list);
void	cmd_pos_setter(t_lexer *lexer,t_list2 *cmd_list);

#endif