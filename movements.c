/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:07:55 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/17 18:56:44 by albert           ###   ########.fr       */
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

t_num	*push_b(t_num *stack_a, t_num **stack_b)
{
	t_num	*temp;

	temp = stack_a;
	stack_a = stack_a->next;
	temp->next = *stack_b;
	*stack_b = temp;
	write (1, "pb\n", 3);
	return (stack_a);
}

t_num	*push_a(t_num **stack_a, t_num *stack_b)
{
	t_num	*temp;

	temp = stack_b;
	stack_b = stack_b->next;
	temp->next = *stack_a;
	*stack_a = temp;
	write (1, "pa\n", 3);
	return (stack_b);
}
