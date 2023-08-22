/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_revrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:29:39 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/22 17:40:49 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*rev_rotate(t_num *stack)
{
	t_num	*head;
	t_num	*temp;

	temp = stack;
	while ((stack->next)->next)
		stack = stack->next;
	head = stack->next;
	stack->next = NULL;
	head->next = temp;
	return (head);
}

t_num	*rra(t_num *stack_a)
{
	stack_a = rev_rotate(stack_a);
	write (1, "rra\n", 4);
	return (stack_a);
}

t_num	*rrb(t_num *stack_b)
{
	stack_b = rev_rotate(stack_b);
	write(1, "rrb\n", 4);
	return (stack_b);
}

void	rrr(t_num **stack_a, t_num **stack_b)
{
	*stack_a = rev_rotate(*stack_a);
	*stack_b = rev_rotate(*stack_b);
	write (1, "rrr\n", 4);
}
