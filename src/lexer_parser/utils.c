/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:05:13 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/04 18:43:27 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
char	*search_in_env(t_data *data, char *str)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = NULL;
	while (data->cp_env[i])
	{
		if (ft_strncmp(data->cp_env[i], str, ft_strlen(str)) == 0)
		{
			cpy = ft_strdup3(data->cp_env[i] + ft_strlen(str) + 1);
			if (!cpy)
				return (NULL);
			break ;
		}
		i++;
	}
	return (cpy);
}
*/

int	contains_env_vars(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

char	*append(char before, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (before)
	{
		ft_memmove(str + 1, str, ++len);
		*str = before;
	}
	return (str);
}

char	*search_in_env(t_data *shell, char *var)
{
	int		idx;
	char	**split;
	char	*res;

	idx = 0;
	while (shell->cp_env[idx])
	{
		split = ft_split(shell->cp_env[idx], '=');
		if (!ft_strcmp(split[0], var))
		{
			res = ft_strdup3(split[1]);
			free_2d_arr(split);
			free(var);
			return (res);
		}
		free_2d_arr(split);
		idx++;
	}
	/*if (to_append)
		return (append('$', var));
	else*/
	return (var);
}

//char	*search_in_env(t_data *data, char *str)
//{
//
//	int		i;
//	char	**env;
//
//	i = 0;
//	env = data->cp_env;
//	for (int j = 0; env[j]; j++)
//		printf("%s\n", env[j]);
//
//	printf("%s\n", str);
//	while (env[i] && ft_strncmp(env[i], str, ft_strlen(str)))
//		i++;
//	printf("%s\n", env[i]);
//	return ("");
//}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f'
		|| c == ' ')
		return (0);
	return (1);
}

void	print_list(t_data *data)
{
	printf("lexer result : \n");
	while (data->s_lex)
	{
		if (data->s_lex->content)
		{
			printf("index : %d | ", data->s_lex->index);
			printf("token type : %d | ", data->s_lex->token_type);
			printf("len : (%zu) | ", ft_strlen(data->s_lex->content));
			printf("content : %s\n", data->s_lex->content);
		}
		else
			printf("NULL\n");
		data->s_lex = data->s_lex->next;
	}
}
