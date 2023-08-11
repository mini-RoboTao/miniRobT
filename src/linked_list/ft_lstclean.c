/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:33:23 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/11 06:26:03 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_lstclean(t_lst **l, void (*del)(void *))
{
	t_lst	*head;
	t_lst	*next;

	head = *l;
	next = *l;
	while (next)
	{
		next = head->next;
		del(head->shape.any);
		if (head)
			free(head);
		head = next;
	}
	*l = NULL;
}

void	ft_only_lstclean(t_lst **l)
{
	t_lst	*head;
	t_lst	*next;

	head = *l;
	next = *l;
	while (next)
	{
		next = head->next;
		if (head)
			free(head);
		head = next;
	}
	*l = NULL;
}

void	clean_intersection_lst(t_intersection **l)
{
	t_intersection	*head;
	t_intersection	*next;

	head = *l;
	next = *l;
	while (next)
	{
		next = head->next;
		if (head)
			free(head);
		head = next;
	}
	l = NULL;
}
