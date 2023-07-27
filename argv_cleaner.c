/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:35:24 by alcaball          #+#    #+#             */
/*   Updated: 2023/07/27 15:01:47 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*arg_parse(int argc, char **argv)
{
	int	i;
	int	j;
	int	*a;

	i = 1;
	while (i <= argc)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			if (isdigit(argv[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	a = malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (i < argc)
	{
		a[i] = atoi(argv[i + 1]);
		i++;
	}
	if (check_repeated(a, argc - 1) == 1)
		return (-1);
	return (a);
}

int	check_repeated(int *a, int count)
{
	int	val;
	int	i;

	while (i < count)
	{
		val = a[i];
		i++;
		if (a[i] == val)
			return (1);
	}
	return (0);
}
