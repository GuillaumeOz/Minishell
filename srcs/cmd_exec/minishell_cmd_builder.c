/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_builder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:55:48 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/08 17:59:06 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	launch_fork(char **splited_line, char **env, char *path)
// {
// 	pid_t	pid;
// 	int		status;

// 	status = 0;
// 	pid = fork();
// 	if (pid < 0)
// 		// Error forking
// 		exit(EXIT_FAILURE);
// 	else if (pid == 0)
// 	{
// 		// Child process
// 		if (execve(path, splited_line, env) == -1)
// 			exit(EXIT_FAILURE);
// 	}
// 	else
// 	{
// 		// Parent process
// 		waitpid(pid, &status, WUNTRACED);
// 		while (!WIFEXITED(status) && !WIFSIGNALED(status))
// 			waitpid(pid, &status, WUNTRACED);
// 	}
// }

char	**take_path(char **env)
{
	int		env_index;
	char	**path;
	char	*raw_path;

	env_index = find_var_env(env, "PATH");
	raw_path = NULL;
	path = NULL;
	if (env_index != -1)
	{
		raw_path = env[env_index] + 5;
		path = ft_split(raw_path, ':');
	}
	return (path);
}

	// char	**path;
	// char	*tmp_cmd;
	// int		i;

	// i = 0;
	// path = take_path((*cmd->env));
	// tmp_cmd = cmd->cmd;
	// while (path && path[i])
	// {
	// 	ft_str_add_suffix(&(path[i]), "/");
	// 	ft_str_add_suffix(&(path[i]), cmd->cmd);
	// 	tmp_cmd = ft_strdup(path[i]);
	// 	if (open(tmp_cmd, O_RDONLY) > 0)
	// 	{
	// 		ft_free_tab((void **)path);
	// 		path = NULL;
	// 		return (tmp_cmd);
	// 	}
	// 	free(tmp_cmd);
	// 	tmp_cmd = NULL;
	// 	i++;
	// }
	// ft_putstr_fd(2, cmd->cmd);
	// ft_putstr_fd(2, ": command not found\n");
	// if (path != NULL)
	// 	ft_free_tab((void **)path);
	// g_exit_code = 127;
	// return (NULL);

// char	*find_cmd(char **env, char *param)
void	cmd_builder(t_cmd *cmd)
{
	if (is_cmd_builtin_case(cmd) == true)
		return ;
	
}
