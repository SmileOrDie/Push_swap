/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:16:48 by shamdani          #+#    #+#             */
/*   Updated: 2015/03/23 10:34:03 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	*s2;

	s2 = (char*)s;
	while (*s)
	{
		if (*s == (unsigned char)c)
			return (s2);
		s2++;
	}
	if (c == '\0')
		return (s2);
	return (NULL);
}
