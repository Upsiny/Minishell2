/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:35:30 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:35:33 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_wait_all(void)
{
	pid_t	wpid;
	int		stat;

	wpid = wait(&stat);
	while (wpid > 0)
	{
		wpid = wait(&stat);
	}
	return ;
}

int	ft_pipes_create(t_data *data)
{
	int	**pp;
	int	i;

	data->nb_cmds = ft_count_list(data->st_cmd);
	pp = ft_calloc(data->nb_cmds + 1, sizeof(int *)));
	if (!pp)
	{
		perror(NULL);
		exit(1);
	}
	i = 0;
	while (i < data->nb_cmds)
	{
		pp[i] = ft_calloc(2, sizeof(int));
		if (!pp[i])
		{
			perror(NULL);
			exit(1);
		}
		i++;
	}
	return (pp);
}

void	piping(t_data *data)
{
	int		**pp;
	pid_t	pid;
	int		i;

	i = 0;
	pp = ft_pipes_create(data);
	while (i + 1 < data->nb_cmds)
	{
		if (pipe(pp[i]) == -1)
			perror("pipe: ");
		pid = fork();
		data->pid = pid;
		if (pid == -1)
			exit(127);
		else if (pid == 0)
			// fonction de processuss + go dans lexecution chaque element
			ft_child(data, pp, i);
		else
			// fonction qui close processus
			ft_parent(pp, i);
		i++;
	}
	//go dans lexecution la derniere cmd, ou, la seul cmd si il ny a pas de pipe
	ft_last_command(data, pp, i);
	ft_wait_all();
	free_tab(pp);
}

/*void	pipes_redir(t_data *data)
{
	if (cmd[0]->cmd[0] == NULL && cmd[0]->stdin[0] == NULL
		&& cmd[0]->stdout[0] == NULL)
		return ;
	else
		piping(data);
}*/
