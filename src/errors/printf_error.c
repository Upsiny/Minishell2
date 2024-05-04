/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:25:57 by hguillau          #+#    #+#             */
/*   Updated: 2024/05/04 11:25:09 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_error_msg1(char *s1)
{
	if (!s1)
		s1 = "";
	write(2, s1, ft_strlen(s1));
}

void	ft_print_error_msg2(char *s1, char *s2)
{
	if (!s1)
		s1 = "";
	write(2, s1, ft_strlen(s1));
	if (!s2)
		s2 = "";
	write(2, s2, ft_strlen(s2));
}

void	ft_print_error_msg3(char *s1, char *s2, char *s3)
{
	if (!s1)
		s1 = "";
	write(2, s1, ft_strlen(s1));
	if (!s2)
		s2 = "";
	write(2, s2, ft_strlen(s2));
	if (!s3)
		s3 = "";
	write(2, s3, ft_strlen(s3));
}

void	ft_print_error_msg4(char *s1, char *s2, char *s3, char *s4)
{
	if (!s1)
		s1 = "";
	write(2, s1, ft_strlen(s1));
	if (!s2)
		s2 = "";
	write(2, s2, ft_strlen(s2));
	if (!s3)
		s3 = "";
	write(2, s3, ft_strlen(s3));
	if (!s4)
		s4 = "";
	write(2, s4, ft_strlen(s4));
}
