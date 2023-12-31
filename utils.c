/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:39:58 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/23 13:08:01 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_movs	init_movs(void)
{
	t_movs	movs;

	movs.ra = 0;
	movs.rb = 0;
	movs.rr = 0;
	movs.rra = 0;
	movs.rrb = 0;
	movs.rrr = 0;
	movs.tot = 0;
	return (movs);
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
	else
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
	else
		return (max);
}
