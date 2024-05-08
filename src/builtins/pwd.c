/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:25:09 by hguillau          #+#    #+#             */
/*   Updated: 2024/05/04 15:41:34 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd_builtin(t_data *data)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	printf("%s\n", tmp);
	free(tmp);
	data->ret_err = 0;
//	int	i;
//
//	i = 0;
//	while (data->cp_env[i])
//	{
//		if (ft_strncmp(data->cp_env[i], "PWD=", 4) == 0)
//		{
//			while (data->cp_env[i])
//			{
//				data->ret_err = 0;
//				printf("%s\n", data->cp_env[i] + 4);
//				return ;
//			}
//		}
//		i++;
//	}
//	if (i == ft_tab_len(data->cp_env))
//	{
//		data->ret_err = 127;
//		ft_print_error_msg3("minishell: ", cmd[0],
//			": No such file or directory\n");
//		return ;
//	}
}
