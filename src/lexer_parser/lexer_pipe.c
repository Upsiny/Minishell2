/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:31:21 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:31:26 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_lexer_pipe(t_data *data)
{
	int	j;

	j = data->lexer_check;
	if (data->prompt[j + 1] == data->lexer_char)
	{
		error_lexer("syntax error near unexpected token `||'");
		return (1);
	}
	else
	{
		implement_list(data, TOKEN_PIPE, 1, j);
		data->index_lexer++;
		lexer_advance(data);
		return (0);
	}
}
