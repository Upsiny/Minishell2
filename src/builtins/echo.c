/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:23:50 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:23:52 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	checker_n(char	*arg)
{
	int	i;

	i = 1;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	check_option(char **cmd)
{
	int	i;

	i = 2;
	while (cmd[i] && cmd[i][0] != '\0'
		&& (cmd[i][0] >= 32 && cmd[i][0] <= 126))
	{
		if (cmd[i + 1] != NULL)
			printf("%s ", cmd[i]);
		else
			printf("%s", cmd[i]);
		i++;
	}
	return ;
}

void	echo_builtin(char **cmd)
{
	int	i;

	i = 1;
	if (!cmd[1] || cmd[1] == NULL || cmd[1][0] == '\0')
	{
		printf("\n");
		return ;
	}
	if ((ft_strncmp((cmd[1]), "-n", 2)) == 0 && checker_n(cmd[1]) == 1)
		check_option(cmd);
	else if (ft_strlen(cmd[0]) == 4)
	{
		while (cmd[i] && cmd[i][0] != '\0'
			&& (cmd[i][0] >= 32 && cmd[i][0] <= 126))
		{
			if (cmd[i + 1] != NULL)
				printf("%s ", cmd[i]);
			else
				printf("%s\n", cmd[i]);
			i++;
		}
	}
}
