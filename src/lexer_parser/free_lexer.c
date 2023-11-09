/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:40 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/14 17:23:41 by tpaufert         ###   ########.fr       */
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
