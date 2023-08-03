/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_together.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:59:37 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/02 22:47:21 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*middle_sphere(void *v)
{
	t_sphere	*middle;

	middle = new_sphere();
	middle->transform = translation(-0.5, 1, 0.5);
	middle->material = new_material();
	middle->material.color = fill_color(0.1, 1, 0.5);
	middle->material.diffuse = 0.7;
	middle->material.specular = 0.3;
	return (middle);
	(void)v;
}

t_sphere	*right_sphere(void *v)
{
	t_sphere	*middle;
	t_matrix	tmp[2];

	middle = new_sphere();
	tmp[0] = translation(1.5, 0.5, -0.5);
	tmp[1] = scaling(0.5, 0.5, 0.5);
	middle->transform = multiply_matrix(tmp[0], tmp[1], 4, 4);
	middle->material = new_material();
	middle->material.color = fill_color(1, 0.1, 0.1);
	middle->material.diffuse = 0.7;
	middle->material.specular = 0.3;
	return (middle);
	(void)v;
}

t_sphere	*left_sphere(void *v)
{
	t_sphere	*middle;
	t_matrix	tmp[2];

	middle = new_sphere();
	tmp[0] = translation(-1.5, 0.33, -0.75);
	tmp[1] = scaling(0.33, 0.33, 0.33);
	middle->transform = multiply_matrix(tmp[0], tmp[1], 4, 4);
	middle->material = new_material();
	middle->material.color = fill_color(1, 0.8, 0.1);
	middle->material.diffuse = 0.7;
	middle->material.specular = 0.3;
	return (middle);
	(void)v;
}

void	put_together(t_data *d)
{
	t_world		w;
	t_camera	c;

	w = (t_world){0};
	w.amount_obj = 6;
	w.shape = malloc(sizeof(union u_shape) * w.amount_obj);
	w.shape[0].sphere = make_floor(NULL);
	w.shape[1].sphere = make_wall_left(w.shape[0].v);
	w.shape[2].sphere = make_wall_right(w.shape[0].v);
	w.shape[3].sphere = middle_sphere(NULL);
	w.shape[4].sphere = right_sphere(NULL);
	w.shape[5].sphere = left_sphere(NULL);
	w.light = point_light(create_point(-10, 10, -10), fill_color(1, 1, 1));
	c = camera(1000, 500, M_PI / 3);
	c.transform = view_transformation(create_point(0, 1.5, -5), \
	create_point(0, 1, 0), create_vector(0, 1, 1));
	d->canvas = render(&c, &w);
}
