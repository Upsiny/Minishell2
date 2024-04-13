/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:24:29 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/07 17:30:49 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	change_val_exp(t_data *data, char *new_pwd)
{
	int	i;

	i = 0;
	change_value_oldpwd(data, 1);
	while (data->cp_exp[i])
	{
		if (ft_strncmp(data->cp_exp[i], "PWD=", 4) == 0)
			break ;
		i++;
	}
	data->cp_exp[i] = ft_strjoin("PWD=", new_pwd);
}

void	change_val_env(t_data *data, char *new_pwd)
{
	int	i;

	i = 0;
	change_value_oldpwd(data, 0);
	while (data->cp_env[i])
	{
		if (ft_strncmp(data->cp_env[i], "PWD=", 4) == 0)
			break ;
		i++;
	}
	data->cp_env[i] = ft_strjoin("PWD=", new_pwd);
}

void	add_reponame_exp(t_data *data, char *repo)
{
	char	*new_pwd;
	char	*all_addup;
	int		i;

	i = 0;
	new_pwd = NULL;
	while (data->cp_exp[i++])
	{
		if (ft_strncmp(data->cp_exp[i], "PWD=", 4) == 0)
		{
			new_pwd = ft_strdup3(data->cp_exp[i]);
			break ;
		}
	}
	if (new_pwd[4] == '/' && new_pwd[5] == '\0')
		data->cp_exp[i] = ft_strjoin(new_pwd, repo);
	else
	{
		all_addup = ft_strjoin(new_pwd, "/");
		data->cp_exp[i] = ft_strjoin(all_addup, repo);
		free(all_addup);
	}
	free(new_pwd);
}

void	add_reponame_env(t_data *data, char *repo)
{
	char	*new_pwd;
	char	*all_addup;
	int		i;

	i = 0;
	new_pwd = NULL;
	while (data->cp_env[i++])
	{
		if (ft_strncmp(data->cp_env[i], "PWD=", 4) == 0)
		{
			new_pwd = ft_strdup3(data->cp_env[i]);
			break ;
		}
	}
	if (new_pwd[4] == '/' && new_pwd[5] == '\0')
		data->cp_env[i] = ft_strjoin(new_pwd, repo);
	else
	{
		all_addup = ft_strjoin(new_pwd, "/");
		data->cp_env[i] = ft_strjoin(all_addup, repo);
		free(all_addup);
	}
	free(new_pwd);
}

void	cpy_value(char *name_var, char **str, char *new_val)
{
	char	*ret;
	int		i;

	i = 0;
	ret = join_var(name_var, new_val);
	while (str[i])
	{
		if (ft_strncmp(str[i], name_var, ft_strlen(name_var)) == 0)
		{
			str[i] = ft_strdup3(ret);
			break ;
		}
		i++;
	}
	free(ret);
}
