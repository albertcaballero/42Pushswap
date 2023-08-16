/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:50:45 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/16 03:54:24 by albert           ###   ########.fr       */
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
	a = a->next;
	//rotate/swap until min = 1, push b, sort3(a), push a
}

void	sort5(t_num *a)
{
	a = a->next;
	//rotate/swap until min = 1, push b, repeat for min2, sort3(a), sort2(b), push a x2
}
