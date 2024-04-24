/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:22:38 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:22:42 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	change_value_exp(t_data *data, char **cmd)
{
	if (cmd[1][0] == '/')
		change_val_exp(data, cmd[1]);
	else if (ft_strcmp(cmd[1], ".") == 0 || ft_strcmp(cmd[1], "./") == 0)
		change_value_oldpwd(data, 1);
	else if (ft_strcmp(cmd[1], "..") == 0 || ft_strcmp(cmd[1], "../") == 0)
	{
		change_value_pwd_exp(data);
		change_value_oldpwd(data, 1);
	}
	else if ((ft_strcmp(cmd[1], "./") > 0 || ft_strcmp(cmd[1], "../") > 0))
	{
		change_value_oldpwd(data, 1);
		change_val_pwdpath(data, cmd, 1);
	}
}

void	change_value_env(t_data *data, char **cmd)
{
	if (cmd[1][0] == '/')
	{
		change_val_env(data, cmd[1]);
	}
	else if (ft_strcmp(cmd[1], ".") == 0 || ft_strcmp(cmd[1], "./") == 0)
		change_value_oldpwd(data, 0);
	else if (ft_strcmp(cmd[1], "..") == 0 || ft_strcmp(cmd[1], "../") == 0)
	{
		change_value_pwd_env(data);
		change_value_oldpwd(data, 0);
	}
	else if ((ft_strcmp(cmd[1], "./") > 0 || ft_strcmp(cmd[1], "../") > 0))
	{
		change_value_oldpwd(data, 0);
		change_val_pwdpath(data, cmd, 0);
	}
}

char	*get_env_value(char **env, const char *var)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)) == 0)
			return (env[i]);
		i++;
	}
	return (NULL);
}
