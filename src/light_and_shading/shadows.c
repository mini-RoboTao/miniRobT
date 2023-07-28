/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:43:14 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/27 21:55:30 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// t_bool	is_shadowed(t_world world, t_obj *point)
// {
// 	t_obj			*v;
// 	t_obj			*direction;
// 	double			distance;
// 	t_ray			*ray;
// 	t_intersection	*intersections;
// 	t_intersection	*hit;

// 	v = subtract_objects(world->light.point, point);
// 	distance = object_magnitude(v);
// 	direction = object_normalize(v);
// 	ray = create_ray(point, direction);

// 	intersectons = intersect_world(world, ray);
// 	hit = hit(intersections);

// 	if (hit && hit.t < distance)
// 		return (true);
// 	return (false);
// }
