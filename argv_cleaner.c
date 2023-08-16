/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:35:24 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/16 03:51:35 by albert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	clean_start(char *num)
{
	int	j;

	j = 0;
	if (num[0] == 45 || num[0] == 43)
		j++;
	while (num[j] == 48)
		j++;
	if (ft_strlen(&num[j]) > 10)
		return (-1);
	j = 0;
	while (num[j] != 0)
	{
		if (ft_isdigit(num[j]) == 0 && (num[0] != 45 && num[0] != 43))
			return (-1);
		j++;
	}
	return (0);
}

int	check_repeated(t_num *stack)
{
	int		temp;
	t_num 	*second;

	while (stack)
	{
		temp = stack->val;
		second = stack;
		while (second)
		{
			if (temp == second->val && second != stack)
				return (-1);
			second = second->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	arg_parse(int argc, char **argv)
{
	int		i;
	long	temp;

	i = 1;
	while (i < argc)
	{
		if (clean_start(argv[i]) == -1)
			return (-1);
		temp = ft_atol(argv[i]);
		if (temp > 2147483647 || temp < -2147483648)
			return (-1);
		i++;
	}
	return (0);
}

