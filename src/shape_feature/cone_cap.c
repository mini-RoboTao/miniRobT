/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_cap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:11:19 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/10 16:44:07 by rotakesh         ###   ########.fr       */
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
	if (cone.cone->closed == false || fabs(ray.direction.y) <= EPSILON)
		return ;
	t = (cone.cone->minimum - ray.position.y) / ray.direction.y;
	if (check_cone_cap(ray, t, cone.cone->minimum))
		intersections(xs, intersection(t, cone, xs), NULL);
	t = (cone.cone->maximum - ray.position.y) / ray.direction.y;
	if (check_cone_cap(ray, t, cone.cone->maximum))
		intersections(xs, intersection(t, cone, xs), NULL);
}
