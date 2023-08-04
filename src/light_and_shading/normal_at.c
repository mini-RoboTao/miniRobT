/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:49:46 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/03 00:41:24 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	normal_at(t_shape shape, t_obj world_point)
{
	t_normal_at	normal;

	normal.inverse = inverse_matrix(shape.sphere->transform);
	normal.object_point = multiply_matrix_by_obj(normal.inverse,
			world_point, 4, 4);
	normal.point = create_point(0, 0, 0);
	normal.object_normal = subtract_objects(normal.object_point, normal.point);
	normal.transpose = transpose_matrix(normal.inverse);
	normal.world_normal = multiply_matrix_by_obj(normal.transpose,
			normal.object_normal, 4, 4);
	normal.world_normal.w = 0;
	return (object_normalize(normal.world_normal));
}
