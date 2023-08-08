/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:19:49 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/07 23:25:17 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_lst	*ft_lstlast(t_lst *l)
{
	t_lst	*tail;

	if (!l)
		return (NULL);
	while (l)
	{
		tail = l;
		l = l->next;
	}
	return (tail);
}

t_intersection	*ft_lstray_last(t_intersection *l)
{
	t_intersection	*tail;

	if (!l)
		return (NULL);
	while (l)
	{
		tail = l;
		l = l->next;
	}
	return (tail);
}
