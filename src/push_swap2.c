/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 23:00:11 by shamdani          #+#    #+#             */
/*   Updated: 2015/03/24 11:35:00 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					ft_atoi2(const char *str, char *error)
{
	static double	value;
	static double	max;
	static int		sign;

	if (!str)
		return ((int)(*error = 1));
	sign = 1;
	if (*str == '+')
		str++;
	else if (*str == '-' && str++)
		sign = -1;
	max = (sign == 1) ? 2147483647 : 2147483648;
	if (!(*str >= '0' && *str <= '9'))
		return ((int)(*error = 1));
	value = 0;
	while (*str && (*str >= '0' && *str <= '9'))
		if (((value = value * 10 + *str++ - '0') > max))
			return ((int)(*error = 1));
	if (*str)
		return ((int)(*error = 1));
	return (value * sign);
}

int					ft_order(int a, int b, int c)
{
	if (a <= b && b <= c)
		return (0);
	else if (a >= b && b <= c && a <= c)
		return (write(1, "sa", 2));
	else if (a <= b && b >= c && a >= c)
		return (write(1, "rra", 3));
	else if (a >= b && b <= c && a >= c)
		return (write(1, "ra", 2));
	else if (a >= b && b >= c && a >= c)
		return (write(1, "ra sa", 5));
	else if (a <= b && b >= c && a <= c)
		return (write(1, "rra sa", 6));
	return (write(1, "Error", 5));
}

int					check_conf(char **str)
{
	int				i;

	i = 1;
	if (str[i + 1])
	{
		if (atoi(str[i]) > atoi(str[i + 1]) && i == 2)
		{
			write(1, "a = ", 4);
			ft_putnbr(ft_atoi(str[i + 1]));
			write(1, " ", 1);
			ft_putnbr(ft_atoi(str[i]));
			write(1, "\nb = ", 5);
			write(1, "\nsa", 3);
		}
		if (atoi(str[i]) > atoi(str[i + 1]) && i == 1)
			write(1, "sa", 2);
	}
	return (0);
}

int					check_double(char **str)
{
	int				i;
	int				j;
	int				tmp;
	char			error;

	error = 0;
	i = 1;
	while (str[i])
	{
		j = i + 1;
		tmp = ft_atoi2(str[i], &error);
		if (error == 1)
			return (0);
		while (str[j])
		{
			if (ft_atoi(str[j]) == tmp)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void				end_main(int len)
{
	len -= 4;
	while (len--)
		write(1, "pa ", 3);
	write(1, "pa\n", 3);
}
