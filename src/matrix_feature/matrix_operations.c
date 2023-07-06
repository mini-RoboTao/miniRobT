/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 01:48:00 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/06 03:52:08 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	mult_action(t_matrix *ma, t_matrix *mb, int col, int row)
{
	int		i;
	double	res;

	i = 0;
	res = 0;
	while (i < ma->x && i < ma->y && i < mb->x && i < mb->y)
	{
		res += (ma->node[row][i] * mb->node[i][col]);
		i++;
	}
	return (res);
}

t_matrix	*multiply_matrix(t_matrix *ma, t_matrix *mb, int nrow, int ncol)
{
	int			col;
	int			row;
	t_matrix	*m;

	if (!ma || !mb)
		return (NULL);
	m = alloc_matrix(ncol, nrow);
	if (!m)
		return (NULL);
	row = 0;
	col = 0;
	while (row < nrow)
	{
		col = 0;
		while (col < ncol)
		{
			m->node[row][col] = mult_action(ma, mb, col, row);
			col++;
		}
		row++;
	}
	return (m);
}

t_obj	*multiply_matrix_by_obj(t_matrix *m, t_obj *obj, int col, int row)
{
	int		i;
	double	o[4];

	i = 0;
	if (!m || !obj)
		return (NULL);
	while (i < row && i < col)
	{
		o[i] = m->node[i][0] * obj->x + \
				m->node[i][1] * obj->y + \
				m->node[i][2] * obj->z + \
				m->node[i][3] * obj->w;
		i++;
	}
	return (create_object(o[0], o[1], o[2], o[3]));
}

t_matrix	*transpose_matrix(t_matrix *ma)
{
	int			i;
	int			j;
	t_matrix	*mb;

	if (!ma)
		return (NULL);
	mb = alloc_matrix(ma->x, ma->y);
	if (!mb)
		return (mb);
	i = -1;
	while (++i < ma->y)
	{
		j = -1;
		while (++j < ma->x)
			mb->node[i][j] = ma->node[j][i];
	}
	i = -1;
	while (++i < ma->y)
	{
		j = -1;
		while (++j < ma->x)
			ma->node[i][j] = mb->node[i][j];
	}
	clean_matrix(mb);
	return (ma);
}
