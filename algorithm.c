/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 00:57:07 by albert            #+#    #+#             */
/*   Updated: 2023/08/21 16:44:35 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findcheap(t_num *a, t_num *b)
{
	int	posmaxb;
	int	i;

	i = 0;
	while (a)
	{
		if (a->val > max(b, VAL) || a->val < min(b, VAL))
		{
			posmaxb = max(b, POS);
			if (posmaxb > (ft_lstsize (b) / 2))
				a->movs = ft_lstsize (b) - posmaxb;
			else
				a->movs = posmaxb;
		}
		else
		{
			
		}
		if (i > (ft_lstsize (a) / 2))
			a->movs += ft_lstsize (a) - i;
		else
			a->movs += i;
		a = a->next;
		i++;
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
