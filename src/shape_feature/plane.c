/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:30:50 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/09 06:36:33 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersections	intersect_plane(t_shape shape, t_ray ray)
{
	double			t;
	t_intersections	xs;

	xs = (t_intersections){0};
	shape.any->saved_ray = ray;
	if (fabs(ray.direction.y) < EPSILON)
		return ((t_intersections){0});
	t = (-ray.position.y) / ray.direction.y;
	intersections(&xs, \
	intersection(t, shape, &xs), NULL, 0);
	return (xs);
}

t_obj	normal_at_plane(t_shape shape, t_obj world_point)
{
	return (create_vector(0, 1, 0));
}

t_shape	new_plane(void)
{
	t_shape		shape;
	t_plane		*p;

	shape = (t_shape){0};
	p = malloc(sizeof(t_plane));
	if (!p)
		return ((t_shape){0});
	p->x = 0.0;
	p->y = 0.0;
	p->z = 0.0;
	p->transform = create_identity_matrix();
	p->material = new_material();
	shape.v = p;
	shape.id = 2;
	shape.intersect = intersect_plane;
	shape.normal_at = normal_at_plane;
	return (shape);
}
