/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 02:46:39 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/28 02:48:34 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*make_floor(void *v)
{
	t_sphere	*floor;

	floor = new_sphere();
	clean_matrix(floor->transform);
	floor->transform = scaling(10, 0.01, 10);
	floor->material = new_material();
	floor->material.color = fill_color(1, 0.9, 0.9);
	floor->material.specular = 0;
	return (floor);
	(void)v;
}

t_sphere	*make_wall_left(void *v)
{
	t_sphere	*wall;
	t_matrix	*tmp[6];
	t_sphere	*floor;

	wall = new_sphere();
	floor = (t_sphere *)v;
	clean_matrix(wall->transform);
	tmp[0] = translation(0, 0, 5);
	tmp[1] = rotation_y(-(M_PI_4));
	tmp[2] = rotation_x(M_PI_2);
	tmp[3] = scaling(10, 0.01, 10);
	tmp[4] = multiply_matrix(tmp[0], tmp[1], 4, 4);
	tmp[5] = multiply_matrix(tmp[2], tmp[3], 4, 4);
	wall->transform = multiply_matrix(tmp[4], tmp[5], 4, 4);
	clean_matrix(tmp[0]);
	clean_matrix(tmp[1]);
	clean_matrix(tmp[2]);
	clean_matrix(tmp[3]);
	clean_matrix(tmp[4]);
	clean_matrix(tmp[5]);
	wall->material = floor->material;
	return (wall);
}

t_sphere	*make_wall_right(void *v)
{
	t_sphere	*wall;
	t_matrix	*tmp[6];
	t_sphere	*floor;

	wall = new_sphere();
	floor = (t_sphere *)v;
	clean_matrix(wall->transform);
	tmp[0] = translation(0, 0, 5);
	tmp[1] = rotation_y(M_PI_4);
	tmp[2] = rotation_x(M_PI_2);
	tmp[3] = scaling(10, 0.01, 10);
	tmp[4] = multiply_matrix(tmp[0], tmp[1], 4, 4);
	tmp[5] = multiply_matrix(tmp[2], tmp[3], 4, 4);
	wall->transform = multiply_matrix(tmp[4], tmp[5], 4, 4);
	clean_matrix(tmp[0]);
	clean_matrix(tmp[1]);
	clean_matrix(tmp[2]);
	clean_matrix(tmp[3]);
	clean_matrix(tmp[4]);
	clean_matrix(tmp[5]);
	wall->material = floor->material;
	return (wall);
}
