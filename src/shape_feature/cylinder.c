/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 02:42:12 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/09 11:14:02 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	new_cylinder(void)
{
	t_shape			shape;
	t_cylinder		*sh_cylinder;

	shape = (t_shape){0};
	sh_cylinder = malloc(sizeof(t_cylinder));
	if (!sh_cylinder)
		return ((t_shape){0});
	sh_cylinder->x = 0.0;
	sh_cylinder->y = 0.0;
	sh_cylinder->z = 0.0;
	sh_cylinder->radius = 1.0;
	sh_cylinder->minimum = -INFINITY;
	sh_cylinder->maximum = INFINITY;
	sh_cylinder->closed = false;
	sh_cylinder->transform = create_identity_matrix();
	sh_cylinder->material = new_material();
	shape.v = sh_cylinder;
	shape.id = cylinder;
	shape.intersect = intersect_cylinder;
	shape.normal_at = normal_at_cylinder;
	return (shape);
}

static double	calculate_bhaskara(double *abc, t_ray ray)
{
	double	disc;

	abc[1] = 2 * ray.position.x * ray.direction.x + 2 * ray.position.z * \
		ray.direction.z;
	abc[2] = pow(ray.position.x, 2) + pow(ray.position.z, 2) - 1;
	disc = pow(abc[1], 2) - 4 * abc[0] * abc[2];
	return (disc);
}

t_intersections	intersect_cylinder(t_shape cylinder, t_ray ray)
{
	double			abc[3];
	double			t[2];
	double			y[2];
	double			disc;
	t_intersections	xs;

	xs = (t_intersections){0};
	abc[0] = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	if (abc[0] <= EPSILON)
		return (xs);
	disc = calculate_bhaskara(abc, ray);
	if (disc < 0)
		return (xs);
	t[0] = (-abc[1] - sqrt(disc)) / (2 * abc[0]);
	t[1] = (-abc[1] + sqrt(disc)) / (2 * abc[0]);
	if (t[0] > t[1])
		swap_double(&t[0], &t[1]);
	y[0] = ray.position.y + t[0] * ray.direction.y;
	if (cylinder.cylinder->minimum < y[0] && y[0] < cylinder.cylinder->maximum)
		intersections(&xs, intersection(t[0], cylinder, &xs), NULL, 0);
	y[1] = ray.position.y + t[1] * ray.direction.y;
	if (cylinder.cylinder->minimum < y[1] && y[1] < cylinder.cylinder->maximum)
		intersections(&xs, intersection(t[1], cylinder, &xs), NULL, 0);
	return (xs);
}

t_obj	normal_at_cylinder(t_shape cylinder, t_obj point)
{
	double	dist;

	dist = pow(point.x, 2) + pow(point.z, 2);
	if (dist < 1 && point.y >= cylinder.cylinder->maximum - EPSILON)
		return (create_vector(0, 1, 0));
	else if (dist < 1 && point.y <= cylinder.cylinder->minimum + EPSILON)
		return (create_vector(0, -1, 0));
	return (create_vector(point.x, 0, point.z));
}
