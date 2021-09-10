/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:05:03 by chdespon          #+#    #+#             */
/*   Updated: 2021/09/10 17:11:22 by chdespon         ###   ########.fr       */
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
				// parse_line(line, env, 0);
				add_history(line);
			}
			if (line == NULL)
				break ;
			free(line);
		}
	}
	free(line);
}

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar('\n');
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	main(int ac, char **av, char **env)
{
	char	**new_env;

	(void)av;
	if (ac != 1)
		return (0);
	new_env = alloc_env(env);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_sigint);
	prompt(new_env);
	ft_free_tab((void **)new_env);
	ft_putstr("exit\n");
	return (0);
}
