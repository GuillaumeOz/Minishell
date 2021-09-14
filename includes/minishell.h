/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:04:53 by chdespon          #+#    #+#             */
/*   Updated: 2021/09/14 17:58:02 by gozsertt         ###   ########.fr       */
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
# include "minishell_signals.h"
# include "minishell_prompt.h"
# include "minishell_lexer.h"

#endif
