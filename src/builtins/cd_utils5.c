/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:23:37 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:23:39 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cd_go_home(t_data *data)
{
	char	*home_env;
	char	*home_exp;
	char	*pwd_env;
	char	*pwd_exp;

	home_env = get_home_value(data->cp_env);
	home_exp = get_home_value(data->cp_exp);
	data->oldpwd = data->pwd;
	data->pwd = home_env;
	pwd_env = ft_split(home_env, '=')[1];
	pwd_exp = ft_split(home_exp, '=')[1];
	printf("%s\n", pwd_env);
	change_val_env(data, pwd_env);
	change_val_exp(data, pwd_exp);
//	free(home_env);
//	free(home_exp);
//	free(pwd_env);
//	free(pwd_exp);
}
