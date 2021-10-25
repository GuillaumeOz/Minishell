/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_double_lower_io_case.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:28:50 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/25 12:07:21 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_double_lower_io_case(t_cmd *cmd, t_lexer *lexer,
	t_lexer *limiter, t_lexer **reader)
{
	char	*to_add;
	char	heading[1];

	cmd->here_doc = true;
	heading[0] = 1;
	if (cmd->limiter == NULL)
	{
		cmd->limiter = (char **)ft_tab_new(1);
		to_add = ft_strdup((*reader)->args);
		if ((*reader)->here_doc_exp == true)
			ft_str_add_prefixe(heading, &to_add);
		ft_add_to_tab(to_add, (void ***)&(cmd->limiter));
	}
	else
	{
		to_add = ft_strdup((*reader)->args);
		if ((*reader)->here_doc_exp == true)
			ft_str_add_prefixe(heading, &to_add);
		ft_add_to_tab(to_add, (void ***)&(cmd->limiter));
	}
	cmd_limiter_handler(lexer, limiter, cmd);
}
