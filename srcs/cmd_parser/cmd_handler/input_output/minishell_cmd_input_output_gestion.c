/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_input_output_gestion.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:36:05 by gozsertt          #+#    #+#             */
/*   Updated: 2021/10/26 15:18:52 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_input_output_gestion(t_lexer *lexer, t_lexer *reader,
	t_cmd *cmd, t_list2 *cmd_list)
{
	if (is_cmd_pipe_case(lexer, &reader) == true && lexer->error == true)
	{
		cmd_input_gestion(lexer, reader, cmd);
		if (lexer->error == true)
		return (list2_push_back(cmd_list, cmd));
		cmd_output_gestion(lexer, reader, cmd);
	}
	else
	{
		cmd_input_gestion(lexer, NULL, cmd);
		if (lexer->error == true)
			return (list2_push_back(cmd_list, cmd));
		cmd_output_gestion(lexer, NULL, cmd);	
	}
}
