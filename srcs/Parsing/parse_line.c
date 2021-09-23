/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:12:52 by chdespon          #+#    #+#             */
/*   Updated: 2021/09/23 15:54:24 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parse_splited_line(char **splited_line, char ***env, int pipe)
{
	char	*cmd;
	if (splited_line[0] == NULL)
		return ;
	else if (ft_strcmp(splited_line[0], "echo") == 0)
	{
		if (splited_line[1] != NULL && ft_strcmp(splited_line[1], "-n") == 0)
			return_val = print_echo(splited_line, true);
		else
			return_val = print_echo(splited_line, false);
	}
	else if (ft_strcmp(splited_line[0], "cd") == 0)
	{
		if (splited_line[2] != NULL)
		{
			return_val = 1;
			ft_putstr("cd: trop d'arguments\n");
			return ;
		}
		else if (chdir(splited_line[1]) != 0)
			printf("cd: %s: Aucun fichier ou dossier de ce type\n",
				splited_line[1]);
		change_pwd(env, splited_line[1]);
	}
	else if (ft_strcmp(splited_line[0], "env") == 0
		&& splited_line[1] == NULL)
		return_val = print_env(*env);
	else if (ft_strcmp(splited_line[0], "pwd") == 0
		&& splited_line[1] == NULL)
		print_pwd();
	else if (ft_strcmp(splited_line[0], "unset") == 0
		&& splited_line[1] != NULL)
		return_val = unset_env(splited_line[1], env);
	else if (ft_strcmp(splited_line[0], "export") == 0
		&& splited_line[1] != NULL)
			return_val = set_env(splited_line[1] , ft_strdup(""), env);
	else if (ft_strcmp(splited_line[0], "export") == 0 && splited_line[1] == NULL)
		return_val = export_whiout_argument(*env);
	else
	{
		cmd = find_cmd(*env, splited_line[0]);
		if (pipe == 1)
		{
			if (execve(cmd, splited_line, *env) == -1)
				exit(EXIT_FAILURE);
		}
		else
			launch_fork(splited_line, *env, cmd);
		free(cmd);
		cmd = NULL;
	}
}

void	pipe_fork(char **env, char *line)
{
	int		pipefd[2];
	pid_t	cpid;
	char	**splited_line;
	int		status;

	status = 0;
	splited_line = ft_split(line, '|');
	// (void)env;
	// if (ft_tab_len((void **)line) != 2)
	// {
	// 	fprintf(stderr, "Usage: %s <string>\n", line[0]);
	// 	exit(EXIT_FAILURE);
	// }
	if (pipe(pipefd) == -1)
		exit(EXIT_FAILURE);
	cpid = fork();
	if (cpid == -1)
		exit(EXIT_FAILURE);
	if (cpid == 0)
	{	/* Child reads from pipe */
		close(pipefd[1]);		/* Close unused write end */
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		parse_line(splited_line[1], &env, 1);
	}
	else
	{	/* Parent writes first command to pipe */
		close(pipefd[0]);			/* Close unused read end */
		dup2(pipefd[1], 1);
		close(pipefd[1]);			/* Reader will see EOF */
		parse_line(splited_line[0], &env, 1);
		waitpid(cpid, &status, 0);
	}
}

void	fork_minishell(char **env, char *line)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	else if (pid == 0)
		pipe_fork(env, line);
	else
	{
		waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			waitpid(pid, &status, WUNTRACED);
	}
}

void	parse_line(char *line, char ***env, int pipe)
{
	char	**splited_line;
	int		i;

	splited_line = ft_split(line, ' ');
	if (line != NULL && ft_strcmp(splited_line[0], "exit") == 0)
	{
		builtin_exit(splited_line + 1, *env);
		return ;
	}
	i = 0;
	while (splited_line[i] != NULL)
	{
		if (ft_strcmp(splited_line[i], "|") == 0 && splited_line[i + 1] != NULL)
		{
			fork_minishell(*env, line);
			ft_free_tab((void **)splited_line);
			return ;
		}
		i++;
	}
	parse_splited_line(splited_line, env, pipe);
	ft_free_tab((void **)splited_line);
}
