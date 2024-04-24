/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:33:34 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:33:36 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**build_cmd_from_lexer(t_data *data)
{
	char	**cmd;
	t_list	*el;
	int		args;
	int		idx;

	if (!(data->s_lex))
	{
		free_ptr(data->s_lex);
		return (NULL);
	}
	el = data->s_lex->next;
	idx = 0;
	while (el)
	{
		el = el->next;
		args++;
	}
	cmd = ft_calloc(sizeof(char *), args + 1);
	if (!cmd)
	{
		free(cmd);
		return (NULL);
	}
	el = data->s_lex->next;
	while (el)
	{
		cmd[idx] = el->content;
		el = el->next;
		idx++;
	}
	cmd[idx] = NULL;
	return (cmd);
}

char	*ft_strcat(char *dest, char *src)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (dest[size])
	{
		size++;
	}
	while (src[i])
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size + i] = '\0';
	return (dest);
}

char	**add_cmd_before_args(t_data *data, char **args)
{
	char	**res;
	int		idx;

	idx = 0;
	res = malloc(sizeof(char *) * (ft_tab_len(args) + 2));
	if (!res || !(data->s_lex))
	{
		free(res);
		return (NULL);
	}
	res[0] = data->s_lex->content;
	if (!args || !args[0])
	{
		res[1] = NULL;
		return (res);
	}
	while (args[idx])
	{
		res[idx + 1] = args[idx];
		idx++;
	}
	res[idx + 1] = NULL;
	return (res);
}

char	**ft_2d_strdup(char **src)
{
	char	**res;
	int		idx;

	if (!src)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_tab_len(src) + 1));
	if (!res)
	{
		free(res);
		return (NULL);
	}
	idx = 0;
	while (src[idx])
	{
		ft_strcpy(res[idx], src[idx]);
		idx++;
	}
	res[idx] = NULL;
	return (res);
}
