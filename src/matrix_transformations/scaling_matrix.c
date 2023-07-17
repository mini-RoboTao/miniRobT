/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:18:17 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/11 21:09:03 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	scaling(t_matrix *matrix, double x, double y, double z)
{
	if (!matrix)
		return (-1);
	if (matrix->x != 4 || matrix->y != 4)
		return (-1);
	matrix->node[0][0] = x;
	matrix->node[1][1] = y;
	matrix->node[2][2] = z;
	matrix->node[3][3] = 1;
	return (1);
}
