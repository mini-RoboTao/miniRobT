/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_cap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:11:19 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/11 06:37:00 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	check_cone_cap(t_ray ray, double t, double minmax)
{
	double	x;
	double	z;

	x = ray.position.x + t * ray.direction.x;
	z = ray.position.z + t * ray.direction.z;
	return ((pow(x, 2) + pow(z, 2)) <= pow(minmax, 2));
}

void	intersect_cone_caps(t_intersections *xs, t_shape cone, t_ray ray)
{
	double			t;

	intersect_cone(xs, cone, ray);
	if (cone.any->closed == false || fabs(ray.direction.y) <= EPSILON)
		return ;
	t = (cone.any->minimum - ray.position.y) / ray.direction.y;
	if (check_cone_cap(ray, t, cone.any->minimum))
		intersections(xs, intersection(t, cone, xs), NULL);
	t = (cone.any->maximum - ray.position.y) / ray.direction.y;
	if (check_cone_cap(ray, t, cone.any->maximum))
		intersections(xs, intersection(t, cone, xs), NULL);
}
