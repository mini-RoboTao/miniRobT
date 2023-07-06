/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:19:46 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/06 01:48:43 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	*alloc_matrix(int col, int row)
{
	int			i;
	t_matrix	*m;

	m = malloc(sizeof(t_matrix));
	if (!m)
		return (NULL);
	m->x = col;
	m->y = row;
	m->node = ft_calloc(sizeof(double *), row);
	if (!m)
		return (clean_matrix(m));
	i = 0;
	while (i < row)
	{
		m->node[i] = ft_calloc(sizeof(double), col);
		if (!m->node[i])
			return (clean_matrix(m));
		i++;
	}
	return (m);
}

t_matrix	*create_matrix(char **values, int col, int row)
{
	int			i;
	int			j;
	t_matrix	*m;

	if (!values || !*values)
		return (NULL);
	m = alloc_matrix(col, row);
	if (!m)
		return (NULL);
	j = 0;
	i = 0;
	while (i < row)
	{
		j = -1;
		while (++j < col)
			m->node[i][j] = ft_atof(values[(i * col) + j]);
		i++;
	}
	return (m);
}

int	matrix_cmp(t_matrix *a, t_matrix *b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!a || !b)
	{
		if (a == b)
			return (1);
		return (0);
	}
	while (i < a->y && i < b->y)
	{
		j = 0;
		while (j < a->x && j < b->x)
		{
			if (fabs(a->node[i][j] - b->node[i][j]) > EPSILON)
				return (0);
			j++;
		}
		i++;
	}
	if (a->y == i && a->x == j && b->y == i && b->x == j)
		return (1);
	return (0);
}
