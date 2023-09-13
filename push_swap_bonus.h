/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:48:23 by alcaball          #+#    #+#             */
/*   Updated: 2023/09/13 09:29:49 by albert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define ORDERED 1
# define NOT_ORDERED 0
# define QUOTES 0
# define NO_QUOTES 1
# define REPEATED -1

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
int		ft_lstsize(t_num *lst);
int		is_sorted(t_num	*stack);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);

#endif