/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverting_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 07:21:50 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/06 19:25:30 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	*inverse_matrix(t_matrix *m)
{
	int			i;
	int			j;
	double		c;
	double		det;
	t_matrix	*mb;

	i = -1;
	c = 0;
	if (!m || !matrix_is_invertible(m))
		return (NULL);
	det = determinant(m);
	mb = alloc_matrix(m->x, m->y);
	if (!mb)
		return (NULL);
	while (++i < m->y)
	{
		j = -1;
		while (++j < m->x)
		{
			c = cofactor(m, i, j);
			mb->node[j][i] = c / det;
		}
	}
	return (mb);
}

static void	run_submatrix(int *sub_row, t_matrix *subm, double *m, int col)
{
	int	j;
	int	sub_col;

	j = -1;
	sub_col = 0;
	while (++j < subm->x + 1)
	{
		if (j != col)
		{
			subm->node[*sub_row][sub_col] = m[j];
			sub_col++;
		}
	}
	*sub_row += 1;
}

t_matrix	*find_submatrix(t_matrix *m, int row, int col)
{
	int			i;
	int			sub_row;
	t_matrix	*subm;

	i = -1;
	sub_row = 0;
	if (!m)
		return (NULL);
	subm = alloc_matrix(m->x - 1, m->y - 1);
	if (!subm)
		return (NULL);
	while (++i < m->y)
	{
		if (i != row)
			run_submatrix(&sub_row, subm, m->node[i], col);
	}
	return (subm);
}
