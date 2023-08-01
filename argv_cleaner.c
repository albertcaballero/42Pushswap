/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:35:24 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/01 14:12:24 by alcaball         ###   ########.fr       */
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
		if (is_digit(num[j]) == 0)
			return (-1);
		j++;
	}
	return (0);
}

int	*arg_parse(int argc, char **argv)
{
	int		i;
	long	temp;
	int		*a;

	i = 1;
	while (i <= argc)
	{
		if (clean_start(argv[i]) == -1)
			return (-1);
		if (check_repeated(argv, argc - 1) == -1)
			return (-1);
		temp = atol(argv[i]);
		if (temp > 2147483647 || temp < -2147483648)
			return (-1);
	}
	a = malloc(sizeof(int *) * (argc - 1));
	i = 0;
	while (i < argc)
	{
		a[i] = malloc(sizeof(int));
		a[i] = atoi(argv[i + 1]);
		i++;
	}
	return (a);
}

int	check_repeated(char **a, int count)
{
	int		i;
	int		j;

	i = 1;
	while (i < count)
	{
		j = 1;
		while (j < count)
		{
			if (a[i] == a[j] && i != j)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
