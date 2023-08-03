/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:18:17 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/02 18:08:47 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	scaling(double x, double y, double z)
{
	t_matrix	matrix;

	matrix = new_matrix(4, 4);
	matrix.node[0][0] = x;
	matrix.node[1][1] = y;
	matrix.node[2][2] = z;
	matrix.node[3][3] = 1;
	return (matrix);
}
