/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtins.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:49:30 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/28 16:49:28 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BUILTINS_H
# define MINISHELL_BUILTINS_H

/*
** builtin cd
*/

int		builtin_cd(char ***env, char **args);

/*
** builtin echo
*/

int		print_echo(char **args, char ***env);

/*
** builtin env
*/

int		print_env(char **env);

/*
** builtin exit
*/

void	builtin_exit(char **line, char **env,
			t_lexer *lexer, t_list2 *cmd_list);

/*
** builtin export
*/

int		export_without_argument(char **env);
char	**take_path(char **env);
int		set_env(char *name, char *value, char ***env);
int		find_var_env(char **env, char *find);
void	ft_swap(char **x, char **y);
int		builtin_export(char **args, char ***env);
int		error_message(char *name, char *builtin);

/*
** builtin pwd
*/

void	change_pwd(char ***env);
char	*get_pwd(void);
int		print_pwd(char ***env);

/*
** builtin unset
*/

int		unset_env(char *name, char ***env);
int		builtin_unset(char **args, char ***env);

#endif