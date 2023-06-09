/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:10:01 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/28 21:19:11 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_lst	*ft_lstnew(t_object *obj)
{
	t_lst	*head;

	head = malloc(sizeof(t_lst));
	if (!head)
		return (NULL);
	head->obj = obj;
	head->next = NULL;
	return (head);
}
