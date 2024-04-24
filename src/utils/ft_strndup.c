/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:34:17 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:34:21 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t		len;
	const char	*ptr;
	char		*dup;
	size_t		i;

	i = 0;
	len = 0;
	ptr = src;
	dup = NULL;
	while (*ptr && len < n)
	{
		ptr++;
		len++;
	}
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	ptr = src;
	while (*ptr && i < len)
	{
		dup[i++] = *ptr;
		ptr++;
	}
	dup[i] = '\0';
	return (dup);
}
