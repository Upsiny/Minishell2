/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_exec_builtins.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:26:26 by hguillau          #+#    #+#             */
/*   Updated: 2024/05/08 10:45:04 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*recup_real_cmd(char *line)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
		i++;
	while (i != 0 && line[i] != '/')
		i--;
	tmp = malloc(sizeof(char) * ((ft_strlen(line) - i) + 1));
	i += 1;
	while (line[i])
	{
		tmp[j] = line[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*check_cmd(char *str)
{
	char	*real_cmd;
	int		nb_slash;

	nb_slash = ft_nb_slash(str);
	real_cmd = NULL;
	if (nb_slash >= 2)
	{
		if (str[0] == '/')
		{
			if (access(str, R_OK) == 0)
				real_cmd = recup_real_cmd(str);
			else
			{
				real_cmd = NULL;
				perror(NULL);
			}
		}
	}
	else if (nb_slash < 2)
		real_cmd = ft_strdup(str);
	return (real_cmd);
}

void	verif_and_modif_cmd_if_slash_or_quote(char **cmd)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (cmd[0] == NULL)
		return ;
	while (cmd[i])
	{
		if (ft_strlen(cmd[i]) > 0 && (cmd[i][0] == '\'' || cmd[i][0] == '\"'))
		{
			cmd[i][ft_strlen(cmd[i]) - 1] = '\0';
			tmp = ft_strdup(&(cmd[i][1]));
			free(cmd[i]);
			cmd[i] = tmp;
		}
		i++;
	}
	tmp = cmd[0];
	cmd[0] = check_cmd(tmp);
	free(tmp);
}

char	**verif_cmd_struct(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		verif_and_modif_cmd_if_slash_or_quote(&cmd[i]);
		i++;
	}
	return (cmd);
}

// envoie une commande soit dans builtins, soit dans execve
void	redir_builtins_or_execve(t_data *data, char **args)
{
	char	**full_cmd;
//	char	*tmp_cmd;

	full_cmd = add_cmd_before_args(data, args);
	if (!(data->s_lex))
		return ;
/*	if (ft_strcmp(data->s_lex->content, "cd") == 0 || ft_strlen(args[0]) == ft_strlen("99999999999999999999999999999999999"))
	{
		if (full_cmd[1] == NULL || (full_cmd[1][0] == '~' && full_cmd[1][1] == '\0'))
			full_cmd[1] = get_home_value(data->cp_env);
		else if (full_cmd[1] == NULL || (full_cmd[1][0] == '~' && full_cmd[1][1] != '\0'))
		{
			tmp_cmd = ft_calloc(sizeof(char), ft_strlen(full_cmd[1] - 1));
			ft_memcpy(tmp_cmd, full_cmd[1] + 1, ft_strlen(full_cmd[1]));
			full_cmd[1] = get_home_value(data->cp_env);
			full_cmd[1] = ft_strjoin(full_cmd[1], tmp_cmd);
		}
		else if (full_cmd[1] == NULL || (full_cmd[1][0] == '-' && full_cmd[1][1] == '\0'))
		{
			full_cmd[1] = ft_split(get_env_value(data->cp_env, "PWD="), '=')[1];
			printf("%s\n", full_cmd[1]);
		}
		cd_builtin(data, full_cmd);
	}*/
	if (!data)
		printf("hello\n");
	if (ft_strcmp(data->s_lex->content, "cd") == 0)
		cd_builtin(data, full_cmd);
	else if (ft_strcmp(data->s_lex->content, "pwd") == 0)
        pwd_builtin(data);
	else if (ft_strcmp(data->s_lex->content, "exit") == 0)
		exit_builtin(data, full_cmd);
	else if (ft_strcmp(data->s_lex->content, "echo") == 0)
		echo_builtin(full_cmd);
	else if (ft_strcmp(data->s_lex->content, "env") == 0)
		env_builtin(data, full_cmd);
	else if (ft_strcmp(data->s_lex->content, "export") == 0)
		export_builtin(data, full_cmd);
	else if (ft_strcmp(data->s_lex->content, "unset") == 0)
		unset_builtin(data, full_cmd);
	else
		ft_set_path_and_execve(data, full_cmd);
    free(full_cmd);
}
