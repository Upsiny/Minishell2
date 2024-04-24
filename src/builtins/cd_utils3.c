/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:23:11 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:23:13 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	change_value_oldpwd(t_data *data, int exp)
{
	char	*name_var;
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (data->oldpwd[y] != '=')
		y++;
	name_var = malloc(sizeof(char) * (y + 2));
	while (i <= y)
	{
		name_var[i] = data->oldpwd[i];
		i++;
	}
	name_var[i] = '\0';
	if (exp)
		cpy_value(name_var, data->cp_exp, data->pwd);
	else
		cpy_value(name_var, data->cp_env, data->pwd);
	free(name_var);
}

void	change_value_pwd_exp(t_data *data)
{
	char	*new_val;
	int		i;
	int		j;
	int		w;

	i = 0;
	j = 0;
	w = 0;
	while (data->cp_exp[i])
	{
		if (ft_strncmp(data->cp_exp[i], "PWD=", 4) == 0)
			break ;
		i++;
	}
	j = recup_new_pwd_exp(data);
	new_val = malloc(sizeof(char) * (j + 1));
	while (data->cp_env[i][w] && w < j)
	{
		new_val[w] = data->cp_env[i][w];
		w++;
	}
	new_val[w] = '\0';
	data->cp_env[i] = verif_pwd(new_val);
	free(new_val);
}

void	change_value_pwd_env(t_data *data)
{
	char	*new_val;
	int		i;
	int		j;
	int		w;

	i = 0;
	j = 0;
	w = 0;
	while (data->cp_env[i])
	{
		if (ft_strncmp(data->cp_env[i], "PWD=", 4) == 0)
			break ;
		i++;
	}
	j = recup_new_pwd_env(data);
	new_val = malloc(sizeof(char) * (j + 1));
	while (data->cp_env[i][w] && w < j)
	{
		new_val[w] = data->cp_env[i][w];
		w++;
	}
	new_val[w] = '\0';
	data->cp_env[i] = verif_pwd(new_val);
	free(new_val);
}

void	change_val_pwdpath(t_data *data, char **cmd, int exp)
{
	char	**path;
	int		i;

	i = 0;
	path = ft_split(cmd[1], '/');
	while (path[i])
	{
		if (ft_strcmp(path[i], "..") == 0)
		{
			if (exp)
				change_value_pwd_exp(data);
			else
				change_value_pwd_env(data);
		}
		if (ft_strcmp(path[i], "..") != 0 && ft_strcmp(path[i], ".") != 0)
		{
			if (exp)
				add_reponame_exp(data, path[i]);
			else
				add_reponame_env(data, path[i]);
		}
		i++;
	}
	free_tab(path);
}
