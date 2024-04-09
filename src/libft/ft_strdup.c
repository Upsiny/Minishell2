/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:32:33 by tpaufert          #+#    #+#             */
/*   Updated: 2024/04/05 15:45:45 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup3(char *src)
{
	char	*copy;
	int		size;

	size = ft_strlen(src);
	copy = ft_calloc(sizeof(char), (size + 1));
	if (!copy)
	{
		free(copy);
		return (NULL);
	}
	ft_strcpy(copy, src);
	return (copy);
}
