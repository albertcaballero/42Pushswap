/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:57:07 by albert            #+#    #+#             */
/*   Updated: 2023/08/21 17:35:00 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findcheap(t_num *a, t_num *b)
{
	int		posmaxb;
	int		i;
	t_movs	movs;
	t_movs	small;
	int		top;
	int		j;

	i = 0;
	top = -2147483648;
	small.tot = 800; //feo de collons, pero es para inicializarla en algo
	while (a)
	{
		if (a->val > max(b, VAL) || a->val < min(b, VAL))
		{
			posmaxb = max(b, POS);
			if (posmaxb > (ft_lstsize (b) / 2))
				movs.rrb = ft_lstsize (b) - posmaxb;
			else
				movs.rb = posmaxb;
		}
		else
		{
			while (b)
			{
				if (b->val > top && b->val < a->val)
					top = b->val;
				j++;
				b = b->next; //AQUI TE QUEDASTE - NOW EITHER RB OR RRB UNTIL TOP->POS = 0
			}
		} //separarlo en funciones
		if (i > (ft_lstsize (a) / 2))
			movs.rra = ft_lstsize (a) - i;
		else
			movs.ra = i;
		a = a->next;
		i++;
		movs.tot = movs.ra + movs.rb + movs.rra + movs.rrb;
		if (movs.tot < small.tot)
			small.tot = movs.tot;
	}
}

// https://medium.com/@ayogun/push-swap-c1f5d2d41e97 
t_num	*algorithm_main(t_num **a, t_num **b)
{
	int	size_a;
	int	maxval;
	int	minval;

	size_a = ft_lstsize (*a);
	push_b(*a, b);
	push_b(*a, b);
	findcheap(*a, *b);
}
