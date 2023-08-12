/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:48:58 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/12 13:25:09 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //delete

//(array to stack) converts input text to nodes on the stack
// t_num	atost(char **arr)
// {
	
// }

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (write (2, "Error\n", 6));
	if (arg_parse(argc, argv) == -1)
		return (write (2, "Error\n", 6));
	write (1, "input ok\n", 8);
	// atost(argv[0]);
	// freebird(a);
	return (0);
}
