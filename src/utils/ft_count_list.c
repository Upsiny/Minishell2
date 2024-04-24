/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:33:51 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:33:53 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_count_list(t_list *head)
{
	if (!head)
		return (0);
	else
		return (1 + ft_count_list(head->next));
}
