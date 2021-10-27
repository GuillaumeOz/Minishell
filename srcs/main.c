/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:05:03 by chdespon          #+#    #+#             */
/*   Updated: 2021/10/27 18:42:28 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	**new_env;

	(void)argv;
	g_exit_code = 0;
	if (argc != 1)
		return (EXIT_FAILURE);
	new_env = alloc_env(env);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_sigint);
	prompt(&new_env);
	return (EXIT_SUCCESS);
}
