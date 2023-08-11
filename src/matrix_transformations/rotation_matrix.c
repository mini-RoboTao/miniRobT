/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:18:17 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/11 15:55:42 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	rotation_x(double r)
{
	t_matrix	matrix;

	if (r - 0 < EPSILON)
		create_identity_matrix();
	matrix = new_matrix(4, 4);
	matrix.node[0][0] = 1;
	matrix.node[1][1] = cos(r);
	matrix.node[1][2] = sin(r) * -1;
	matrix.node[2][1] = sin(r);
	matrix.node[2][2] = cos(r);
	matrix.node[3][3] = 1;
	return (matrix);
}

t_matrix	rotation_y(double r)
{
	t_matrix	matrix;

	if (r - 0 < EPSILON)
		create_identity_matrix();
	matrix = new_matrix(4, 4);
	matrix.node[0][0] = cos(r);
	matrix.node[0][2] = sin(r);
	matrix.node[1][1] = 1;
	matrix.node[2][0] = sin(r) * -1;
	matrix.node[2][2] = cos(r);
	matrix.node[3][3] = 1;
	return (matrix);
}

t_matrix	rotation_z(double r)
{
	t_matrix	matrix;

	if (r - 0 < EPSILON)
		create_identity_matrix();
	matrix = new_matrix(4, 4);
	matrix.node[0][0] = cos(r);
	matrix.node[0][1] = sin(r) * -1;
	matrix.node[1][0] = sin(r);
	matrix.node[1][1] = cos(r);
	matrix.node[2][2] = 1;
	matrix.node[3][3] = 1;
	return (matrix);
}
