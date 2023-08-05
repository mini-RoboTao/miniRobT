/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:28:51 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/05 18:44:11 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_lstadd_back(t_lst **l, t_lst *new)
{
	t_lst	*tail;

	if (!l || !new)
		return ;
	tail = ft_lstlast(*l);
	if (tail == NULL)
		*l = new;
	else
		tail->next = new;
}

void	ft_lstrayadd_back(t_intersection **l, t_intersection *new)
{
	t_intersection	*tail;

	if (!l || !new)
		return ;
	tail = ft_lstray_last(*l);
	if (tail == NULL)
		*l = new;
	else
		tail->next = new;
}

void	ft_lst_ray_sort_add(t_intersection **l, t_intersection *new)
{
	t_intersection	*temp;

	if (!l || !new)
		return ;
	temp = *l;
	if (!*l)
	{
		*l = new;
		return ;
	}
	else if (new->t <= (*l)->t)
	{
		*l = new;
		new->next = temp;
		return ;
	}
	while (temp->next && new->t > temp->t && !(new->t < temp->next->t))
		temp = temp->next;
	if (!temp->next)
		temp->next = new;
	else
	{
		new->next = temp->next;
		temp->next = new;
	}
}

// void	ft_lst_ray_sort_add(t_intersection **l, t_intersection *new)
// {
// 	t_intersection	*temp;
// 	// t_intersection	*lst;

// 	// lst = *l;
// 	if (!l || !new)
// 		return ;
// 	temp = *l;
// 	if (!*l)
// 	{
// 		*l = new;
// 		return ;
// 	}
// 	else if (new->t <= (*l)->t)
// 	{
// 		// temp = *l;
// 		*l = new;
// 		new->next = temp;
// 	}
// 	else
// 	{
// 		// temp = *l;
// 		while (temp->next && new->t > temp->t && !(new->t < temp->next->t))
// 			temp = temp->next;
// 		if (!temp->next)
// 			temp->next = new;
// 		else
// 		{
// 			new->next = temp->next;
// 			temp->next = new;
// 		}
// 	}
// 	// *l = lst;
// }