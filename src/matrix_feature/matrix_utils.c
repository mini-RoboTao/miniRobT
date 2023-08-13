/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:53:52 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/13 15:44:19 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	determinant(t_matrix m)
{
	int		i;
	double	det;

	i = -1;
	det = 0;
	if (m.x == 2)
		return (m.node[0][0] * m.node[1][1] - \
			m.node[0][1] * m.node[1][0]);
	else
	{
		while (++i < m.x)
			det = det + (m.node[0][i] * cofactor(m, 0, i));
	}
	return (det);
}

double	minor_matrix(t_matrix m, int row, int col)
{
	double		res;
	t_matrix	tmp;

	tmp = find_submatrix(m, row, col);
	res = determinant(tmp);
	return (res);
}

double	cofactor(t_matrix m, int row, int col)
{
	double	res;

	res = minor_matrix(m, row, col);
	if ((row + col) % 2 == 0)
		return (res);
	return (-res);
}

int	matrix_is_invertible(t_matrix m)
{
	if (determinant(m) == 0)
		return (0);
	return (1);
}
