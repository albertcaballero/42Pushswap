/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:49:06 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/24 19:02:44 by albert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define QUOTES 0
# define NO_QUOTES 1
# define ORDERED 1
# define NOT_ORDERED 0
# define REPEATED -1
# define POS 1
# define VAL 0

typedef struct s_movements
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rrr;
	int	rr;
	int	tot;
}	t_movs;

typedef struct s_number
{
	int				val;
	struct s_number	*next;
}	t_num;

int		arg_parse(int argc, char **argv, int flag);
int		check_repeated(t_num *stack);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
int		ft_lstsize(t_num *lst);
void	sort(int count, t_num **stack_a, t_num	**stack_b);
t_num	*sort23(t_num **a);
t_num	*sort45(t_num **a, t_num **b);
char	**ft_split(char const *s, char c);
int		min(t_num *stack, int flag);
int		max(t_num *stack, int flag);
int		is_sorted(t_num	*stack);
t_num	*algorithm(t_num **a, t_num **b);
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
void	print_nodes(t_num	*a);
int		ft_printf(const char *str, ...);

#endif