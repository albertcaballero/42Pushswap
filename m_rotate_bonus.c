/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_rotate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:23:21 by albert            #+#    #+#             */
/*   Updated: 2023/09/13 11:06:23 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_num	*rotate(t_num *stack)
{
	t_num	*temp;
	t_num	*head;

	if (ft_lstsize(stack) < 2)
		return (stack);
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
	return (stack_a);
}

t_num	*rb(t_num *stack_b)
{
	stack_b = rotate(stack_b);
	return (stack_b);
}

void	rr(t_num **stack_a, t_num **stack_b)
{
	*stack_a = rotate(*stack_a);
	*stack_b = rotate(*stack_b);
}
