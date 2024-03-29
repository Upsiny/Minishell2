/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:11:27 by tpaufert          #+#    #+#             */
/*   Updated: 2024/02/27 19:21:31 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/lexer_parser.h"
#include "../../includes/minishell.h"

char	**ft_tabcpy(char **tab)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!tab || !(tab[0]))
		return (NULL);
	while (tab[j])
		j++;
	tmp = malloc(sizeof(char *) * (j + 1));
	if (!tmp)
	{
		free_2d_arr(tmp);
		return (NULL);
	}
	while (tab[i])
	{
		tmp[i] = ft_strdup3(tab[i]);
//	printf("debug1111111111111111111111111111111111111111111111\n");
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

t_data	*init_struct(char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		ft_error_msg("malloc error");
	data->st_cmd = malloc(sizeof(t_cmd));
	if (!data->st_cmd)
		ft_error_msg("malloc error");
	if (envp[0] == NULL)
		printf("No envp. get only new pwd and the old.");
	else
		data->cp_env = ft_tabcpy(envp);//provoque des leaks
//	printf("debug2222222222222222222222222222222222222222222222\n");
	data->cp_exp = envp;
	data->cp_exp = order_exp(data->cp_exp);
//	dprintf(2, "debug3333333333333333333333333333333333333333333\n");//DEBUG
	data->content_here = NULL;
	data->pid = -1;
	data->in_pipe = 0;
	data->ret_err = 0;
	data->val_home = get_home_value(data->cp_env);
	data->pwd = get_env_value(data->cp_env, "PWD=");
	data->oldpwd = get_env_value(data->cp_env, "PWD=");
	data->oldpwd = ft_strjoin("OLDPWD=", data->oldpwd);
	add_variable(data, data->oldpwd);
	return (data);
}
