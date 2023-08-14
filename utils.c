/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:39:58 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/14 17:47:45 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	freebird(int *a)
{
	a[0] = 1;
	return (-1);
}

int	is_sorted(t_num	*stack)
{
	while (stack->next)
	{
		if (stack->val > (stack->next)->val)
			return (NOT_ORDERED);
		stack = stack->next;
	}
	return (ORDERED);
}

int	min(t_num *stack) //mal
{
	int	min;
	int	pos;

	min = stack->val;
	pos = 0;
	while (stack)
	{
		if (stack->val < min)
			min = stack->val;
		stack = stack->next;
		pos++;
	}
	return (pos);
}

int	max(t_num *stack)
{
	int	max;
	int	pos;
	int	posmax;

	max = stack->val;
	posmax = 0;
	pos = 0;
	while (stack)
	{
		if (stack->val > max)
		{
			posmax = pos;
			max = stack->val;
		}
		stack = stack->next;
		pos++;
	}
	return (posmax);
}
