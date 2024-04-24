/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:26:17 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 15:06:54 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	verif_cmd(char **all_path, char **pathcmd, char **cmd)
{
	char	*gd_path;
	int		i;
	int		z;

	i = 0;
	z = 0;
	gd_path = NULL;
	while (all_path[i])
	{
		gd_path = ft_strjoin(all_path[i], pathcmd[0]);
		if (access(gd_path, R_OK) == 0)
		{
			free(gd_path);
			return (0);
		}
		else
			i++;
		free(gd_path);
		z++;
	}
//	printf("je passe ici? \n");
	if (z == i)
//        aff_errcmd(cmd);
		return(aff_errcmd(cmd));
	return (0);
}

int	aff_errcmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[0][i])
	{
		if (cmd[0][i] == '/')
		{
			ft_print_error_msg3("minishell: ", cmd[0],
				": No such file or directory\n");
			return (127);
		}
		i++;
	}
//	printf("je passe la\n");
	ft_print_error_msg3("minishell: ", cmd[0], ": command not found\n");
	return (127);
}

void	ft_execve(t_data *data, char **all_path, char **pathcmd, char **cmd)
{
	char	*gd_path;
	int		i;
	pid_t	p;
	int		status;

	(void) cmd;
	i = 0;
	p = fork();
	while (all_path[i])
	{
		gd_path = ft_strjoin(all_path[i], pathcmd[0]);
		if (access(gd_path, R_OK) == 0)
		{
			if (p == -1)
			{
				perror("Fork");
				exit(EXIT_FAILURE);
			}
			else if (p == 0)
			{
				if (execve(gd_path, pathcmd, data->cp_env) == -1)
				{
					perror("Execve : ");
					exit(EXIT_FAILURE);
				}
			}
			else
				wait(&status);
		}
		i++;
		free(gd_path);
	}
}

//why is pathcmd a char**? it might be logic, but don't look like it at first sight --theo
//why is "" leaking while an other cmd as been done before? --helian
void	ft_execution(t_data *data, char **all_path, char **pathcmd, char **cmd)
{
	if (access(cmd[0], X_OK) == 0)
	{
		if (execve(cmd[0], pathcmd, data->cp_env) == -1)
		{
			perror("Execve : ");
			exit(EXIT_FAILURE);
		}
		return ;
	}
	if (verif_cmd(all_path, pathcmd, cmd) != 0)
	{
		free_tab(all_path);
		free_tab(pathcmd);
//		printf("kamoulox?\n");
	//	exit(data->ret_err);
	}
	else
	{
		ft_execve(data, all_path, pathcmd, cmd);
		free_tab(all_path);
		free_tab(pathcmd);
	}
}
