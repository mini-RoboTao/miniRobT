/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 02:42:12 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/15 23:30:09 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	new_cylinder(void)
{
	t_shape			shape;

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
	shape.id = cylinder;
	shape.intersect = intersect_caps;
	shape.normal_at = normal_at_cylinder;
	return (shape);
}

void	fill_cylinder(t_world *world, t_define_cylinder c)
{
	t_shape	cylinder;

	cylinder = new_cylinder();
	set_transform2(&cylinder, translation(c.point.x, c.point.y, c.point.z));
	set_transform2(&cylinder, rotation_x(c.vector.x * M_PI));
	set_transform2(&cylinder, rotation_y(c.vector.y * M_PI));
	set_transform2(&cylinder, rotation_z(c.vector.z * M_PI));
	set_transform2(&cylinder, scaling(c.diameter, 1, c.diameter));
	cylinder.any->maximum = c.height / 2;
	cylinder.any->minimum = -(c.height / 2);
	cylinder.any->material = c.material;
	ft_lstadd_back(&world->lst, ft_lstnew(cylinder));
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

void	intersect_cylinder(t_intersections *xs, t_shape cylinder, t_ray ray)
{
	double			abc[3];
	double			t[2];
	double			y[2];
	double			disc;

	abc[0] = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	if (abc[0] <= EPSILON)
		return ;
	disc = calculate_bhaskara(abc, ray);
	if (disc < 0)
		return ;
	t[0] = (-abc[1] - sqrt(disc)) / (2 * abc[0]);
	t[1] = (-abc[1] + sqrt(disc)) / (2 * abc[0]);
	if (t[0] > t[1])
		swap_double(&t[0], &t[1]);
	y[0] = ray.position.y + t[0] * ray.direction.y;
	if (cylinder.any->minimum < y[0] && y[0] < cylinder.any->maximum)
		intersections(xs, intersection(t[0], cylinder, xs), NULL);
	y[1] = ray.position.y + t[1] * ray.direction.y;
	if (cylinder.any->minimum < y[1] && y[1] < cylinder.any->maximum)
		intersections(xs, intersection(t[1], cylinder, xs), NULL);
}

t_obj	normal_at_cylinder(t_shape cylinder, t_obj point)
{
	double	dist;

	dist = pow(point.x, 2) + pow(point.z, 2);
	if (dist < 1 && point.y >= cylinder.any->maximum - EPSILON)
		return (create_vector(0, 1, 0));
	else if (dist < 1 && point.y <= cylinder.any->minimum + EPSILON)
		return (create_vector(0, -1, 0));
	return (create_vector(point.x, 0, point.z));
}
