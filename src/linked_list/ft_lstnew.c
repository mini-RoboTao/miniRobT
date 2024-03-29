/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:10:01 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/07 22:31:27 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_lst	*ft_lstnew(t_shape shape)
{
	t_lst	*head;

	head = malloc(sizeof(t_lst));
	if (!head)
		return (NULL);
	head->shape = shape;
	head->next = NULL;
	return (head);
}

t_intersection	*ft_lstnew_ray(double t, t_shape shape, size_t id)
{
	t_intersection	*head;

	head = malloc(sizeof(t_intersection));
	if (!head)
		return (NULL);
	head->t = t;
	head->shape = shape;
	head->next = NULL;
	return (head);
}
