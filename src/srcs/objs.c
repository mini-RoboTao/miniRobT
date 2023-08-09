/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 02:46:39 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/09 10:17:03 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	make_floor(void *v)
{
	t_shape	floor;

	floor = new_plane();
	floor.plane->material = new_material();
	floor.plane->material.color = fill_color(1, 0.9, 0.9);
	floor.plane->transform = multiply_matrix(rotation_x(M_PI_2), \
	translation(0, 0, 1), 4, 4);
	floor.plane->material.transparency = 0.5;
	floor.plane->material.reflective = 0.5;
	floor.plane->material.refractive_index = 1.5;
	floor.plane->material.specular = 0;
	return (floor);
	(void)v;
}

t_shape	make_wall_left(t_shape *floor)
{
	t_shape		wall;

	wall = new_sphere();
	wall.sphere->transform = multiply_matrix(\
								multiply_matrix(\
									translation(0, 0, 5), \
									rotation_y(-(M_PI_4)), 4, 4), \
								multiply_matrix(\
									rotation_x(M_PI_2), \
									scaling(10, 0.01, 10), 4, 4), 4, 4);
	wall.sphere->material = floor->sphere->material;
	return (wall);
}

t_shape	make_wall_right(t_shape *floor)
{
	t_shape		wall;
	t_matrix	tmp[6];

	wall = new_sphere();
	wall.sphere->transform = multiply_matrix(\
								multiply_matrix(\
									translation(0, 0, 5), \
									rotation_y((M_PI_4)), 4, 4), \
								multiply_matrix(\
									rotation_x(M_PI_2), \
									scaling(10, 0.01, 10), 4, 4), 4, 4);
	wall.sphere->material = floor->sphere->material;
	return (wall);
}
