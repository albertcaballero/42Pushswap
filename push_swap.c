/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:48:58 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/01 14:13:50 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //delete


int	main(int argc, char **argv)
{
	int		*a;
	int		i;

	i = 0;
	if (argc < 2)
		return (write (2, "Error\n", 6));
	a = arg_parse(argc, argv);
	while (a[i]) //delete
	{
		printf("%i\n", a[i]);
		i++;
	}
	if (a[0] == -1)
		return (write (2, "Error\n", 6));
	freebird(a);
	return (0);
}
