/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:28:51 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/17 17:53:29 by dapaulin         ###   ########.fr       */
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
