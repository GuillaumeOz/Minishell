/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_builder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:28:05 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/13 14:00:23 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		return ;//add builtin gestion here
	tmp = find_cmd(*(cmd->env), cmd->cmd);
	if (tmp == NULL)
		minishell_command_error(cmd, cmd->cmd);
	else
	{
		free(cmd->cmd);
		cmd->cmd = tmp;
	}
}


	// else if (ft_strcmp(cmd[0], "echo") == 0)
	// {
	// 	if (cmd[1] != NULL && ft_strcmp(cmd[1], "-n") == 0)
	// 		g_exit_code = print_echo(cmd, true);
	// 	else
	// 		g_exit_code = print_echo(cmd, false);
	// }
	// else if (ft_strcmp(cmd[0], "cd") == 0)
	// 	g_exit_code = builtin_cd(env, cmd);
	// else if (ft_strcmp(cmd[0], "env") == 0
	// 	&& cmd[1] == NULL)
	// 	g_exit_code = print_env(*env);
	// else if (ft_strcmp(cmd[0], "pwd") == 0
	// 	&& cmd[1] == NULL)
	// 	g_exit_code = print_pwd();
	// else if (ft_strcmp(cmd[0], "unset") == 0
	// 	&& cmd[1] != NULL)
	// 	g_exit_code = unset_env(cmd[1], env);
	// else if (ft_strcmp(cmd[0], "export") == 0
	// 	&& cmd[1] != NULL)
	// 		g_exit_code = set_env(cmd[1] , NULL, env);
	// else if (ft_strcmp(cmd[0], "export") == 0 && cmd[1] == NULL)
	// 	g_exit_code = export_without_argument(*env);