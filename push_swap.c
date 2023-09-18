/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:48:58 by alcaball          #+#    #+#             */
/*   Updated: 2023/09/18 11:57:12 by alcaball         ###   ########.fr       */
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
		stack_a->val = ft_atoi(argv[i]);
		if (i == argc + flag - 1)
			break ;
		stack_a->next = malloc(sizeof(t_num));
		stack_a = stack_a->next;
		i++;
	}
	stack_a->next = NULL;
	return (head);
}

void	print_nodes(t_num	*a)
{
	write(1, "\n--------\n", 10);
	while (a)
	{
		ft_putnbr_fd (a->val, 1);
		write(1, "  ||  ", 6);
		a = a->next;
	}
	write(1, "\n--------\n", 10);
}

t_num	*splitter(int argc, char **argv)
{
	t_num	*stack_a;
	int		i;

	i = 0;
	argv = ft_split(argv[1], 32);
	argc = 0;
	if (argv[argc] == NULL)
		return (NULL);
	while (argv[argc] != NULL)
		argc++;
	if (arg_parse(argc, argv, QUOTES) == -1)
		return (NULL);
	stack_a = create_stack(argc, argv, QUOTES);
	while (argv[i] != NULL)
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
	return (stack_a);
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
	sort (argc, &stack_a, &stack_b);
	freestack(stack_a);
	return (0);
}
