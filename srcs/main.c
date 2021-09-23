/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:05:03 by chdespon          #+#    #+#             */
/*   Updated: 2021/09/22 14:58:44 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char **new_env;

	(void)argv;
	if (argc != 1)
		return (EXIT_FAILURE);
	new_env = alloc_env(env);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_sigint);
	prompt(&new_env);
	return (EXIT_SUCCESS);
}
