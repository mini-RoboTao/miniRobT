/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparency_and_refraction.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:19:54 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/07 23:24:21 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	determining_n(t_lst *containers)
{
	if (!containers)
		return (1.0);
	else
		return (ft_lstlast(containers)->shape.any->material.refractive_index);
}

int	shape_in_the_lst(t_lst *lst, t_shape find)
{
	while (lst)
	{
		if (lst->shape.v == find.v)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	determining_n1_and_n2(t_intersections *xs, t_intersection *hit, \
		t_precomp *comps)
{
	t_lst			*containers;
	t_intersection	*head;

	containers = NULL;
	head = xs->i;
	while (head)
	{
		if (head == hit)
			comps->n1 = determining_n(containers);
		if (shape_in_the_lst(containers, head->shape))
			ft_lstremove(&containers, head->shape);
		else
			ft_lstadd_back(&containers, ft_lstnew(head->shape));
		if (head == hit)
		{
			comps->n2 = determining_n(containers);
			ft_only_lstclean(&containers);
			break ;
		}
		head = head->next;
	}
}
