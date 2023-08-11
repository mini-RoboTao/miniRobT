/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 01:48:00 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/10 21:02:49 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	matrix_cmp(t_matrix a, t_matrix b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < a.y && i < b.y)
	{
		j = 0;
		while (j < a.x && j < b.x)
		{
			if (fabs(a.node[i][j] - b.node[i][j]) > EPSILON)
				return (0);
			j++;
		}
		i++;
	}
	if (a.y == i && a.x == j && b.y == i && b.x == j)
		return (1);
	return (0);
}

static double	mult_action(t_matrix ma, t_matrix mb, int col, int row)
{
	int		i;
	double	res;

	i = 0;
	res = 0;
	while (i < ma.x && i < ma.y && i < mb.x && i < mb.y)
	{
		res += (ma.node[row][i] * mb.node[i][col]);
		i++;
	}
	return (res);
}

t_matrix	multiply_matrix(t_matrix ma, t_matrix mb, int nrow, int ncol)
{
	int			col;
	int			row;
	t_matrix	m;

	m = new_matrix(ncol, nrow);
	row = 0;
	col = 0;
	while (row < nrow)
	{
		col = 0;
		while (col < ncol)
		{
			m.node[row][col] = mult_action(ma, mb, col, row);
			col++;
		}
		row++;
	}
	return (m);
}

t_obj	multiply_matrix_by_obj(t_matrix m, t_obj obj, int col, int row)
{
	int		i;
	double	o[4];

	i = 0;
	while (i < row && i < col)
	{
		o[i] = m.node[i][0] * obj.x + \
				m.node[i][1] * obj.y + \
				m.node[i][2] * obj.z + \
				m.node[i][3] * obj.w;
		i++;
	}
	return (create_object(o[0], o[1], o[2], o[3]));
}

t_matrix	transpose_matrix(t_matrix ma)
{
	int			i;
	int			j;
	t_matrix	mb;

	mb = new_matrix(ma.x, ma.y);
	i = -1;
	while (++i < ma.y)
	{
		j = -1;
		while (++j < ma.x)
			mb.node[i][j] = ma.node[j][i];
	}
	return (mb);
}
