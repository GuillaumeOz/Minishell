/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:05:03 by chdespon          #+#    #+#             */
/*   Updated: 2021/09/14 17:51:00 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**alloc_env(char **env)
{
	char	**dest;
	int		i;

	dest = (char **)ft_tab_new(ft_tab_len((void **)env));
	i = 0;
	while (env[i])
	{
		dest[i] = ft_strdup(env[i]);
		i++;
	}
	return (dest);
}

void	quit(int i, char **env)
{
	ft_free_tab((void **)env);
	ft_putstr("exit\n");
	rl_clear_history();
	exit(i);
}

void	prompt(char **env)
{
	char	*line;

	while (1)
	{
		line = readline(_BLUE"("_RED"Minishell" _BLUE") "_GREEN"➜"_WHITE" ");
		{
			if (line != NULL && ft_strcmp(line, "\n") > 0
				&& ft_str_is_only_whitespaces(line) == 0)
			{
				parse_line(line, env, 0);
				add_history(line);
			}
			if (line == NULL)
				break ;
			free(line);
		}
	}
	free(line);
	quit(val_ret, env);
}

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar('\n');
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		val_ret = 130;
	}
}

int	main(int ac, char **av, char **env)
{
	char	**new_env;

	(void)av;
	if (ac != 1 && av[1] == NULL)
		return (EXIT_FAILURE);
	new_env = alloc_env(env);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_sigint);
	prompt(new_env);
	return (EXIT_SUCCESS);
}
