/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:04:53 by chdespon          #+#    #+#             */
/*   Updated: 2021/11/02 14:43:41 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _BLUE "\033[1;34m"
# define _WHITE "\033[0;37m"
# define _GREEN "\033[32m"
# define _YELLOW "\033[33m"
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

unsigned int	g_exit_code;

#endif
