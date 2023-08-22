/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:57:07 by albert            #+#    #+#             */
/*   Updated: 2023/08/22 12:40:42 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findtop(t_movs *movs, t_num *b, int aval)
{
	int	top;
	int	j;
	int	posmaxb;

	top = -2147483648;
	j = 0;
	if (aval > max(b, VAL) || aval < min(b, VAL))
	{
		posmaxb = max(b, POS);
		return (posmaxb);
	}
	else
	{
		while (b)
		{
			if (b->val > top && b->val < aval)
				top = b->val;
			j++;
			b = b->next;
		}
		return (j);
	}
}

int	findcheap(t_num *a, t_num *b)
{
	int		i;
	t_movs	movs;
	t_movs	small;
	int		index;

	i = 0;
	small.tot = 800;
	while (a)
	{
		index = findtop(&movs, b, a->val);
		if (index > (ft_lstsize (b) / 2))
			movs.rrb = ft_lstsize (b) - index;
		else
			movs.rb = index;
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
