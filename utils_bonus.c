/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:39:58 by alcaball          #+#    #+#             */
/*   Updated: 2023/09/13 12:14:47 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	ft_lstsize(t_num *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	is_sorted(t_num	*stack)
{
	while (stack->next)
	{
		if (stack->val > (stack->next)->val)
			return (NOT_ORDERED);
		stack = stack->next;
	}
	return (ORDERED);
}
