/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:22:15 by hguillau          #+#    #+#             */
/*   Updated: 2024/05/04 14:44:04 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_new_pwd(t_data *data) // actualise le oldpwd et le pwd
{
	char	*tmp_pwd;
	char	*send_pwd;

	tmp_pwd = getcwd(NULL, 0);
	if (tmp_pwd == NULL)
	{
		ft_print_error_msg1("cd: error retrieving current directory: ");
		ft_print_error_msg1("getcwd: cannot access parent directories");
		ft_print_error_msg1(": No such file or directory\n");
		return ;
	}
	send_pwd = ft_strjoin("PWD=", tmp_pwd);
	update_variable(data->cp_env, send_pwd);
	free(tmp_pwd);
	free(send_pwd);
}

int	ft_chdir(char *path, char *str, t_data *data) // fait si realisable, le transfert dans le dossier cible
{
	char	*tmp_opwd;

	if (chdir(path) != 0)
	{ // pense a secure les print_error_msg
		ft_print_error_msg3("minishell: cd: ", str/*?str:"n/a"*/, ": No such file or directory\n");
		data->ret_err = 1;
		return (1);
	}
	tmp_opwd= ft_strjoin("OLD", get_env_value(data->cp_env, "PWD="));
	update_variable(data->cp_env, tmp_opwd);
	ft_new_pwd(data);
	free(tmp_opwd);
	return (0);
}

void	cd_builtin(t_data *data, char **cmd)
{
	char *path;
	int	i;
	
	i = 5;
	if (!cmd[1])
	{
		path = get_env_value(data->cp_env, "HOME="); // penser a avancer le pointeur jusqu'au "="
		if (!path)
		{
			ft_print_error_msg1("minishell: cd: HOME not set\n");
			data->ret_err = 1;
			return ;
		}
		while (i > 0)
		{
			path++;
			i--;
		}
		printf("path = %s\n", path);
		ft_chdir(path, cmd[1], data);
	}
	else if (cmd[2])
	{
		ft_print_error_msg1("cd: too many arguments\n");
		data->ret_err = 1;
		return ;
	}
	else
		ft_chdir(cmd[1], cmd[1], data);
}
