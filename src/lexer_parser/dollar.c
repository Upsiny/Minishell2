/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:18:37 by hguillau          #+#    #+#             */
/*   Updated: 2023/07/04 18:11:07 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	replace_prompt(t_data *data, char *value, int start, int end)
{
	char	*first_part;
	char	*last_part;
	char	*new_prompt;
	int		i;
	int		j;

	i = 0;
	j = end;
	first_part = malloc((start + 1) * sizeof(char));
	if (!first_part)
	{
		free(first_part);
		return ;
	}
	last_part = malloc((ft_strlen(data->prompt) - end + 1) * sizeof(char));
	if (!last_part)
	{
		free(last_part);
		return ;
	}
	if (!value)
		value = "";
	while (i < start)
	{
		first_part[i] = data->prompt[i];
		i++;
	}
	first_part[i] = '\0';
	i = 0;
	while (data->prompt[j])
	{
		last_part[i] = data->prompt[j];
		i++;
		j++;
	}
	last_part[i] = '\0';
//    printf("val : %s\n", value);
	new_prompt = ft_strjoin(first_part, value);
	free(first_part);
	data->tmp_dollar = ft_strdup3(new_prompt);
	free(new_prompt);
	new_prompt = ft_strjoin(data->tmp_dollar, last_part);
	free(last_part);
	free(data->tmp_dollar);
	free(data->prompt);
	data->prompt = ft_strdup3(new_prompt);
	free(new_prompt);
}

int	ft_isinside(char c)
{
	int	i;

	i = 0;
	while (DOLLAR_STOP[i])
	{
		if (DOLLAR_STOP[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	get_dollar(t_data *data)
{
	int		i;
	int		j;
	int		k;
	char	*dol_value;
	char	*split;

	i = data->lexer_check;
	j = 0;
	k = 1;
	while (data->prompt[i + j])
	{
		j++;
		if (!ft_isspace(data->prompt[i + j])
			|| !ft_isinside(data->prompt[i + j]))
			break ;
	}
	dol_value = malloc(sizeof(char) * (j + 1));
	if (!dol_value)
	{
		free(dol_value);
		return ;
	}
	while (k < j)
	{
		dol_value[k - 1] = data->prompt[i + 1];
		k++;
		i++;
	}
	dol_value[k - 1] = '\0';
    split = search_in_env(data, dol_value);
	if (!split)
    {
        free(split);
        return;
    }
	replace_prompt(data, split, data->lexer_check - 1,
		data->lexer_check + j);
//    printf("%s\n", data->prompt);
	free(split);
}
