/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:57:07 by albert            #+#    #+#             */
/*   Updated: 2023/08/24 19:29:03 by albert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findtop(t_num *b, int aval) //YOU ARE THE PROBLEM (maybe)
{
	int	top;
	int	j;
	int	pos;

	top = INT_MIN;
	j = 0;
	pos = 0;
	if (aval <= min(b, VAL) || aval >= max(b, VAL))
		pos = max(b, POS);
	else
	{
		while (b)
		{
			if (b->val > top && b->val < aval)
			{
				pos = j;
				top = b->val;
			}
			j++;
			b = b->next;
		}
	}
	return (pos);
}

t_movs	findcheap(t_num *a, t_num *b, int lena, int lenb)
{
	int		i;
	t_movs	movs;
	t_movs	small;

	i = 0;
	small.tot = INT_MAX;
	movs = init_movs();
	while (a)
	{
		if (findtop(b, a->val) >= (lenb / 2))
			movs.rrb = lenb - findtop(b, a->val); //AQUI
		else
			movs.rb = findtop(b, a->val);
		if (i >= (lena / 2))
			movs.rra = lena - i; //AQUI
		else
			movs.ra = i;
		i++;
		movs.tot = movs.ra + movs.rb + movs.rra + movs.rrb;
		if (movs.tot < small.tot)
			small = movs;
		a = a->next;
	}
	return (small);
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
		movs = findcheap(*a, *b, ft_lstsize(*a), ft_lstsize(*b));
		movs = optimize(movs);
		shake_it (movs, a, b);
		*a = push_b (*a, b);
	}
	while (max(*b, POS) != 0)
	{
		if (max(*b, POS) > ft_lstsize(*b) / 2)
			*b = rrb(*b);
		else
			*b = rb(*b);
	}
	while (*b)
		*b = push_a (a, *b);
	print_nodes (*a);
	if (is_sorted(*a) == ORDERED)
		write (1, "ok\n", 3);
	return (*a);
}
