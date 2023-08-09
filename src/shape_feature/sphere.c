/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:20:58 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/09 10:16:23 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	intersect_sphere(t_intersections *xs, t_shape shape, t_ray ray)
{
	double			abc[3];
	double			discriminat;

	shape.any->saved_ray = ray;
	discriminat = calculate_discriminat(abc, ray, shape);
	if (discriminat < 0)
		return ;
	intersections(xs, \
	intersection((-abc[1] - (sqrt(discriminat))) / (2 * abc[0]), shape, xs), \
	intersection((-abc[1] + (sqrt(discriminat))) / (2 * abc[0]), shape, xs));
}

t_obj	normal_at_sphere(t_shape shape, t_obj point)
{
	return (subtract_objects(point, create_point(0, 0, 0)));
}

t_shape	new_sphere(void)
{
	t_shape		shape;
	t_sphere	*s;

	shape = (t_shape){0};
	s = malloc(sizeof(t_sphere));
	if (!s)
		return ((t_shape){0});
	s->x = 0.0;
	s->y = 0.0;
	s->z = 0.0;
	s->radius = 1.0;
	s->transform = create_identity_matrix();
	s->material = new_material();
	shape.sphere = s;
	shape.id = sphere;
	shape.intersect = intersect_sphere;
	shape.normal_at = normal_at_sphere;
	return (shape);
}

t_shape	glass_sphere(void)
{
	t_shape	shape;

	shape = new_sphere();
	shape.sphere->material.transparency = 1.0;
	shape.sphere->material.refractive_index = 1.5;
	return (shape);
}
