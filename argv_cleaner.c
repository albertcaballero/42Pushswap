/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:35:24 by alcaball          #+#    #+#             */
/*   Updated: 2023/07/27 14:32:32 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**arg_parse(int argc, char **argv)
{
	int	i;
	int	j;
	int	*a;

	i = 1;
	while (argv[i] != NULL)
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
	a = malloc(sizeof(int) * i);
	j = 0;
	i = 0;
	while (argv[i + 1] != NULL)
	{
		a[i] = atoi(argv[i + 1]);
		i++;
	}
	return (a);
}
