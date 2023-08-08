/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:42:59 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/07 23:30:46 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_lstremove(t_lst **l, t_shape rm)
{
	t_lst	*head;
	t_lst	*tmp;

	if (*l && rm.v && (*l)->shape.v == rm.v)
	{
		head = (*l)->next;
		if (*l)
			free(*l);
		*l = head;
		return ;
	}
	head = *l;
	while (head)
	{
		if (head->next && head->next->shape.v == rm.v)
		{
			tmp = head->next->next;
			if (head->next)
				free(head->next);
			head->next = tmp;
			return ;
		}
		head = head->next;
	}
}
