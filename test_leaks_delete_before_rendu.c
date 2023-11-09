/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_leaks_delete_before_rendu.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:23:44 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/04 16:40:13 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	while (42)
	{
		system("leaks minishell");
		sleep(1);
	}
	return (0);
}
