/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:07:55 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/16 17:04:09 by alcaball         ###   ########.fr       */
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

t_num	*push_b(t_num *stack_a, t_num **stack_b)
{
	*stack_b = stack_a;
	stack_a = stack_a->next;
	(*stack_b)->next = NULL;
	return (stack_a);
}

t_num	*push_a(t_num **stack_a, t_num *stack_b)
{
	*stack_a = stack_b;
	stack_b = (stack_b)->next;
	(*stack_a)->next = NULL;
	return (stack_b);
}