/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:50:45 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/01 17:11:19 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort2(int *arr)
{
	int	temp;

	if (arr[0] > arr[1])
	{
		temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	}
	return (arr);
}

int	*sort3(int *arr)
{
	int	min;

	min = fmin(arr);
	temp = arr[0]
	arr[0] = arr[]
	//el min en pos1, los otros 2 es un sort2
}