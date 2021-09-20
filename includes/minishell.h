/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:04:53 by chdespon          #+#    #+#             */
/*   Updated: 2021/09/20 12:36:11 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _BLUE "\033[1;34m"
# define _WHITE "\033[0;37m"
# define _GREEN "\033[32m"
# define _PURPLE "\033[1;35m"
# define _RED "\033[1;31m"

# include <limits.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "libft.h"
# include "minishell_t_lexer.h"
# include "minishell_quit.h"
# include "minishell_error.h"
# include "minishell_signals.h"
# include "minishell_prompt.h"
# include "minishell_tokenizer.h"
# include "minishell_parsing.h"

#define debug		write(1, "ICI\n", 4);
#define info		printf("line -> %d, fonction -> %s\n", __LINE__, __func__);
#define PRINTD(x)	printf("%d\n", x);
#define PRINTC(x)	printf("%c\n", x);
#define PRINTS(x)	printf("%s\n", x);

int		return_val;

void	pipe_fork(char **env, char *line);
void	fork_minishell(char **env, char *line);
void	parse_line(char *line, char **env, int pipe);
void	launch_fork(char **splited_line, char **env, char *path);
char	**take_path(char **env);
char	*find_cmd(char **env, char *param);
int		set_env(const char *name, const char *value, char ***env);
int		find_var_env(char **env, char *find);
int		unset_env(char *name, char ***env);
void	print_env(char **env);
void	change_pwd(char ***env, char *splited_line);
char	*get_pwd(void);
void	print_pwd(void);
int		print_echo(char **splited_line, t_bool n_flag);
void	quit(char **env, t_bool print_exit);
void	builtin_exit(char **line, char **env);

int		g_exit_code;// its usefull ?

#endif
