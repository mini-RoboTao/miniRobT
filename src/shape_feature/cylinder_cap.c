/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_cap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:11:19 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/09 10:54:25 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	check_cap(t_ray ray, double t)
{
	double	x;
	double	z;

	x = ray.position.x + t * ray.direction.x;
	z = ray.position.z + t * ray.direction.z;
	return ((pow(x, 2) + pow(z, 2)) <= 1);
}

t_intersections	intersect_caps(t_shape cylinder, t_ray ray)
{
	t_intersections	xs_caps;
	t_intersections	xs_cylinder;
	double			t;

	xs_caps = (t_intersections){0};
	xs_cylinder = (t_intersections){0};
	xs_cylinder = intersect_cylinder(cylinder, ray);
	if (cylinder.cylinder->closed == false || fabs(ray.direction.y) <= EPSILON)
		return (xs_cylinder);
	t = (cylinder.cylinder->minimum - ray.position.y) / ray.direction.y;
	if (check_cap(ray, t))
		intersections(&xs_caps, intersection(t, cylinder, & xs_caps), NULL, 0);
	t = (cylinder.cylinder->maximum - ray.position.y) / ray.direction.y;
	if (check_cap(ray, t))
		intersections(&xs_caps, intersection(t, cylinder, & xs_caps), NULL, 0);
	intersections(&xs_caps, xs_cylinder.i, NULL, 0);
	return (xs_caps);
}
