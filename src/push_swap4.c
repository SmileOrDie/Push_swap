/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 12:06:56 by shamdani          #+#    #+#             */
/*   Updated: 2015/03/23 14:06:29 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_check1(t_nbr *head)
{
	int		save1;
	int		save2;
	t_nbr	*ptr;

	save1 = head->nbr;
	save2 = head->next->nbr;
	ptr = head->next->next;
	if (!(ptr->nbr < ptr->next->nbr) || (save1 < save2) ||
		!(save1 < ptr->nbr) || !(save2 < ptr->nbr))
		return (0);
	while (ptr->next)
	{
		if ((ptr->nbr > ptr->next->nbr) ||
			(save1 > ptr->next->nbr) ||
			(save2 > ptr->next->nbr))
			return (0);
		ptr = ptr->next;
	}
	write(1, "sa\n", 3);
	return (1);
}

int			ft_check2(t_nbr *head)
{
	int		save1;
	int		save2;
	t_nbr	*ptr;

	ptr = head;
	while (ptr->next->next)
		ptr = ptr->next;
	save1 = ptr->nbr;
	save2 = ptr->next->nbr;
	ptr = head;
	if (!(ptr->nbr < ptr->next->nbr) || save1 < save2)
		return (0);
	while (ptr->next->next->next)
	{
		if ((ptr->nbr > ptr->next->nbr) ||
			(save1 < ptr->next->nbr) ||
			(save2 < ptr->next->nbr))
			return (0);
		ptr = ptr->next;
	}
	write(1, "rra rra sa ra ra\n", 17);
	return (1);
}

int			ft_ordered(t_nbr *head, int len)
{
	t_nbr	*ptr;

	if (!head)
		return (-1);
	if (ft_check1(head) || ft_check2(head))
		return (1);
	ptr = head;
	while (ptr->next)
	{
		if (ptr->nbr > ptr->next->nbr)
			return (0);
		ptr = ptr->next;
	}
	return (1);
	len++;
}
