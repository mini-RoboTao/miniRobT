/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_cap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:11:19 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/09 13:10:48 by dapaulin         ###   ########.fr       */
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

void	intersect_caps(t_intersections *xs, t_shape cylinder, t_ray ray)
{
	double			t;

	intersect_cylinder(xs, cylinder, ray);
	if (cylinder.cylinder->closed == false || fabs(ray.direction.y) <= EPSILON)
		return ;
	t = (cylinder.cylinder->minimum - ray.position.y) / ray.direction.y;
	if (check_cap(ray, t))
		intersections(xs, intersection(t, cylinder, xs), NULL);
	t = (cylinder.cylinder->maximum - ray.position.y) / ray.direction.y;
	if (check_cap(ray, t))
		intersections(xs, intersection(t, cylinder, xs), NULL);
}
