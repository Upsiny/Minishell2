/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:30:56 by hguillau          #+#    #+#             */
/*   Updated: 2024/05/10 12:12:40 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		quote_in_str(t_data *data, char c)
{
	int	i;

	i = 0;
	if (ft_check_endquote(data, c) != 0)
	{
		i = ft_check_endquote(data, c);
		if (c == '\'')
			data->bsq = 1;
		else
			data->bdq = 1;
		return (i);
	}
	else
		return (0);
}

int	ft_lexer_alpha(t_data *data)
{
	int		i;
	int		j;
	int		quote;
	char	oc;

	i = 0;
	j = data->lexer_check;
	while (data->prompt && data->prompt[j + i])
	{
		if (data->lexer_char == '|' || data->lexer_char == '<'
			|| data->lexer_char == '>' || !ft_isspace(data->lexer_char)
		/*	|| data->lexer_char == '\'' || data->lexer_char == '\"'*/)
			break ;
		if (data->lexer_char == '\'' || data->lexer_char == '\"') // debut quotes
		{
			quote = quote_in_str(data, data->lexer_char);
			if (quote == 0)
			{
				error_lexer("no ended quote");
				return (1);
			}
			else
			//avancer de quote et check pour le dollar | remettre les bool a 0
			{
				oc = data->lexer_char;
				replace_prompt(data, NULL, i, i + 1);
				data->lexer_char = data->prompt[data->lexer_check];
				while (data->prompt[data->lexer_check] != oc)
				{
					if (data->prompt[data->lexer_check] == '$' && data->bdq == 1)
						get_dollar(data);
					i++;
					lexer_advance(data);
				}
				replace_prompt(data, NULL, data->lexer_check, data->lexer_check + 1);
				data->bdq = 0;
				data->bsq = 0;
			} // fin du else
		}// fin quotes
		if (data->prompt[data->lexer_check] == '$')
		{
			get_dollar(data);
			if (!data->prompt)
				return (1);
		}
		if (data->prompt[data->lexer_check] != '$'
			&& data->prompt[data->lexer_check])
		{
			i++;
			lexer_advance(data);
		}
	}
	implement_list(data, TOKEN_STRING, i, j);
	data->index_lexer++;
	return (0);
}
