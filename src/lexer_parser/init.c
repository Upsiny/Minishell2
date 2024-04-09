/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:11:27 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/07 16:31:49 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/lexer_parser.h"
#include "../../includes/minishell.h"

char	**ft_tabcpy(char **tab)
{
	int		i;
	char	**newtab;
	i = 0;
	while (tab[i])
		i++;
	newtab = malloc(sizeof(char *) * (i + 1));
	if (!newtab)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		newtab[i] = ft_strdup3(tab[i]);
		if (!newtab[i])
		{
			while (i >= 0)
			{
				free(newtab[i]);
				i--;
			}
			free(newtab);
			return (NULL);
		}
		i++;
	}
	newtab[i] = NULL;
	return (newtab);
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
		data->cp_env = envp;
	data->cp_exp = ft_tabcpy(data->cp_env);
	data->cp_exp = order_exp(data->cp_exp);
	data->content_here = NULL;
	data->pid = -1;
	data->in_pipe = 0;
	data->ret_err = 0;
//	data->val_home = get_env_value(data->cp_env, "HOME=");
//	data->pwd = get_env_value(data->cp_env, "PWD=");
//	data->oldpwd = get_env_value(data->cp_env, "PWD=");
//	data->oldpwd = ft_strjoin("OLDPWD=", data->oldpwd);
//	add_variable(data, data->oldpwd);
	return (data);
}
