/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:24:57 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:24:59 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_val_exp(char *str)
{
	int	i;
	int	j;

	j = 0;
	printf("declare -x ");
	while (str[j] != '=')
		printf("%c", str[j++]);
	printf("=\"");
	i = j + 1;
	if (str[j] != '\0')
		while (str[i] != '\0')
			printf("%c", str[i++]);
	printf("\"\n");
}

int	count_variables(char **env)
{
	int	count;

	count = 0;
	while (env[count] != NULL)
		count++;
	return (count);
}

int	is_valid_exp2(char *str)
{
	if (str == NULL)
		return (1);
	if (str[0] == '\0')
		return (1);
	if (ft_strchr(str, '-'))
		return (1);
	return (0);
}

int	is_valid_exp(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (str[i] == 32)
			return (1);
		i++;
	}
	return (0);
}

void	print_export(char **cp_exp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cp_exp[i])
	{
		j = 0;
		if (check_var(cp_exp[i]) == 0)
		{
			printf("declare -x ");
			while (cp_exp[i][j] != '\0')
				printf("%c", cp_exp[i][j++]);
			printf("\n");
		}
		else
			print_val_exp(cp_exp[i]);
		i++;
	}
}
