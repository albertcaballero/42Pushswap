/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:50:45 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/16 18:39:42 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_few(int count, t_num **stack_a, t_num	**stack_b)
{
	if (count == 2 || count == 3)
		*stack_a = sort23(stack_a);
	if (count == 4 || count == 5)
		*stack_a = sort45(stack_a, stack_b);
}

t_num	*sort23(t_num **a)
{
	while (is_sorted(*a) != ORDERED)
	{
		if (max(*a) != 0 && (*a)->val > ((*a)->next)->val)
			*a = swap(*a);
		else
			*a = rotate (*a);
	}
	return (*a);
}

t_num	*sort45(t_num **a, t_num **b)
{
	while (ft_lstsize(*a) > 3)
	{
		*a = rotate (*a);
		if (min(*a) == 0)
			*a = push_b (*a, b);
	}
	*a = sort23(a);
	while (*b)
		*b = push_a (a, *b);
	return (*a);
}
