/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 11:48:39 by shamdani          #+#    #+#             */
/*   Updated: 2015/03/23 14:31:11 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	creat_list(char **str, t_nbr **nbr, unsigned int len)
{
	t_nbr		*ret;
	int			i;

	i = (ft_strcmp(str[1], "-v") == 0) ? 2 : 1;
	if (!(*nbr = (t_nbr *)malloc(sizeof(t_nbr))))
		return (0);
	ret = *nbr;
	len = 0;
	while (str[i])
	{
		ret->nbr = ft_atoi(str[i]);
		if (str[i + 1])
		{
			if (!(ret->next = (t_nbr *)malloc(sizeof(t_nbr))))
				return (0);
			ret = ret->next;
		}
		i++;
		len++;
	}
	ret->next = NULL;
	return (len);
}

int				low_pop2(t_nbr *ret, t_nbr *low, t_nbr **nbr)
{
	if (low == *nbr)
	{
		*nbr = (*nbr)->next;
		free(low);
		return (0);
	}
	ret = *nbr;
	while (ret->next != low)
		ret = ret->next;
	ret->next = low->next;
	free(low);
	return (1);
}

int				low_pop(t_nbr **nbr)
{
	t_nbr		*ret;
	t_nbr		*low;
	int			i;
	int			place;

	if (!*nbr)
		return (0);
	ret = *nbr;
	low = ret;
	i = 0;
	place = 0;
	while (ret)
	{
		ret = ret->next;
		if (ret && low->nbr > ret->nbr)
		{
			place = i + 1;
			low = ret;
		}
		i++;
	}
	if (low_pop2(ret, low, nbr) == 0)
		return (0);
	return (place);
}
