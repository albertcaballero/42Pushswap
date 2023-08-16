/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:48:58 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/16 03:49:01 by albert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*create_stack(int argc, char **argv, int flag)
{
	t_num	*stack_a;
	t_num	*head;
	int		i;

	i = 0;
	if (flag == FLAG_NO_QUOTES)
		i = 1;
	stack_a = malloc(sizeof(t_num));
	head = stack_a;
	while (i < (argc + flag))
	{
		stack_a->pos = i - flag;
		stack_a->val = atoi(argv[i]);
		if (i == argc + flag - 1)
			break;
		stack_a->next = malloc(sizeof(t_num));
		stack_a = stack_a->next;
		i++;
	}
	stack_a->next = NULL;
	return (head);
}

void	sort_few(int count, t_num **stack_a)
{
	if (count == 2 || count == 3)
		*stack_a = sort23(*stack_a);
	if (count == 4)
		sort4(*stack_a);
	if (count == 5)
		sort5(*stack_a);
}

//DELETE
void	print_nodes(t_num *stack)
{
	while (stack)
	{
		write(1, "\n", 1);
		write(1, "pos:", 4);
		ft_putnbr_fd (stack->pos, 1);
		write(1, "\n", 1);
		write(1, "val:", 4);
		ft_putnbr_fd (stack->val, 1);
		write(1, "\n", 1);
		stack = stack->next;
	}
		write(1, "---------\n", 10);
}

int	main(int argc, char **argv)
{
	t_num	*stack_a;
	int		flag;

	argc--;
	if (argc < 1)
		return (write (2, "Error\n", 6));
	flag = FLAG_NO_QUOTES;
	if (argc == 1)
	{
		flag = FLAG_QUOTES;
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
	write (1, "---------\ninput ok\n---------\n", 29);
	print_nodes(stack_a);
	if (is_sorted(stack_a) == ORDERED)
		return (0);
	if (argc < 5)
		sort_few (argc, &stack_a);
	//IF FLAG_QUOTES, FREE(SPLIT)
	//FREE STACK A AL FINAL DEL PROGRAMA
	print_nodes(stack_a);
	return (0);
}
