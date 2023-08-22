/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:48:58 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/22 17:42:30 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*create_stack(int argc, char **argv, int flag)
{
	t_num	*stack_a;
	t_num	*head;
	int		i;

	i = 0;
	if (flag == NO_QUOTES)
		i = 1;
	stack_a = malloc(sizeof(t_num));
	head = stack_a;
	while (i < (argc + flag))
	{
		stack_a->val = atoi(argv[i]);
		if (i == argc + flag - 1)
			break ;
		stack_a->next = malloc(sizeof(t_num));
		stack_a = stack_a->next;
		i++;
	}
	stack_a->next = NULL;
	return (head);
}

//DELETE
void	print_nodes(t_num *stack)
{
	write(1, "\n---------\n", 11);
	while (stack)
	{
		ft_putnbr_fd (stack->val, 1);
		write(1, "  ||  ", 6);
		stack = stack->next;
	}
	write(1, "\n---------\n", 11);
}

int	main(int argc, char **argv)
{
	t_num	*stack_a;
	t_num	*stack_b;
	int		flag;

	argc--;
	stack_b = NULL;
	if (argc < 1)
		return (write (2, "Error\n", 6));
	flag = NO_QUOTES;
	if (argc == 1)
	{
		flag = QUOTES;
		argv = ft_split(argv[1], 32);
		argc = 0;
		while (argv[argc] != NULL)
			argc++;
	}
	if (arg_parse(argc, argv) == -1)
		return (write (2, "Error\n", 6));
	stack_a = create_stack(argc, argv, flag);
	if (check_repeated(stack_a) == REPEATED)
		return (write (2, "Error\n", 6));
	print_nodes(stack_a);
	if (is_sorted(stack_a) == ORDERED)
		return (0);
	if (argc <= 5)
		sort_few (argc, &stack_a, &stack_b);
	else
		stack_a = algorithm (&stack_a, &stack_b);
	print_nodes(stack_a);
	//IF FLAG_QUOTES, FREE(SPLIT)
	//FREE STACK A AL FINAL DEL PROGRAMA
	return (0);
}
