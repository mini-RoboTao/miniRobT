/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:18:17 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/18 17:37:30 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	*scaling(double x, double y, double z)
{
	t_matrix	*matrix;

	matrix = alloc_matrix(4, 4);
	if (!matrix)
		return (NULL);
	matrix->node[0][0] = x;
	matrix->node[1][1] = y;
	matrix->node[2][2] = z;
	matrix->node[3][3] = 1;
	return (matrix);
}
