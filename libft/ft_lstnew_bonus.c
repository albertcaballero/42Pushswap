/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:50:00 by alcaball          #+#    #+#             */
/*   Updated: 2023/08/12 14:39:32 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*pepe;

	pepe = malloc (sizeof(t_list));
	if (!pepe)
		return (NULL);
	pepe->content = content;
	pepe->next = NULL;
	return (pepe);
}
