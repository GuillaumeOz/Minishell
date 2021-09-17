/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:05:03 by chdespon          #+#    #+#             */
/*   Updated: 2021/09/16 15:04:11 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char **new_env;

	(void)argv;
	if (argc != 1)
		return (0);
	new_env = alloc_env(env);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_sigint);
	prompt(new_env);
	ft_free_tab((void **)new_env);
	ft_putstr("exit\n");
	return (0);
}
