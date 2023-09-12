/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:48:23 by alcaball          #+#    #+#             */
/*   Updated: 2023/09/12 18:13:24 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define ORDERED 1
# define NOT_ORDERED 0

typedef struct s_number
{
	int				val;
	struct s_number	*next;
}	t_num;

t_num	*push_a(t_num **stack_a, t_num *stack_b);
t_num	*push_b(t_num *stack_a, t_num **stack_b);
t_num	*ra(t_num *stack_a);
t_num	*rb(t_num *stack_b);
void	rr(t_num **stack_a, t_num **stack_b);
t_num	*sa(t_num *stack_a);
t_num	*sb(t_num *stack_b);
void	ss(t_num **stack_a, t_num **stack_b);
t_num	*rra(t_num *stack_a);
t_num	*rrb(t_num *stack_b);
void	rrr(t_num **stack_a, t_num **stack_b);
t_movs	init_movs(void);
int		ft_lstsize(t_num *lst);
int		is_sorted(t_num	*stack);