/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:24:33 by hguillau          #+#    #+#             */
/*   Updated: 2024/05/08 13:41:05 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Vérifie si une variable existe déjà dans l'environnement
int	variable_exists(char **env, char *variable)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (variable[j] != '=' && variable[j] != '\0')
		j++;
	while (env[i])
	{
		if (ft_strncmp(env[i], variable, j) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	update_variable(char **env, char *variable)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
/*	if (!variable_exists(env, variable))
	{
		add_variable(data, variable);
		return ;
	}*/
	while (variable[j] != '=' && variable[j] != '\0')
		j++;
	while (env[i])
	{
		if (ft_strncmp(env[i], variable, j) == 0)
		{
			free(env[i]);
			env[i] = ft_strdup3(variable);
			if (env[i] == NULL)
				return ;
		}
		i++;
	}
}

// Ajoute une variable à l'environnement
void	add_variable(t_data *data, char *variable)
{
	int		count;
	char	**new_env;
	int		i;

	if (!data->cp_env)
	{
		new_env = ft_calloc(sizeof(char *), 2);
		if (!new_env)
		{
			free_2d_arr(new_env);
			return ;
		}
		new_env[0] = ft_strdup3(variable);
	//	new_env[1] = NULL;
//		dprintf(2, "new env: %s ; %s\n", new_env[0], new_env[1]);//DEBUG
	//	free(data->cp_env);
		data->cp_env = new_env;
//		dprintf(2, "new env: %s ; %s\n", data->cp_env[0], data->cp_env[1]);//DEBUG
		return ;
	}
	i = 0;
	count = count_variables(data->cp_env);
	new_env = malloc(sizeof(char *) * (count + 2));
	if (!new_env)
	{
		free_2d_arr(new_env);
		return ;
	}
	while (i < count)
	{
		new_env[i] = ft_strdup3(data->cp_env[i]);
		if (!(new_env[i]))
		{
			free_2d_arr(new_env);
			return ;
		}
		i++;
	}
	new_env[count] = ft_strdup3(variable);
	if (!(new_env[count]))
	{
		free_2d_arr(new_env);
		return ;
	}
	new_env[count + 1] = NULL;
	i = 0;
	while (data->cp_env[i] != NULL)
		i++;
	free_2d_arr(data->cp_env);
	data->cp_env = new_env;
}

// Fonction principale pour exporter une variable
void	export_builtin2(t_data *data, char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i] != NULL)
	{
		if (is_valid_exp(cmd[1]) && is_valid_exp2(cmd[1]))
		{
			ft_print_error_msg3("minishell: export: `",
				cmd[1], "': not a valid identifier\n");
			data->ret_err = 1;
		}
		else if (!data->cp_env)
			add_variable(data, cmd[1]);
		else if (variable_exists(data->cp_env, cmd[i]))
			update_variable(data->cp_env, cmd[i]);
		else
			add_variable(data, cmd[i]);
		i++;
	}
}

void	export_builtin(t_data *data, char **cmd)
{
//	int	i;

//	i = 0;
	if (!(cmd[1]))
		print_export(data->cp_exp);
	else
	{
		export_builtin2(data, cmd);
		free_tab(data->cp_exp);
		data->cp_exp = order_exp(data->cp_env);
		data->ret_err = 0;
	}
//	while (data->cp_env[i])//debug
//	{
//		printf("env end builtin = %s\n",data->cp_env[i]);
//		i++;
//	}
}
