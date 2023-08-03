/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:43:14 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/03 03:41:18 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	is_shadowed(t_world *world, t_obj point)
{
	t_obj			objs;
	double			distance;
	t_ray			ray;
	t_intersections	intersections;
	t_intersection	*h;

	objs = subtract_objects(world->light.position, point);
	distance = object_magnitude(objs);
	objs = object_normalize(objs);
	ray = create_ray(point, objs);
	intersections = intersect_world(world, ray);
	if (!intersections.i)
		return (false);
	h = hit(intersections);
	if (h && h->t < distance)
	{
		clean_intersection_lst(&intersections.i);
		return (true);
	}
	clean_intersection_lst(&intersections.i);
	return (false);
}
