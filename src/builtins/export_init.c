/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:24:45 by hguillau          #+#    #+#             */
/*   Updated: 2024/04/24 10:24:47 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Fonction utilitaire pour compter le nombre de variables exportées
int	count_exp(char **cp_exp)
{
	int	count;

	count = 0;
	while (cp_exp[count] != NULL)
		count++;
	return (count);
}

// Fonction utilitaire pour dupliquer les variables exportées dans un tableau
// séparé
char	**duplicate_exp(char **cp_exp, int count)
{
	char	**sorted_exp;
	int		i;

	i = 0;
	sorted_exp = malloc(sizeof(char *) * (count + 1));
	while (i < count)
	{
		sorted_exp[i] = ft_strdup3(cp_exp[i]);
		i++;
	}
	sorted_exp[count] = NULL;
	return (sorted_exp);
}

// Fonction utilitaire pour trier les variables exportées par ordre alphabétique
void	sort_exp(char **sorted_exp, int count)
{
	int		swapped;
	int		num_passes;
	int		j;
	char	*temp;

	swapped = 1;
	num_passes = 0;
	while (swapped)
	{
		swapped = 0;
		j = 0;
		while (j < count - num_passes - 1)
		{
			if (ft_strcmp(sorted_exp[j], sorted_exp[j + 1]) > 0)
			{
				temp = sorted_exp[j];
				sorted_exp[j] = sorted_exp[j + 1];
				sorted_exp[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		num_passes++;
	}
}

// Fonction principale pour ordonner les variables exportées
char	**order_exp(char **cp_env)
{
	int		count;
	char	**sorted_exp;

	count = count_exp(cp_env);
	sorted_exp = duplicate_exp(cp_env, count);
	sort_exp(sorted_exp, count);
	return (sorted_exp);
}
