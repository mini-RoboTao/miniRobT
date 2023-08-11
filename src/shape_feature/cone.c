/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 02:42:12 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/11 06:36:48 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	new_cone(void)
{
	t_shape	shape;

	shape = (t_shape){0};
	shape.any = malloc(sizeof(t_common_shape));
	if (!shape.any)
		return ((t_shape){0});
	shape.any->x = 0.0;
	shape.any->y = 0.0;
	shape.any->z = 0.0;
	shape.any->minimum = -INFINITY;
	shape.any->maximum = INFINITY;
	shape.any->closed = false;
	shape.any->transform = create_identity_matrix();
	shape.any->material = new_material();
	shape.id = cone;
	shape.intersect = intersect_cone_caps;
	shape.normal_at = normal_at_cone;
	return (shape);
}

static void	calculate_abc(double *abc, t_ray ray)
{
	abc[0] = pow(ray.direction.x, 2) - pow(ray.direction.y, 2)
		+ pow(ray.direction.z, 2);
	abc[1] = 2 * ray.position.x * ray.direction.x - 2 * ray.position.y
		* ray.direction.y + 2 * ray.position.z * ray.direction.z;
	abc[2] = pow(ray.position.x, 2) - pow(ray.position.y, 2)
		+ pow(ray.position.z, 2);
}

void	intersect_cone(t_intersections *xs, t_shape cone, t_ray ray)
{
	double			abc[3];
	double			t[2];
	double			y[2];
	double			disc;

	calculate_abc(abc, ray);
	if (abc[0] == 0 && abc[1] != 0)
	{
		intersections(xs, intersection(-abc[2] / (2 * abc[1]), cone, xs), NULL);
		return ;
	}
	disc = pow(abc[1], 2) - 4 * abc[0] * abc[2];
	if (disc < 0)
		return ;
	t[0] = (-abc[1] - sqrt(disc)) / (2 * abc[0]);
	t[1] = (-abc[1] + sqrt(disc)) / (2 * abc[0]);
	if (t[0] > t[1])
		swap_double(&t[0], &t[1]);
	y[0] = ray.position.y + t[0] * ray.direction.y;
	if (cone.any->minimum < y[0] && y[0] < cone.any->maximum)
		intersections(xs, intersection(t[0], cone, xs), NULL);
	y[1] = ray.position.y + t[1] * ray.direction.y;
	if (cone.any->minimum < y[1] && y[1] < cone.any->maximum)
		intersections(xs, intersection(t[1], cone, xs), NULL);
}

t_obj	normal_at_cone(t_shape cone, t_obj point)
{
	double	dist;
	double	y;

	y = sqrt(pow(point.x, 2) + pow(point.z, 2));
	if (point.y > 0)
		y = -y;
	dist = pow(point.x, 2) + pow(point.z, 2);
	if (dist < 1 && point.y >= cone.any->maximum - EPSILON)
		return (create_vector(0, 1, 0));
	else if (dist < 1 && point.y <= cone.any->minimum + EPSILON)
		return (create_vector(0, -1, 0));
	return (create_vector(point.x, y, point.z));
}
