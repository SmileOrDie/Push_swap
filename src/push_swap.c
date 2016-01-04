/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 15:34:34 by shamdani          #+#    #+#             */
/*   Updated: 2015/03/24 11:34:00 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					is_digit(char *src)
{
	int		i;

	i = (src[0] == '-') ? 0 : -1;
	while (src[++i])
		if (!ft_isdigit(src[i]))
			return (0);
	if (i > 11)
		return (0);
	return (1);
}

int					check_argc(char **av)
{
	int		i;

	i = 1;
	if (!av[i + 1])
		return (1);
	while (av[i])
	{
		if (!is_digit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

static void			ft_proc(int pos, int tmp, int len)
{
	static int		a;
	static int		b;
	static char		*str;

	if (tmp == pos)
		return ;
	if (tmp > pos)
	{
		a = tmp - pos;
		b = len - tmp + pos;
		str = (a <= b) ? "ra " : "rra ";
	}
	else
	{
		a = pos - tmp;
		b = len - pos + tmp;
		str = (a <= b) ? "rra " : "ra ";
	}
	a = (a <= b) ? a : b;
	b = (*(str + 1) == 'r') ? 4 : 3;
	while (a--)
		write(1, str, b);
}

void				order_proc(t_nbr **nbr, unsigned int len)
{
	int				pos;
	int				nextpos;
	int				tmp;

	pos = 0;
	while (len > 3)
	{
		nextpos = low_pop(nbr);
		ft_proc(pos, nextpos, len);
		pos = nextpos;
		len--;
		if ((unsigned int)pos >= len)
			pos = 0;
		write(1, "pb ", 3);
	}
	if (pos == 0)
		tmp = ft_order((*nbr)->nbr, (*nbr)->next->nbr, (*nbr)->next->next->nbr);
	else if (pos == 1)
		tmp = ft_order((*nbr)->next->nbr, (*nbr)->next->next->nbr, (*nbr)->nbr);
	else
		tmp = ft_order((*nbr)->next->next->nbr, (*nbr)->nbr, (*nbr)->next->nbr);
	if (tmp)
		write (1, " ", 1);
}

int					main(int ac, char **av)
{
	t_nbr			*nbr;
	unsigned int	len;
	char			v;

	if (ac <= 2 || !check_argc(av) || !check_double(av))
	{
		if ((av[1] && !is_digit(av[1])) || !check_double(av))
			ft_putstr_fd("Error\n", 2);
		return (0);
	}
	else if (ac == 3)
		return (check_conf(av));
	else if (ac == 4)
		return (ft_order(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3])));
	len = creat_list(av, &nbr, 0);
	if ((v = ft_ordered(nbr, len)) == -1 || v == 1)
		return ((v == 1) ? 0 : write(2, "Error\n", 6));
	if (v == 1)
		return (0);
	order_proc(&nbr, len);
	end_main(len);
	return (0);
}
