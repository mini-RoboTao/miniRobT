/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:28:51 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/05 17:40:19 by rotakesh         ###   ########.fr       */
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

// void	ft_lst_ray_sort_add(t_intersection **l, t_intersection *new)
// {
// 	t_intersection	*temp;
// 	t_intersection	*lst;

// 	lst = *l;
// 	printf("\n\nRAY SORT\n\n");
// 	printf("lst\t%p\n", lst);
// 	printf("l\t%p\n", l);
// 	printf("*l\t%p\n", *l);

// 	printf("received new->t\t%f\n", new->t);
// 	printf("received list\n");
// 	t_intersection *temp2 = lst;
// 	while (temp2)
// 	{
// 		printf("temp2->t\t%f\n", temp2->t);
// 		temp2 = temp2->next;
// 	}

// 	if (!l || !new)
// 		return ;
// 	if (!lst)
// 	{
// 		//printf("%p\n\n", new);
// 		//printf("\nif\n\n\n\n");
// 		//printf("%p\n", *l);
// 		lst = new;
// 		*l = lst;
// 		printf("\n\n!LST\n\n");
// 		printf("lst\t%p\n", lst);
// 		printf("l\t%p\n", l);
// 		printf("*l\t%p\n", *l);
// 		// printf("%p\n", *l);
// 		return ;
// 	}
// 	else if (new->t <= lst->t)
// 	{
// 		printf("\nelse if\n\n\n\n");
// 		temp = lst;
// 		lst = new;
// 		new->next = temp;
// 	}
// 	else
// 	{
// 		printf("\nelse\n\n\n\n");
// 		temp = lst;
// 		// while (new->t > temp->next->t && temp->next->next)
// 		while (temp->next && new->t > temp->t)
// 		{
// 			printf(" -- \n");
// 			temp = temp->next;
// 		}
// 		if (!temp->next)
// 		{
// 			temp->next = new;
// 		}
// 		else
// 		{
// 			printf("ELSEEEEEE\n");
// 			printf("new->t\t%f\n", new->t);
// 			printf("temp->t\t%f\n", temp->t);
// 			new->next = temp->next;
// 			temp->next = new;
// 		}
// 	}
// 	*l = lst;
// }