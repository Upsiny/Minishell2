/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:38:32 by tpaufert          #+#    #+#             */
/*   Updated: 2022/04/01 18:21:30 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_tabs(const char *s, char c)
{
	int		i;
	int		tabs;

	i = 0;
	tabs = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			tabs++;
		i++;
	}
	return (tabs);
}

static int	word_len(const char *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void	*freememory(char **tableau, int tabs)
{
	int	i;

	i = 0;
	while (i < tabs)
	{
		free(tableau[i]);
		i++;
	}
	free(tableau);
	return (NULL);
}

static char	**creat_new_tab(const char *s, int tabs, char c, char **newtab)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (++i < tabs)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		newtab[i] = ft_calloc(sizeof(char), (len + 1));
		if (!newtab[i])
			return (freememory(newtab, i));
		j = 0;
		while (j < len)
			newtab[i][j++] = *s++;
		newtab[i][j] = '\0';
	}
	newtab[i] = NULL;
	return (newtab);
}

char	**ft_split(const char *s, char c)
{
	char	**newtab;
	int		tabs;

	if (!s)
		return (NULL);
	tabs = count_tabs(s, c);
	newtab = ft_calloc(sizeof(char *), (tabs + 1));
	if (!newtab)
		return (NULL);
	newtab = creat_new_tab(s, tabs, c, newtab);
	return (newtab);
}
