/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:07:55 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/16 18:36:38 by alcaball         ###   ########.fr       */
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
	t_num	*temp;

	temp = stack_a;
	stack_a = stack_a->next;
	temp->next = *stack_b;
	*stack_b = temp;
	return (stack_a);
}

t_num	*push_a(t_num **stack_a, t_num *stack_b)
{
	t_num	*temp;

	temp = stack_b;
	stack_b = stack_b->next;
	temp->next = *stack_a;
	*stack_a = temp;
	return (stack_b);
}