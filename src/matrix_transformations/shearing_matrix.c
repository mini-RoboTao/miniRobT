/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:18:17 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/13 00:15:04 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	shearing(t_matrix *matrix, t_shearing shearing_points)
{
	if (!matrix)
		return (-1);
	if (matrix->x != 4 || matrix->y != 4)
		return (-1);
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
	return (1);
}
