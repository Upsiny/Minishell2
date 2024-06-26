/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:32:02 by hguillau          #+#    #+#             */
/*   Updated: 2024/05/16 13:42:38 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/*
int	ft_check_endquote(t_data *data, char c)
{
	int	i;
	int	j;

	i = 1;
	j = data->lexer_check;
	while (data->prompt[j])
	{
		i++;
		j++;
		if (data->prompt[j] == c)
			return (i);
	}
	return (0);
}
*/
/*
int	ft_check_endquote(t_data *data, char c, int	i, int j)
{
	data->sfqi = i;
	data->sfq = j;
	while (data->prompt[data->sfq])
	{
		data->sfqi++;
		data->sfq++;
		if ((data->prompt[data->sfq] == '\'' && data->prompt[data->sfq] != c)
			|| (data->prompt[data->sfq] == '\"'
			&& data->prompt[data->sfq] != c))
			ft_check_endquote(data, data->prompt[data->sfq],
			data->sfqi, data->sfq);
		if (data->prompt[data->sfq] == c)
			return (data->sfqi);
	}
	return (0);
}
*//*
int	ft_simple_quotes(t_data *data)
{
	int	i;

	i = 0;
	if (ft_check_endquote(data, '\'') != 0)
	{
		i = ft_check_endquote(data, '\'');
		implement_list(data, TOKEN_SQUOTE, i - 2, data->lexer_check + 1);
		while (i)
		{
			lexer_advance(data);
			i--;
		}
		return (0);
	}
	else
	{
		error_lexer("no ended quote");
		return (1);
	}
}

int	ft_double_quotes(t_data *data)
{
	int	i;

	i = 1;
	if (ft_check_endquote(data, '\"') != 0)
	{
		i = data->lexer_check;
		lexer_advance(data);
		while (data->prompt[data->lexer_check] != '\"')
		{
			if (data->prompt[data->lexer_check] == '$'*//*
				&& data->prompt[data->lexer_check - 1] != '$'*//*)
			{
				data->bdq = 1;
				get_dollar(data);
				data->bdq = 0;
			}
			else
				lexer_advance(data);
		}
		implement_list(data, TOKEN_DQUOTE,
			(data->lexer_check - i) - 1, i + 1);
		lexer_advance(data);
		return (0);
	}
	else
	{
		error_lexer("no ended quote");
		return (1);
	}
}

int	ft_lexer_quotes(t_data *data)
{
	if (data->lexer_char == '\"')
	{
		if (ft_double_quotes(data))
			return (1);
	}
	else if (data->lexer_char == '\'')
	{
		if (ft_simple_quotes(data))
			return (1);
	}
	data->index_lexer++;
	return (0);
}*/
