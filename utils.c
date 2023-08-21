/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:39:58 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/21 15:40:03 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*put_index(t_num *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		stack->pos = index;
		index++;
		stack = stack->next;
	}
	return (stack);
}

int	ft_lstsize(t_num *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
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

int	min(t_num *stack, int flag)
{
	int	min;
	int	pos;
	int	posmin;

	min = stack->val;
	pos = 0;
	posmin = 0;
	while (stack)
	{
		if (stack->val < min)
		{
			posmin = pos;
			min = stack->val;
		}
		stack = stack->next;
		pos++;
	}
	if (flag == POS)
		return (posmin);
	if (flag == VAL)
		return (min);
}

int	max(t_num *stack, int flag)
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
	if (flag == POS)
		return (posmax);
	if (flag == VAL)
		return (max);
}
