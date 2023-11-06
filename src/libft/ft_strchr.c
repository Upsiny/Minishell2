/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:14:43 by tpaufert          #+#    #+#             */
/*   Updated: 2022/04/01 18:50:02 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	t;

	t = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == t)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == '\0' && t == '\0')
		return ((char *) &s[i]);
	return (NULL);
}
