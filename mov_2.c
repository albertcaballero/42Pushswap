/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:23:21 by albert            #+#    #+#             */
/*   Updated: 2023/08/17 19:02:00 by albert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*ra(t_num *stack_a)
{
	stack_a = rotate(stack_a);
	write(1, "ra\n", 3);
	return (stack_a);
}

t_num	*sa(t_num *stack_a)
{
	stack_a = swap(stack_a);
	write(1, "sa\n", 3);
	return (stack_a);
}

t_num	*rra(t_num *stack_a)
{
	stack_a = rev_rotate(stack_a);
	write (1, "rra\n", 3);
	return (stack_a);
}