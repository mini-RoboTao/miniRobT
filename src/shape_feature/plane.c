/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:30:50 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/11 06:31:44 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	intersect_plane(t_intersections *xs, t_shape shape, t_ray ray)
{
	double			t;

	shape.any->saved_ray = ray;
	if (fabs(ray.direction.y) < EPSILON)
		return ;
	t = (-ray.position.y) / ray.direction.y;
	intersections(xs, \
	intersection(t, shape, xs), NULL);
}

t_obj	normal_at_plane(t_shape shape, t_obj world_point)
{
	return (create_vector(0, 1, 0));
}

t_shape	new_plane(void)
{
	t_shape		shape;

	shape = (t_shape){0};
	shape.any = malloc(sizeof(t_common_shape));
	if (!shape.any)
		return ((t_shape){0});
	shape.any->x = 0.0;
	shape.any->y = 0.0;
	shape.any->z = 0.0;
	shape.any->transform = create_identity_matrix();
	shape.any->material = new_material();
	shape.id = plane;
	shape.intersect = intersect_plane;
	shape.normal_at = normal_at_plane;
	return (shape);
}
