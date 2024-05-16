/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:20:16 by hguillau          #+#    #+#             */
/*   Updated: 2024/05/16 15:25:56 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// remove la quote dans le prompt
void	remove_quote(t_data *data, int pos)
{
	char	*new_prompt;
	int		i;

	new_prompt = malloc(ft_strlen(data->prompt) * sizeof(char));
	i = 0;
	while (i < pos)
	{
		new_prompt[i] = data->prompt[i];
		i++;
	}
	while (data->prompt[i + 1])
	{
		new_prompt[i] = data->prompt[i + 1];
		i++;
	}
	new_prompt[i] = '\0';
	free(data->prompt);
	data->prompt = ft_strdup3(new_prompt);
	free(new_prompt);
//	printf("new_prompt = %s\n", data->prompt); //debug
}

// remove les quotes du prompt et avance jusque la fermeture de celle-ci
int	work_in_quote(t_data *data, char qtype, int pos)
{
	int	i;// size totale de la quote (avec expand si expand)
	int	j;// position sur laquelle on travaille

	j = pos;
	i = 0;
	remove_quote(data, j);
	while (data->prompt[j] != qtype)
	{
//		if (data->prompt[j] == '$' && data->bdq == 1) // commenter pour les premiers tests
//			get_dollar(data, j) // refaire le get dollar avec j = pos du dollar
		i++;
		j++;
	}
	remove_quote(data, j);
	return (i);
}

// regarde si la quote est fermente
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
		{
			return (i);
		}
	}
	return (0);
}

// travaille si il y a une quote dans la str
int	get_quote(t_data *data, int pos)
{
	int		i;
	char	qtype;

	qtype = data->prompt[pos];
	if (ft_check_endquote(data, qtype))
	{
		if (qtype == '\'')
			data->bsq = 1;
		else
			data->bdq = 1;
		i = work_in_quote(data, qtype, pos);
		data->bsq = 0;
		data->bdq = 0;
		data->lexer_char = data->prompt[data->lexer_check];
		return (i - 2);
	}
	return (0);
}

// lexer pour les str et quotes
int	ft_lexer_str(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = data->lexer_check;
	while (data->prompt && data->prompt[i + j])
	{
//		if (data->prompt[i + j] == '$')
//			get_dollar(data); // refaire get dollar avec en 2eme param, la pos du dollar
		if (data->prompt[i + j] == '\'' || data->prompt[i + j] == '\"')
		{
			if (ft_check_endquote(data, data->prompt[i + j]))
				i += get_quote(data, (i + j));
			else
			{
				error_lexer("no ended quote");
				return (1);
			}
		}
		if (data->prompt[i + j] == '|' || data->prompt[i + j] == '<'
			|| data->prompt[i + j] == '>' || !ft_isspace(data->prompt[i + j]))
			break ;
		if (data->prompt[i + j] != '$' && data->prompt[i + j])
			i++;
	}
	implement_list(data, TOKEN_STRING, i, j);
	while (i--)
		lexer_advance(data);
	data->index_lexer++;
	return (0);
}
