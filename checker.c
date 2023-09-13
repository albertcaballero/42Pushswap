/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:48:20 by alcaball          #+#    #+#             */
/*   Updated: 2023/09/13 09:29:27 by albert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	checker(t_num *stack_a, t_num *stack_b)
{
	char	*mov;

	mov = malloc (sizeof(char) * (3 + 1));
	while (mov != NULL)
	{
		mov = get_next_line(1);
		if (ft_strncmp(mov, "sa\n", 3) == 0)
			stack_a = sa(stack_a);
		if (ft_strncmp(mov, "sb\n", 3) == 0)
			stack_b = sb(stack_b);
		if (ft_strncmp(mov, "ra\n", 3) == 0)
			stack_a = ra(stack_a);
		if (ft_strncmp(mov, "rb\n", 3) == 0)
			stack_b = rb(stack_b);
		if (ft_strncmp(mov, "rr\n", 3) == 0)
			rr(&stack_a, &stack_b);
		if (ft_strncmp(mov, "pa\n", 3) == 0)
			stack_b = push_a(&stack_a, stack_b);
		if (ft_strncmp(mov, "pb\n", 3) == 0)
			stack_a = push_b(stack_a, &stack_b);
		if (ft_strncmp(mov, "rra\n", 4) == 0)
			stack_a = rra(stack_a);
		if (ft_strncmp(mov, "rrb\n", 4) == 0)
			stack_b = rrb(stack_b);
		if (ft_strncmp(mov, "rrr\n", 4) == 0)
			rrr(&stack_a, &stack_b);
	}
	if (is_sorted(stack_a) == ORDERED)
		write(1, "ok\n", 3);
	else
		write(1, "ko\n", 3);
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
	freestack(stack_a);
	return (0);
}

/*
create stack from argv (igual que el main)
read from stdout in while
	strncmp with each of the movements
	execute movement
		los movs no tienen que imprimir nada
is sorted == true then OK
*/