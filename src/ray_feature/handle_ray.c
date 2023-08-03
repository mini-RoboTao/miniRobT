/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:48:49 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/03 02:00:02 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	create_ray(t_obj point, t_obj vector)
{
	t_ray	ray;

	ray.position = point;
	ray.direction = vector;
	return (ray);
}

t_obj	cat_position(t_ray ray, double t)
{
	t_obj	o;
	t_obj	res;

	res = multiply_object(ray.direction, t);
	o = sum_objects(ray.position, res);
	return (o);
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
	shape.id = 1;
	return (shape);
}
