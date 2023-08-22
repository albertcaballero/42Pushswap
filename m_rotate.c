/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:23:21 by albert            #+#    #+#             */
/*   Updated: 2023/08/22 15:44:32 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*rotate(t_num *stack)
{
	t_num	*temp;
	t_num	*head;

	head = stack->next;
	temp = stack;
	while (stack->next)
		stack = stack->next;
	stack->next = temp;
	temp->next = NULL;
	return (head);
}

t_num	*ra(t_num *stack_a)
{
	stack_a = rotate(stack_a);
	write(1, "ra\n", 3);
	return (stack_a);
}

t_num	*rb(t_num *stack_b)
{
	stack_b = rotate(stack_b);
	write(1, "rb\n", 3);
	return (stack_b);
}

t_num	*rr(t_num **stack_a, t_num **stack_b)
{
	stack_a = rotate(*stack_a);
	stack_b = rotate(*stack_b);
	write (1, "rr\n", 3);
}
