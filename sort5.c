/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:50:45 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/14 16:06:32 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_num *a)
{
	if (a->val > (a->next)->val)
		a = swap (a);
	print_nodes(a);
}

int	sort3(t_num *a)
{
	if (min(a) == 1)
	{
		rotate (a);
		swap (a);
		rerotate (a);
	}
	if (min(a) == 2 && max(a) == 1)
		rotate (a);
	if (min(a) == 2 && max(a) == 3)
		swap (a);
}

int	sort4(t_num *a)
{
	a->val = 5;
	return (1);
}

int	sort5(t_num *a)
{
	a->val = 5;
	return (1);
}
