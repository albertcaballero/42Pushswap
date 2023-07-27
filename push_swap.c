/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:48:58 by alcaball          #+#    #+#             */
/*   Updated: 2023/07/27 14:55:15 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap()
{

}

int	main(int argc, char **argv)
{
	int		*a;

	if (argc < 2)
		return (write (2, "Error\n", 6));
	a = arg_parse(argc, argv);
	if (a == -1)
		return (write (2, "Error\n", 6));
	return (0);
}
