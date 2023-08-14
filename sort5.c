/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:50:45 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/14 17:44:49 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_num	*sort23(t_num *a)
{
	while (is_sorted(a) != ORDERED)
	{
		printf("MAX: %d\n", max(a));
		if (max(a) != 0 && a->val > (a->next)->val)
		{
			a = swap(a);
			printf("sa\n");	
		}
		else
		{
			a = rotate (a);
			printf("ra\n");
		}
		usleep(10000);
	}
	return (a);
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
