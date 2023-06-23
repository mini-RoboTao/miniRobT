/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:33:23 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/18 19:15:41 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_lstclean(t_lst **l, void (*del)(t_object *))
{
	t_lst	*head;
	t_lst	*next;

	head = *l;
	next = *l;
	while (next)
	{
		next = head->next;
		del(head->obj);
		if (head)
			free(head);
		head = next;
	}
	*l = NULL;
}
