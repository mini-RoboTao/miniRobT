/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:18:17 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/12 23:32:36 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rotation_x(t_matrix *matrix, double r)
{
	if (!matrix)
		return (-1);
	if (matrix->x != 4 || matrix->y != 4)
		return (-1);
	matrix->node[0][0] = 1;
	matrix->node[1][1] = cos(r);
	matrix->node[1][2] = sin(r) * -1;
	matrix->node[2][1] = sin(r);
	matrix->node[2][2] = cos(r);
	matrix->node[3][3] = 1;
	return (1);
}

int	rotation_y(t_matrix *matrix, double r)
{
	if (!matrix)
		return (-1);
	if (matrix->x != 4 || matrix->y != 4)
		return (-1);
	matrix->node[0][0] = cos(r);
	matrix->node[0][2] = sin(r);
	matrix->node[1][1] = 1;
	matrix->node[2][0] = sin(r) * -1;
	matrix->node[2][2] = cos(r);
	matrix->node[3][3] = 1;
	return (1);
}

int	rotation_z(t_matrix *matrix, double r)
{
	if (!matrix)
		return (-1);
	if (matrix->x != 4 || matrix->y != 4)
		return (-1);
	matrix->node[0][0] = cos(r);
	matrix->node[0][1] = sin(r) * -1;
	matrix->node[1][0] = sin(r);
	matrix->node[1][1] = cos(r);
	matrix->node[2][2] = 1;
	matrix->node[3][3] = 1;
	return (1);
}
