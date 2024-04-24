/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:22:52 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:22:55 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*recup_oldpwd(char **str)
{
	char	*oldpwd;
	int		i;

	i = 0;
	oldpwd = NULL;
	while (str[i])
	{
		if (ft_strncmp(str[i], "OLDPWD=", 7) == 0)
		{
			oldpwd = ft_strdup3(str[i]);
			break ;
		}
		i++;
	}
	return (oldpwd);
}

int	recup_new_pwd_exp(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->cp_exp[i])
	{
		if (ft_strncmp(data->cp_exp[i], "PWD=", 4) == 0)
		{
			while (data->cp_exp[i][j] != '\0')
				j++;
			if (data->cp_exp[i][j] == '\0')
				break ;
		}
		i++;
	}
	while (data->cp_exp[i][j] != '/')
		j--;
	return (j);
}

int	recup_new_pwd_env(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->cp_env[i])
	{
		if (ft_strncmp(data->cp_env[i], "PWD=", 4) == 0)
		{
			while (data->cp_env[i][j] != '\0')
				j++;
			if (data->cp_env[i][j] == '\0')
				break ;
		}
		i++;
	}
	while (data->cp_env[i][j] != '/')
		j--;
	return (j);
}

char	*verif_pwd(char *line)
{
	char	*tmp;

	if (ft_strcmp(line, "PWD=") == 0)
		tmp = ft_strjoin(line, "/");
	else
		tmp = ft_strdup3(line);
	return (tmp);
}

char	*join_var(char *str1, char *new_val)
{
	char	*dest;
	char	*cpy;
	int		i;
	int		j;

	j = 0;
	cpy = malloc(sizeof(char) * (ft_strlen(new_val) + 1));
	i = 0;
	while (new_val[i] != '=')
		i++;
	i += 1;
	while (new_val[i])
		cpy[j++] = new_val[i++];
	cpy[j] = '\0';
	dest = ft_strjoin(str1, cpy);
	free(cpy);
	return (dest);
}
