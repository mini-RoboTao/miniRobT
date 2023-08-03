/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 01:19:18 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/02 22:05:15 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clean_world(t_world w)
{
	clean_shape(&w.shape[0]);
	clean_shape(&w.shape[1]);
	if (w.shape)
		free(w.shape);
}
