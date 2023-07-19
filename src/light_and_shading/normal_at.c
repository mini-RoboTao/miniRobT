/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:49:46 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/19 00:18:22 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

	// point->x = point->x - sphere->x;
	// point->y = point->y - sphere->y;
	// point->z = point->z - sphere->z;

t_obj	*normal_at(t_sphere *sphere, t_obj *point)
{
	t_obj	*vec;

	vec = create_vector(point->x - sphere->x, point->y - sphere->y,
			point->z - sphere->z);
	return (object_normalize(vec));
}

// t_obj	*normal_at(t_sphere *sphere, t_obj *world_point)
// {
// 	t_obj		*object_point;
// 	t_obj		*object_normal;
// 	t_obj		*world_normal;
// 	t_matrix	*inverse;
// 	t_obj		*point;

// 	inverse = inverse_matrix(sphere->transform);
// 	object_point = multiply_matrix_by_obj(inverse, world_point, 4, 4);
// 	point = create_point(0, 0, 0);
// 	object_normal = subtract_objects(object_point, point);
// 	world_normal = multiply_matrix_by_obj(inverse, object_normal, 4, 4);
// 	world_normal->w = 0;
// 	clean_obj(object_point);
// 	clean_obj(object_normal);
// 	clean_matrix(inverse);
// 	clean_obj(point);
// 	return (object_normalize(world_normal));
// }
