/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:17:06 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/17 16:11:37 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	ft_lstsize(t_lst *l)
{
	int	size;

	size = 0;
	while (l)
	{
		l = l->next;
		size++;
	}
	return (size);
}

int	ft_lstray_size(t_intersection *l)
{
	int	size;

	size = 0;
	while (l)
	{
		l = l->next;
		size++;
	}
	return (size);
}
