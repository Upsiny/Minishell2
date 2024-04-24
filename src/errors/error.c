/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:25:45 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:25:47 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// ne pas oublier de recuperer dans le bash les numeros derreur pour que les
// erreurs de minishell coincident au bash;
void	error_lexer(char *msg)
{
	printf("%s\n", msg);
}

int	ft_error_parsing(char *msg)
{
	printf("%s\n", msg);
	return (1);
}

void	ft_error_msg(char *msg)
{
	printf("%s\n", msg);
	exit(0);
}
