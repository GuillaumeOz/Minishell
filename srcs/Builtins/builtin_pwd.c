/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:15:15 by chdespon          #+#    #+#             */
/*   Updated: 2021/09/23 16:16:33 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_pwd(char ***env, char *splited_line)
{
	// int		env_index;
	// int		i;
	// char	**tmp;

	// i = 0;
	// tmp = NULL;
	// env_index = find_var_env(*env, "PWD");
	(void)splited_line;
	(void)env;
	// if (ft_strcmp(splited_line, "..") == 0)
	// {
	// 	// tmp = ft_split(*env[env_index], '/');
	// 	while (tmp[i++])
	// 	ft_strjoin("/", tmp[i]);
	// 	ft_rm_charset(*env[env_index], tmp[i]);
	// 	ft_free_tab((void **)tmp);
	// }
}

char	*get_pwd(void)
{
	char	*buf;
	char	*mem;
	size_t	size;

	buf = NULL;
	mem = NULL;
	size = 16;
	while (buf == NULL)
	{
		free(mem);
		buf = malloc(sizeof(char) * (size));
		if (buf == NULL)
			return (NULL);
		mem = buf;
		buf = getcwd(buf, size);
		size += 16;
	}
	return (buf);
}

int	print_pwd(void)
{
	char	*pwd;

	pwd = get_pwd();
	ft_str_add_suffix(&pwd, "\n");
	ft_putstr_fd(1, pwd);
	free(pwd);
	return (EXIT_SUCCESS);
}
