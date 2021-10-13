/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtins.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:49:30 by chdespon          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/10/13 14:18:57 by gozsertt         ###   ########.fr       */
=======
/*   Updated: 2021/10/13 14:16:15 by chdespon         ###   ########.fr       */
>>>>>>> e1a883084f303a51426be2bf7b4fec914f5d406e
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

int		print_echo(char **splited_line, t_bool n_flag, char ***env);

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
void	ft_swap(char **x, char **y);
int		builtin_export(char **args, char ***env);


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
int		builtin_unset(char **args, char ***env);

#endif