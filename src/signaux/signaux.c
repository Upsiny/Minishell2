/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:33:03 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:33:06 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

void	rl_replace_line(const char *text, int clear_undo);

void	ft_ctrl_c(int sig)
{
	if (sig == 2)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	return ;
}

void	ft_ctrl_back(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_signaux(void)
{
	signal(SIGINT, ft_ctrl_c);
	signal(SIGQUIT, ft_ctrl_back);
}
