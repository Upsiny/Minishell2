/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:26:47 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:26:49 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_nb_slash(char *str)
{
	int	i;
	int	slash;

	i = 0;
	slash = 0;
	while (str[i])
	{
		if (str[i] == '/')
			slash++;
		i++;
	}
	return (slash);
}
