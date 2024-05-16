/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:21:51 by hguillau          #+#    #+#             */
/*   Updated: 2024/05/16 15:26:25 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
	//	if (tmp->content != NULL)
			free(tmp->content);
        free(tmp);
	}
}

void	free_2d_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// ne pas oublier de stocker dans nb_cmds le nombre de cmds,
// sinon le builtin exit ne fonctionne pas pareil
// bah fait le
int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	char	**cmd;
//	int	i = 0; //debug

	(void) av;
	data = init_struct(envp);
	if (ac != 1)
	{
		ft_free_lst(data);
		ft_error_msg("no arguments accepted");
	}
	if (!data)
		ft_error_msg("Malloc Error");
	ft_signaux();
	while (1)
	{
		data->pid = -1;
		data->prompt = readline("Minishell Lovecraftien (҂◡_◡) > ");
		add_history(data->prompt);
		if (!(data->prompt))
		{
			printf("exit\n");
			exit(0);
//			break ;
		}
		init_lexer(data);
		if (!lexer_work(data))
		{
			if (!ft_check_lst(data))
			{
//				pour exit, il faut indiquer que cest la seule cmds
//				data->nb_cmds = 1;
//				print_list(data);
				cmd = build_cmd_from_lexer(data);
				redir_builtins_or_execve(data, cmd);
				free_list(data->s_lex);
			}
		}
		free(data->content_here);
		free(data->prompt);
		free(cmd);
//		while (data->cp_env[i] || i == 0){ //debug
//			printf("env = %s\n ptr = %p\n", data->cp_env[i], data->cp_env[i]);
//			i++;}
		//debug
//		i = 0;
	}
	free_2d_arr(data->cp_env);
	free_2d_arr(data->cp_exp);
//	free(data->pwd);
//	free(data->oldpwd);
	ft_free_lst(data);
//	exit(0);
}
