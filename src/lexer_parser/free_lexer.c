/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:30:29 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:30:31 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_lst(t_data *data)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = data->s_lex;
	if (!tmp)
		return ;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
}
/*
//fonction to free a lst
void ft_free_lst(t_data *data)
{
	t_list	*tmp;

	while (data)
	{
		tmp = data->next;
		data->next = NULL;
		free(data);
		data = tmp;
	}
}*/
