/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:18:17 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/16 16:40:34 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	translation(double x, double y, double z)
{
	t_matrix	matrix;

	matrix = new_matrix(4, 4);
	matrix.node[0][3] = x;
	matrix.node[1][3] = y;
	matrix.node[2][3] = z;
	matrix.node[0][0] = 1;
	matrix.node[1][1] = 1;
	matrix.node[2][2] = 1;
	matrix.node[3][3] = 1;
	return (matrix);
}
