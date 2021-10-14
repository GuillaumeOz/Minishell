/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:04:53 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/14 13:03:14 by chdespon         ###   ########.fr       */
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
# include <errno.h>
# include "libft.h"
# include "minishell_t_lexer.h"
# include "minishell_t_cmd.h"
# include "minishell_quit.h"
# include "minishell_error.h"
# include "minishell_signals.h"
# include "minishell_prompt.h"
# include "minishell_tokenizer.h"
# include "minishell_parsing.h"
# include "minishell_cmd_parser.h"
# include "minishell_cmd_exec.h"
# include "minishell_builtins.h"

#define debug		write(2, "ICI\n", 4);
#define info		printf("line -> %d, fonction -> %s\n", __LINE__, __func__);
#define PRINTD(x)	fprintf(stderr, "%d\n", x);
#define PRINTC(x)	fprintf(stderr, "%c\n", x);
#define PRINTS(x)	fprintf(stderr, "%s\n", x);
#define PRINTP(x)	fprintf(stderr, "%p\n", x);

// void	pipe_fork(char **env, char *line);
// void	fork_minishell(char **env, char *line);
// void	parse_line(char *line, char ***env, int pipe);

int		g_exit_code;

#endif
