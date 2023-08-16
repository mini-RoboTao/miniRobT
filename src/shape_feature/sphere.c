/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:20:58 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/15 22:44:23 by dapaulin         ###   ########.fr       */
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

	shape = (t_shape){0};
	shape.any = malloc(sizeof(t_common_shape));
	if (!shape.any)
		return ((t_shape){0});
	shape.any->x = 0.0;
	shape.any->y = 0.0;
	shape.any->z = 0.0;
	shape.any->transform = create_identity_matrix();
	shape.any->material = new_material();
	shape.id = sphere;
	shape.intersect = intersect_sphere;
	shape.normal_at = normal_at_sphere;
	return (shape);
}

void	fill_sphere(t_world *world, t_define_sphere s)
{
	t_shape	sphere;

	sphere = new_sphere();
	set_transform2(&sphere, translation(s.point.x, s.point.y, s.point.z));
	set_transform2(&sphere, scaling(s.diameter, s.diameter, s.diameter));
	sphere.any->material = s.material;
	ft_lstadd_back(&world->lst, ft_lstnew(sphere));
}

t_shape	glass_sphere(void)
{
	t_shape	shape;

	shape = new_sphere();
	shape.any->material.transparency = 1.0;
	shape.any->material.refractive_index = 1.5;
	return (shape);
}
