/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 02:42:12 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/11 06:32:57 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	new_cube(void)
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
	shape.id = cube;
	shape.intersect = intersect_cube;
	shape.normal_at = normal_at_cube;
	return (shape);
}

void	intersect_cube(t_intersections *xs, t_shape cube, t_ray ray)
{
	double			*x_min_max;
	double			*y_min_max;
	double			*z_min_max;
	double			t_min_max[2];

	x_min_max = check_axis(ray.position.x, ray.direction.x);
	y_min_max = check_axis(ray.position.y, ray.direction.y);
	z_min_max = check_axis(ray.position.z, ray.direction.z);
	t_min_max[0] = max_three(x_min_max[0], y_min_max[0], z_min_max[0]);
	t_min_max[1] = min_three(x_min_max[1], y_min_max[1], z_min_max[1]);
	free(x_min_max);
	free(y_min_max);
	free(z_min_max);
	if (t_min_max[0] > t_min_max[1])
		return ;
	intersections(xs, intersection(t_min_max[0], cube, xs), \
						intersection(t_min_max[1], cube, xs));
}

double	*check_axis(double origin, double direction)
{
	double	*t_min_max;
	double	t_numerator[2];

	t_min_max = malloc(sizeof(double) * 3);
	if (!t_min_max)
		return (NULL);
	t_numerator[0] = (-1 - origin);
	t_numerator[1] = (1 - origin);
	if (fabs(direction) >= EPSILON)
	{
		t_min_max[0] = t_numerator[0] / direction;
		t_min_max[1] = t_numerator[1] / direction;
	}
	else
	{
		t_min_max[0] = t_numerator[0] * INFINITY;
		t_min_max[1] = t_numerator[1] * INFINITY;
	}
	if (t_min_max[0] > t_min_max[1])
		swap_double(&t_min_max[0], &t_min_max[1]);
	return (t_min_max);
}

t_obj	normal_at_cube(t_shape cube, t_obj point)
{
	double	maxc;

	maxc = max_three(fabs(point.x), fabs(point.y), fabs(point.z));
	if (maxc == (fabs(point.x)))
		return (create_vector(point.x, 0, 0));
	else if (maxc == (fabs(point.y)))
		return (create_vector(0, point.y, 0));
	return (create_vector(0, 0, point.z));
}
