/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:24:06 by hguillau          #+#    #+#             */
/*   Updated: 2024/05/08 13:18:29 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	if_path_exist(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	if (data->cp_env)
	{
		len = ft_tab_len(data->cp_env);
		while (data->cp_env[i])
		{
			if (ft_strncmp(data->cp_env[i], "PATH=", 5) == 0)
				break ;
			i++;
		}
		if (len != i)
			return (1);
		else
			return (0);
	}
	return (1);
}

void	env_builtin(t_data *data, char **cmd)
{
	int	i;

	i = 0;
/*	if (!if_path_exist(data))
	{
		write(2, "minishell :", 11);
		write(2, cmd[0], ft_strlen(cmd[0]));
		write(2, ": No such file or directory\n", 28);
		data->ret_err = 127;
		return ;
	}*/
	if (cmd[1])
	{
		write(2, "env :", 5);
		write(2, "'", 1);
		write(2, &cmd[1], ft_strlen(cmd[1]));
		write(2, "': No such file or directory\n", 29);
		data->ret_err = 127;
		return ;
	}
	if (data->cp_env)
	{
		while (data->cp_env[i])
		{
			printf("%s\n", data->cp_env[i]);
			i++;
		}
	}
	data->ret_err = 0;
}
