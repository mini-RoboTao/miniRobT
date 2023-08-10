/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_together.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:59:37 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/10 17:47:13 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	middle_sphere(void *v)
{
	t_shape		middle;
	t_matrix	tmp[2];
	t_pattern	pattern;

	middle = new_sphere();
	middle.sphere->transform = translation(-0.5, 1, 0.5);
	middle.sphere->material = new_material();
	middle.sphere->material.color = fill_color(0.8, 0.4, 1);
	middle.sphere->material.reflective = 0.5;
	middle.sphere->material.transparency = 0.5;
	middle.sphere->material.refractive_index = 1.5;
	middle.sphere->material.diffuse = 0.7;
	middle.sphere->material.specular = 0.3;
	middle.sphere->material.ambient = 0.5;
	pattern = gradient_pattern(fill_color(0, 1, 0), fill_color(1, 0, 0));
	tmp[0] = translation(1, 1, 0.5);
	tmp[1] = scaling(2, 2, 2);
	set_pattern_transform(&pattern, multiply_matrix(tmp[0], tmp[1], 4, 4));
	middle.sphere->material.pattern = pattern;
	return (middle);
	(void)v;
}

t_shape	right_sphere(void *v)
{
	t_shape		middle;
	t_pattern	pattern;

	middle = new_cube();
	middle.any->transform = multiply_matrix(\
								translation(1.5, 0.5, -0.5), \
								scaling(0.5, 0.5, 0.5), 4, 4);
	middle.any->material = new_material();
	middle.any->material.color = fill_color(0.5, 0, 0.7);
	middle.any->material.reflective = 0.5;
	middle.any->material.diffuse = 0.7;
	middle.any->material.specular = 0.3;
	pattern = alt_checkers_pattern(fill_color(0, 1, 0), fill_color(1, 0, 0));
	set_pattern_transform(&pattern, scaling(0.2, 0.2, 0.2));
	middle.any->material.pattern = pattern;
	return (middle);
	(void)v;
}

t_shape	left_cube(void *v)
{
	t_shape		s3;
	t_pattern	pattern;

	s3 = new_cube();
	s3.cube->transform = multiply_matrix(\
									translation(-1.5, 0.33, -0.75), \
									scaling(0.33, 0.33, 0.33), 4, 4);
	s3.cube->material = new_material();
	s3.cube->material.color = fill_color(1, 0.8, 0.1);
	s3.cube->material.diffuse = 0.7;
	s3.cube->material.specular = 0.3;
	pattern = stripe_pattern(fill_color(1, 1, 0), fill_color(1, 0.4, 0));
	set_pattern_transform(&pattern, scaling(0.5, 0.5, 0.5));
	s3.cube->material.pattern = pattern;
	return (s3);
	(void)v;
}

t_shape	left_cylinder(void *v)
{
	t_shape		s3;
	t_pattern	pattern;

	s3 = new_cylinder();
	s3.cube->height = 3;
	s3.any->transform = multiply_matrix(\
									translation(-1.5, 0.33, -0.75), \
									scaling(0.33, 0.33, 0.33), 4, 4);
	s3.any->material = new_material();
	s3.any->material.color = fill_color(1, 0.8, 0.1);
	s3.any->material.diffuse = 0.7;
	s3.any->material.specular = 0.3;
	pattern = stripe_pattern(fill_color(1, 1, 0), fill_color(1, 0.4, 0));
	set_pattern_transform(&pattern, scaling(0.5, 0.5, 0.5));
	s3.any->material.pattern = pattern;
	return (s3);
	(void)v;
}

void	put_together(t_data *d)
{
	t_world		w;
	t_camera	c;

	w = (t_world){0};
	w.amount_obj = 8;
	w.shapes = malloc(sizeof(t_shape) * w.amount_obj);
	w.shapes[0] = make_floor(NULL);
	w.shapes[1] = middle_sphere(NULL);
	w.shapes[2] = right_sphere(NULL);
	w.shapes[3] = left_cylinder(NULL);
	w.shapes[4] = right_cube(NULL);
	w.shapes[5] = cap_cylinder(NULL);
	w.shapes[6] = left_cone(NULL);
	w.shapes[7] = left_cone_2(NULL);
	w.light = point_light(create_point(-10, 10, -10), fill_color(1, 1, 1));
	c = camera(WIDTH, HEIGHT, M_PI / 3);
	c.transform = view_transformation(create_point(0, 1.5, -5), \
	create_point(0, 1, 0), create_vector(0, 1, 0));
	d->canvas = render(&c, &w);
}
