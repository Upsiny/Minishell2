/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:33:43 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:33:45 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL && tab)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
