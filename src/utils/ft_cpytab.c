/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpytab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:33:17 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/04 15:05:44 by tpaufert         ###   ########.fr       */
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
