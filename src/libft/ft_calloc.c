/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:57:42 by tpaufert          #+#    #+#             */
/*   Updated: 2024/02/27 19:22:15 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> //DEBUG==========================================================

void	*ft_calloc(size_t count, size_t size)
{
//dprintf(2, "\033[33mentering %s (%s:%d)\n", __FUNCTION__, __FILE__,__LINE__);//DEBUG
	void	*ptr;

//	if (!(count && size)) {
//		dprintf(2, "\033[31mWARNING : calloc of size 0\033[33m\n");//DEBUG
//		sleep (1);} //DEBUG
	if (count && (((long)count * (long)size) / count != size)) {
//		dprintf(2, "failed first check\033[0m\n");//DEBUG
		return (NULL);}
//	dprintf(2, "passed first check\n");//DEBUG
	ptr = malloc(count * size);
//	dprintf(2, "malloc of size %li done : %p\n", count * size, ptr);//DEBUG
	if (ptr == NULL) {
//		dprintf(2, "malloc failed\033[0m\n");//DEBUG
		return (NULL);}
//	dprintf(2, "malloc passed\n");//DEBUG
	ft_bzero(ptr, count * size);
//	dprintf(2, "bzeros done\n");//DEBUG
//	dprintf(2, "\033[32mexiting function normaly\033[0m\n");//DEBUG
	return (ptr);
}
