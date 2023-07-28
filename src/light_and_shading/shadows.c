/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:43:14 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/28 00:57:07 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	is_shadowed(t_world *world, t_obj *point)
{
	t_obj			*objs;
	double			distance;
	t_ray			*ray;
	t_intersections	intersections;
	t_intersection	*h;

	objs = subtract_objects(world->light->position, point);
	distance = object_magnitude(objs);
	objs = object_normalize(objs);
	ray = create_ray(point, objs);
	intersections = intersect_world(world, ray);
	if (!intersections.i)
	{
		clean_ray(ray);
		free(intersections.shape);
		return (false);
	}
	h = hit(intersections);
	if (h && h->t < distance)
	{
		clean_ray_inter_shape(ray, &intersections.i, intersections.shape);
		return (true);
	}
	clean_ray_inter_shape(ray, &intersections.i, intersections.shape);
	return (false);
}
