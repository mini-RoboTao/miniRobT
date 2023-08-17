/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:30:50 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/16 20:12:13 by dapaulin         ###   ########.fr       */
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

void	fill_plane(t_world *world, t_define_plane p)
{
	t_shape	plane;

	plane = new_plane();
	set_transform2(&plane, translation(p.point.x, p.point.y, p.point.z));
	if (p.vector.x != 0)
		set_transform2(&plane, rotation_x(p.vector.x * M_PI));
	if (p.vector.y != 0)
		set_transform2(&plane, rotation_y(p.vector.y * M_PI));
	if (p.vector.z != 0)
		set_transform2(&plane, rotation_z(p.vector.z * M_PI));
	plane.any->material = p.material;
	ft_lstadd_back(&world->lst, ft_lstnew(plane));
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
