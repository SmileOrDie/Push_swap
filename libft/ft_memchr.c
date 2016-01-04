/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:17:43 by shamdani          #+#    #+#             */
/*   Updated: 2015/03/23 10:31:57 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char *src2;

	src2 = (unsigned char*)src;
	while (n--)
	{
		if (*src2 == (unsigned char)c)
			return ((void*)src2);
		src2++;
	}
	return (NULL);
}
