/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:18:17 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/18 17:41:38 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	*shearing(t_shearing shearing_points)
{
	t_matrix	*matrix;

	matrix = alloc_matrix(4, 4);
	if (!matrix)
		return (NULL);
	matrix->node[0][0] = 1;
	matrix->node[1][1] = 1;
	matrix->node[2][2] = 1;
	matrix->node[3][3] = 1;
	matrix->node[0][1] = shearing_points.x_to_y;
	matrix->node[0][2] = shearing_points.x_to_z;
	matrix->node[1][0] = shearing_points.y_to_x;
	matrix->node[1][2] = shearing_points.y_to_z;
	matrix->node[2][0] = shearing_points.z_to_x;
	matrix->node[2][1] = shearing_points.z_to_y;
	return (matrix);
}
