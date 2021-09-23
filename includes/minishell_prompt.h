/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdespon <chdespon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:08:39 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/22 15:01:18 by chdespon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PROMPT_H
# define MINISHELL_PROMPT_H

char	**alloc_env(char **env);
void	prompt(char ***env);

#endif