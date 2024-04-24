/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpytab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:34:00 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:34:02 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_cpytab(char **tab)
{
	int		size;
	int		i;
	char	**cpy;

	size = 0;
	i = 0;
	if (!tab)
		return (NULL);
	while (tab[size])
		size++;
	cpy = ft_calloc(sizeof(char *), (size + 1));
	if (!cpy)
		return (NULL);
	while (i < size)
	{
		cpy[i] = ft_strdup3(tab[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
