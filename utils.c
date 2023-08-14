/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:39:58 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/14 15:50:41 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	freebird(int *a)
{
	a[0] = 1;
	return (-1);
}

int	min(t_num *stack)
{
	int	min;
	int	pos;

	min = stack->val;
	pos = 0;
	while (stack)
	{
		if (stack->val < min)
			min = stack->val;
		stack = stack->val;
		pos++;
	}
	return (pos);
}

int	max(t_num *stack)
{
	int	max;
	int	pos;

	max = stack->val;
	pos = 0;
	while (stack)
	{
		if (stack->val > max)
			max = stack->val;
		stack = stack->val;
		pos++;
	}
	return (pos);
}
