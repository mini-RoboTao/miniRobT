/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:49:46 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/28 06:06:18 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	normal_at(t_sphere *sphere, t_obj world_point)
{
	t_normal_at	normal;

	normal.inverse = inverse_matrix(sphere->transform);
	normal.object_point = multiply_matrix_by_obj(normal.inverse,
			world_point, 4, 4);
	normal.point = create_point(0, 0, 0);
	normal.object_normal = subtract_objects(normal.object_point, normal.point);
	normal.transpose = transpose_matrix(normal.inverse);
	normal.world_normal = multiply_matrix_by_obj(normal.transpose,
			normal.object_normal, 4, 4);
	normal.world_normal.w = 0;
	clean_matrix(normal.inverse);
	return (object_normalize(normal.world_normal));
}
