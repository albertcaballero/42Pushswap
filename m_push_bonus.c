/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_push_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:07:55 by alcaball          #+#    #+#             */
/*   Updated: 2023/09/12 18:11:42 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
