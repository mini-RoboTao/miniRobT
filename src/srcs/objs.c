/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 02:46:39 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/11 07:17:05 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	make_floor(void *v)
{
	t_shape		floor;
	t_pattern	pattern;

	floor = new_plane();
	floor.any->material = new_material();
	set_transform(&floor, translation(0, -1, 0));
	floor.any->material.reflective = 0.5;
	floor.any->material.transparency = 0.5;
	floor.any->material.refractive_index = 1.5;
	pattern = checkers_pattern(fill_color(1, 1, 1), fill_color(0, 0, 0));
	set_pattern_transform(&pattern, scaling(0.5, 0.5, 0.5));
	floor.any->material.pattern = pattern;
	return (floor);
	(void)v;
}

t_shape	cap_cylinder(void *v)
{
	t_shape		s3;
	t_pattern	pattern;

	s3 = new_cylinder();
	s3.any->transform = multiply_matrix(\
									translation(-2, -0.33, -1.25), \
									scaling(0.33, 0.33, 0.33), 4, 4);
	s3.any->material = new_material();
	s3.any->material.color = fill_color(1, 0.8, 0.1);
	s3.any->material.diffuse = 0.7;
	s3.any->material.specular = 0.3;
	pattern = stripe_pattern(fill_color(1, 1, 0), fill_color(1, 0.4, 0));
	set_pattern_transform(&pattern, scaling(0.5, 0.5, 0.5));
	s3.any->material.pattern = pattern;
	s3.any->closed = true;
	return (s3);
	(void)v;
}

t_shape	right_cube(void *v)
{
	t_shape		middle;
	t_pattern	pattern;

	middle = new_cube();
	middle.any->transform = multiply_matrix(\
								translation(-2, 1.75, -0.5), \
								scaling(0.5, 0.5, 0.5), 4, 4);
	middle.any->material = new_material();
	middle.any->material.color = fill_color(0.5, 0, 0.7);
	middle.any->material.reflective = 0.5;
	middle.any->material.diffuse = 0.7;
	middle.any->material.specular = 0.3;
	pattern = checkers_pattern(fill_color(0, 1, 0), fill_color(1, 0, 0));
	set_pattern_transform(&pattern, scaling(0.5, 0.5, 0.5));
	middle.any->material.pattern = pattern;
	return (middle);
	(void)v;
}

t_shape	left_cone(void *v)
{
	t_shape		s3;
	t_pattern	pattern;

	s3 = new_cone();
	s3.any->transform = multiply_matrix(\
									translation(1, 1.66, 1.75), \
									scaling(0.6, 0.6, 0.6), 4, 4);
	s3.any->transform = multiply_matrix(s3.any->transform, rotation_x(M_PI), \
									4, 4);
	s3.any->material = new_material();
	s3.any->material.color = fill_color(1, 0.8, 0.1);
	s3.any->material.diffuse = 0.7;
	s3.any->material.specular = 0.3;
	pattern = alt_checkers_pattern(fill_color(1, 1, 0), fill_color(1, 0.4, 0));
	set_pattern_transform(&pattern, scaling(0.2, 0.2, 0.2));
	s3.any->material.pattern = pattern;
	return (s3);
	(void)v;
}

t_shape	left_cone_2(void *v)
{
	t_shape		s3;
	t_pattern	pattern;

	s3 = new_cone();
	s3.any->transform = multiply_matrix(\
									translation(1, 1.66, 1.75), \
									scaling(0.6, 0.6, 0.6), 4, 4);
	s3.any->material = new_material();
	s3.any->material.color = fill_color(1, 0.8, 0.1);
	s3.any->material.diffuse = 0.7;
	s3.any->material.specular = 0.3;
	pattern = alt_checkers_pattern(fill_color(1, 1, 0), fill_color(1, 0.4, 0));
	set_pattern_transform(&pattern, scaling(0.2, 0.2, 0.2));
	s3.any->material.pattern = pattern;
	return (s3);
	(void)v;
}
