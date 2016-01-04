/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 15:39:09 by shamdani          #+#    #+#             */
/*   Updated: 2015/03/24 11:30:18 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct		s_nbr
{
	int				nbr;
	struct s_nbr	*next;
}					t_nbr;

int					ft_atoi2(const char *str, char *error);
int					ft_order(int a, int b, int c);
int					check_conf(char **str);
unsigned int		creat_list(char **str, t_nbr **nbr, unsigned int len);
int					low_pop(t_nbr **nbr);
int					ft_ordered(t_nbr *head, int len);
int					check_double(char **str);
void				end_main(int len);

#endif
