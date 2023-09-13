/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_push_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:07:55 by alcaball          #+#    #+#             */
/*   Updated: 2023/09/13 11:52:05 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_num	*push_b(t_num *stack_a, t_num **stack_b)
{
	t_num	*temp;

	if (ft_lstsize(stack_a) < 1)
		return (stack_a);
	temp = stack_a;
	stack_a = stack_a->next;
	temp->next = *stack_b;
	*stack_b = temp;
	return (stack_a);
}

t_num	*push_a(t_num **stack_a, t_num *stack_b)
{
	t_num	*temp;

	if (ft_lstsize(stack_b) < 1)
		return (stack_b);
	temp = stack_b;
	stack_b = stack_b->next;
	temp->next = *stack_a;
	*stack_a = temp;
	return (stack_b);
}
