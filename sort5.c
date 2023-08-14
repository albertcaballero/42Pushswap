/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:50:45 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/14 17:13:24 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort23(t_num *a)
{
	while (is_sorted(a) != 1)
	{
		if (max(a) == 1 && a->val > (a->next)->val)
			swap(a);
		else
			rotate (a);
		a = a->next;
	}
}

void	sort4(t_num *a)
{
	a = NULL;
	//rotate/swap until min = 1, push b, sort3(a), push a
}

void	sort5(t_num *a)
{
	a = NULL;
	//rotate/swap until min = 1, push b, repeat for min2, sort3(a), sort2(b), push a x2
}
