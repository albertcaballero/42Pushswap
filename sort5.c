/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:50:45 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/16 13:32:44 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*sort23(t_num *a)
{
	while (is_sorted(a) != ORDERED)
	{
		if (max(a) != 0 && a->val > (a->next)->val)
			a = swap(a);
		else
			a = rotate (a);
	}
	return (a);
}

void	sort4(t_num *a)
{
	t_num	*b;

	while (min(a) != 0)
		a = rotate (a);
	b = push_b (&a);
	a = sort23(a);
	a = push_a (b);
}

void	sort5(t_num *a)
{
	while (min(a) != 0)
		a = rotate (a);
	push_b (a);
	while (min(a) != 0)
		a = rotate (a);
	push_b (a);
	a = sort23(a);
	push_a (b);
	push_a (b);
}
