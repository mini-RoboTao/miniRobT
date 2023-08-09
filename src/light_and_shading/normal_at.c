/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:49:46 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/09 06:26:55 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	normal_at(t_shape shape, t_obj world_point)
{
	t_obj		local_point;
	t_obj		local_normal;
	t_obj		world_normal;

	local_point = multiply_matrix_by_obj(\
	inverse_matrix(shape.any->transform), world_point, 4, 4);
	local_normal = shape.normal_at(shape, local_point);
	world_normal = multiply_matrix_by_obj(\
	transpose_matrix(inverse_matrix(shape.any->transform)), local_normal, 4, 4);
	world_normal.w = 0;
	return (object_normalize(world_normal));
}

// t_obj	normal_at(t_shape shape, t_obj world_point)
// {
// 	t_normal_at	normal;

// 	if (shape.id == 3)
// 		return (create_vector(0, 1, 0));
// 	normal.inverse = inverse_matrix(shape.any->transform);
// 	normal.object_point = multiply_matrix_by_obj(normal.inverse,
// 			world_point, 4, 4);
// 	normal.point = create_point(0, 0, 0);
// 	normal.object_normal = subtract_objects(normal.object_point, normal.point);
// 	normal.transpose = transpose_matrix(normal.inverse);
// 	normal.world_normal = multiply_matrix_by_obj(normal.transpose,
// 			normal.object_normal, 4, 4);
// 	normal.world_normal.w = 0;
// 	return (object_normalize(normal.world_normal));
// }