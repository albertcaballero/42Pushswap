/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:57:07 by albert            #+#    #+#             */
/*   Updated: 2023/08/22 18:14:21 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findtop(t_num *b, int aval)
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

t_movs	findcheap(t_num *a, t_num *b)
{
	int		i;
	t_movs	movs;
	t_movs	small;
	int		index;

	i = 0;
	small.tot = INT_MAX;
	movs = init_movs();
	while (a)
	{
		index = findtop(b, a->val);
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
	return (movs);
}

t_movs	optimize(t_movs movs)
{
	if (movs.ra >= movs.rb)
	{
		movs.rr = movs.rb;
		movs.ra = movs.ra - movs.rb;
		movs.rb = 0;
	}
	else
	{
		movs.rr = movs.ra;
		movs.rb = movs.rb - movs.ra;
		movs.ra = 0;
	}
	if (movs.rra >= movs.rrb)
	{
		movs.rrr = movs.rrb;
		movs.rra = movs.rra - movs.rrb;
		movs.rrb = 0;
	}
	else
	{
		movs.rrr = movs.rra;
		movs.rrb = movs.rrb - movs.rra;
		movs.rra = 0;
	}
	return (movs);
}

void	shake_it(t_movs movs, t_num	**a, t_num **b)
{
	while (movs.rr-- > 0)
		rr (a, b);
	while (movs.rrr-- > 0)
		rrr (a, b);
	while (movs.ra-- > 0)
		*a = ra (*a);
	while (movs.rb-- > 0)
		*b = rb (*b);
	while (movs.rra-- > 0)
		*a = rra (*a);
	while (movs.rrb-- > 0)
		*b = rrb (*b);
}

t_num	*algorithm(t_num **a, t_num **b)
{
	t_movs	movs;

	*a = push_b(*a, b);
	*a = push_b(*a, b);
	while (*a)
	{
		movs = findcheap(*a, *b);
		movs = optimize(movs);
		shake_it (movs, a, b);
		*a = push_b (*a, b);
	}
	while (max(*b, POS) != 0) //AQUI - A LO MEJOR EL RRB LO HACE MAL O SINO EL OPTIMIZE/FINDCHEAP
		*b = rb(*b);
	print_nodes (*b);
	while (*b)
		*b = push_a (a, *b);
	if (is_sorted(*a) == ORDERED)
		write (1, "----ok----\n", 11);
	else
		write (1, "----no----\n", 11);
	return (*a);
}
