/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:48:20 by alcaball          #+#    #+#             */
/*   Updated: 2023/09/13 13:31:25 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_movements(char *mov, t_num **a, t_num **b)
{
	if (ft_strncmp(mov, "sa\n", 3) == 0)
		*a = sa(*a);
	else if (ft_strncmp(mov, "sb\n", 3) == 0)
		*b = sb(*b);
	else if (ft_strncmp(mov, "ra\n", 3) == 0)
		*a = ra(*a);
	else if (ft_strncmp(mov, "rb\n", 3) == 0)
		*b = rb(*b);
	else if (ft_strncmp(mov, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(mov, "pa\n", 3) == 0)
		*b = push_a(a, *b);
	else if (ft_strncmp(mov, "pb\n", 3) == 0)
		*a = push_b(*a, b);
	else if (ft_strncmp(mov, "rra\n", 4) == 0)
		*a = rra(*a);
	else if (ft_strncmp(mov, "rrb\n", 4) == 0)
		*b = rrb(*b);
	else if (ft_strncmp(mov, "rrr\n", 4) == 0)
		rrr(a, b);
	else if (ft_strncmp(mov, "ss\n", 3) == 0)
		ss(a, b);
	else
		return (write (2, "Error\n", 6));
	return (42);
}

void	freestack(t_num *stack)
{
	t_num	*temp;

	temp = stack;
	while (stack)
	{
		stack = stack->next;
		free (temp);
		temp = stack;
	}
	free(stack);
}

void	checker(t_num *stack_a, t_num *stack_b)
{
	char	*mov;

	mov = get_next_line(0);
	while (mov != NULL)
	{
		if (check_movements(mov, &stack_a, &stack_b) != 42)
			return ;
		free (mov);
		mov = get_next_line(0);
	}
	free (mov);
	if (is_sorted(stack_a) == ORDERED && ft_lstsize(stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	freestack(stack_a);
}

int	main(int argc, char **argv)
{
	t_num	*stack_a;
	t_num	*stack_b;

	argc--;
	stack_b = NULL;
	if (argc < 1)
		return (write (2, "Error\n", 6));
	else if (argc == 1)
	{
		stack_a = splitter(argc, argv);
		if (stack_a == NULL)
			return (write (2, "Error\n", 6));
	}
	else
	{
		stack_a = create_stack(argc, argv, NO_QUOTES);
		if (arg_parse(argc, argv, NO_QUOTES) == -1)
			return (write (2, "Error\n", 6));
	}
	if (check_repeated(stack_a) == REPEATED)
		return (write (2, "Error\n", 6));
	checker(stack_a, stack_b);
	return (0);
}
