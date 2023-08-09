/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 02:46:39 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/09 16:57:55 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	make_floor(void *v)
{
	t_shape	floor;

	floor = new_plane();
	floor.plane->material = new_material();
	set_transform(&floor, translation(0, -1, 0));
	floor.plane->material.reflective = 0.5;
	floor.plane->material.transparency = 0.5;
	floor.plane->material.refractive_index = 1.5;
	return (floor);
	(void)v;
}
