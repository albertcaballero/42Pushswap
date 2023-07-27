/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:35:24 by alcaball          #+#    #+#             */
/*   Updated: 2023/07/27 17:13:49 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int clean_start(char *num)
{
	int	j;
	int	flag;

	j = 0;
	flag = 1;
	if (num[0] == 45 || num[0] == 43)
		if (num[0] == 45)
			flag = -1;
	while (num[j] == 48)
		j++;
	if (ft_strlen(&num[j]) > 10)
		return (-1);
}

int	*arg_parse(int argc, char **argv)
{
	int		i;
	int		j;
	long	temp;
	int		*a;

	i = 1;
	while (i <= argc)
	{
		argv[i]
		temp = atol(argv[i]);

	}
	return (a);
}

int	check_repeated(int *a, int count)
{
	int	val;
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		val = a[i];
		j = 0;
		while (j < count)
		{
			if (a[j] == val)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_intrange(int *a, int count)
{
	int	i;

	i = 1;
	while (i < count)
	{
		if (argv[i] >)

	}
}




/*
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
	if (check_repeated(a, argc - 1) == 1 || check_intrange(a, argc - 1) == 1)
		return (-1);
	return (a);
}
*/