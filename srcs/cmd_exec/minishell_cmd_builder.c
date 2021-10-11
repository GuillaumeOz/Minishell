/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_builder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:28:05 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/11 18:33:43 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	launch_fork(char **splited_line, char **env, char *path)//suppr this ?
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
		// Error forking
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		// Child process
		if (execve(path, splited_line, env) == -1)
			exit(EXIT_FAILURE);
	}
	else
	{
		// Parent process
		waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			waitpid(pid, &status, WUNTRACED);
	}
}

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

char	*find_cmd(char **env, char *param)
{
	char	**path;
	char	*cmd;
	int		i;

	i = 0;
	path = take_path(env);
	cmd = param;
	while (path && path[i])
	{
		ft_str_add_suffix(&(path[i]), "/");
		ft_str_add_suffix(&(path[i]), param);
		cmd = ft_strdup(path[i]);
		if (open(cmd, O_RDONLY) > 0)
		{
			ft_free_tab((void **)path);
			path = NULL;
			return (cmd);
		}
		free(cmd);
		cmd = NULL;
		i++;
	}
	if (path != NULL)
		ft_free_tab((void **)path);
	return (NULL);
}

void	cmd_builder(t_cmd *cmd)
{
	char *tmp;

	tmp = NULL;
	if (is_cmd_builtin_case(cmd) == true)
		return ;
	tmp = find_cmd(*(cmd->env), cmd->cmd);
	if (tmp == NULL)
		minishell_command_error(cmd, cmd->cmd);
	else
		cmd->cmd = tmp;
}
