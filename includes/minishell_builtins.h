/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtins.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:49:30 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/08 17:58:13 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BUILTINS_H
# define MINISHELL_BUILTINS_H

# include "libft.h"

/*
** builtin cd
*/

int		builtin_cd(char ***env, char **args);

/*
** builtin echo
*/

int		print_echo(char **splited_line, t_bool n_flag);

/*
** builtin env
*/

int		print_env(char **env);

/*
** builtin exit
*/

void	builtin_exit(char **line, char **env);

/*
** builtin export
*/

int		export_without_argument(char **env);
char	**take_path(char **env);
int		set_env(char *name, char *value, char ***env);
int		find_var_env(char **env, char *find);

/*
** builtin pwd
*/

void	change_pwd(char ***env);
char	*get_pwd(void);
int		print_pwd(void);

/*
** builtin unset
*/

int		unset_env(char *name, char ***env);

#endif