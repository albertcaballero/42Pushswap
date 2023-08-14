/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:48:58 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/14 11:39:29 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*create_stack(int argc, char **argv)
{
	t_num	*stack_a;
	t_num	*head;
	
	while (i < argc)
	{
		stack_a->pos = i;
		stack_a->val = atoi(argv[i]);
		stack_a->next = NULL; //find way to chain them
		print_node(stack_a);
		i++;
	}
}

void	sort_few(int count, t_num *stack_a)
{
	if (count == 1)
		sort1(stack_a);
	if (count == 2)
		sort2(stack_a);
	if (count == 3)
		sort3(stack_a);
	if (count == 4)
		sort4(stack_a);
	if (count == 5)
		sort5(stack_a);
}

void	print_node(t_num *node)
{
	write(1, "\n", 1);
	write(1, "pos:", 4);
	ft_putnbr_fd (node->pos, 1);
	write(1, "\n", 1);
	write(1, "val:", 4);
	ft_putnbr_fd (node->val, 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_num	*stack_a;
	int		i;

	i = 1;
	stack_a = malloc(sizeof(t_num));
	if (argc < 2)
		return (write (2, "Error\n", 6));
	if (arg_parse(argc, argv) == -1)
		return (write (2, "Error\n", 6));
	write (1, "---------\ninput ok\n---------\n", 29);
	while (i < argc)
	{
		stack_a->pos = i;
		stack_a->val = atoi(argv[i]);
		stack_a->next = NULL; //find way to chain them
		print_node(stack_a);
		i++;
	}
	if (argc < 6)
		sort_few (argc - 1, stack_a);
//	push_swap (stack_a);
	return (0);
}
