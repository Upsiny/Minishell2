/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:30:43 by hguillau          #+#    #+#             */
/*   Updated: 2024/05/09 09:28:07 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/lexer_parser.h"
#include "../../includes/minishell.h"

/*void	create_my_env(t_data *data)
{
	char	*tmp_pwd;
	char	*pwd;
	char	*opwd;
	
	tmp_pwd = getcwd(NULL, 0);
	pwd = ft_strjoin("PWD=", tmp_pwd);
	opwd = ft_strjoin("OLDPWD=", tmp_pwd);
	printf("debug\n");
	add_variable(data, pwd);
	add_variable(data, opwd);
	free(tmp_pwd);
	free(pwd);
	free(opwd);
}*/

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
	{
		printf("No envp. get only new pwd and the old.\n");
		data->cp_env = ft_calloc(sizeof(char *), 1);
//		create_my_env(data);
	}
	else
		data->cp_env = ft_tabcpy(envp);
	data->cp_exp = envp;
	data->cp_exp = order_exp(data->cp_exp);
	data->content_here = NULL;
	data->bdq = 0;
	data->bsq = 0;
//	data->pid = -1;
	data->in_pipe = 0;
	data->ret_err = 0;
//	data->val_home = get_home_value(data->cp_env);
//	data->pwd = get_env_value(data->cp_env, "PWD=");
//	data->oldpwd = get_env_value(data->cp_env, "PWD=");
//    printf("%s\n", data->oldpwd);
	return (data);
}
