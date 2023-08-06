/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 02:46:39 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/05 19:39:59 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	make_floor(void *v)
{
	t_shape	floor;

	floor = new_sphere();
	floor.sphere->transform = scaling(10, 0.01, 10);
	floor.sphere->material = new_material();
	floor.sphere->material.color = fill_color(1, 0.5, 0.9);
	floor.sphere->material.specular = 0;
	return (floor);
	(void)v;
}

t_shape	make_wall_left(t_shape *floor)
{
	t_shape		wall;
	t_matrix	tmp[6];

	wall = new_sphere();
	tmp[0] = translation(0, 0, 5);
	tmp[1] = rotation_y(-(M_PI_4));
	tmp[2] = rotation_x(M_PI_2);
	tmp[3] = scaling(10, 0.01, 10);
	tmp[4] = multiply_matrix(tmp[0], tmp[1], 4, 4);
	tmp[5] = multiply_matrix(tmp[2], tmp[3], 4, 4);
	wall.sphere->transform = multiply_matrix(tmp[4], tmp[5], 4, 4);
	wall.sphere->material = floor->sphere->material;
	return (wall);
}

t_shape	make_wall_right(t_shape *floor)
{
	t_shape		wall;
	t_matrix	tmp[6];

	wall = new_sphere();
	tmp[0] = translation(0, 0, 5);
	tmp[1] = rotation_y(M_PI_4);
	tmp[2] = rotation_x(M_PI_2);
	tmp[3] = scaling(10, 0.01, 10);
	tmp[4] = multiply_matrix(tmp[0], tmp[1], 4, 4);
	tmp[5] = multiply_matrix(tmp[2], tmp[3], 4, 4);
	wall.sphere->transform = multiply_matrix(tmp[4], tmp[5], 4, 4);
	wall.sphere->material = floor->sphere->material;
	return (wall);
}
