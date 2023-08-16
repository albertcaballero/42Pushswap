/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:50:45 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/16 14:02:36 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_few(int count, t_num **stack_a, t_num	**stack_b)
{
	if (count == 2 || count == 3)
		sort23(stack_a);
	if (count == 4 || count == 5)
		sort45(stack_a, stack_b);
}

t_num	*sort23(t_num **a)
{
	while (is_sorted(a) != ORDERED)
	{
		if (max(a) != 0 && (*a)->val > ((*a)->next)->val)
			swap(a);
		else
			rotate (a);
	}
}

void	*sort45(t_num **a, t_num **b)
{
	while (ft_lstsize(*a) > 3)
	{
		rotate (a);
		if (min(a) == 0)
			push_b (a, b);
	}
	sort23(a);
	while (b)
		push_a (b);
}
