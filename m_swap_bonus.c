/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_swap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:30:57 by alcaball          #+#    #+#             */
/*   Updated: 2023/09/13 11:52:47 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_num	*swap(t_num *stack)
{
	t_num	*temp;

	if (ft_lstsize(stack) < 2)
		return (stack);
	temp = stack->next;
	stack->next = temp->next;
	temp->next = stack;
	stack = temp;
	return (stack);
}

t_num	*sa(t_num *stack_a)
{
	stack_a = swap(stack_a);
	return (stack_a);
}

t_num	*sb(t_num *stack_b)
{
	stack_b = swap(stack_b);
	return (stack_b);
}

void	ss(t_num **stack_a, t_num **stack_b)
{
	*stack_a = swap(*stack_a);
	*stack_b = swap(*stack_b);
}
