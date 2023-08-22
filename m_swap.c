/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:30:57 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/22 16:53:38 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*swap(t_num *stack)
{
	t_num	*temp;

	temp = stack->next;
	stack->next = temp->next;
	temp->next = stack;
	stack = temp;
	return (stack);
}

t_num	*sa(t_num *stack_a)
{
	stack_a = swap(stack_a);
	write(1, "sa\n", 3);
	return (stack_a);
}

t_num	*sb(t_num *stack_b)
{
	stack_b = swap(stack_b);
	write(1, "sb\n", 3);
	return (stack_b);
}

void	ss(t_num **stack_a, t_num **stack_b)
{
	*stack_a = swap(*stack_a);
	*stack_b = swap(*stack_b);
	write (1, "ss\n", 3);
}
