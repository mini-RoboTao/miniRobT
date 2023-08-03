/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:19:46 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/02 19:01:39 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	new_matrix(int x, int y)
{
	t_matrix	m;

	m = (t_matrix){0};
	m.x = x;
	m.y = y;
	return (m);
}

t_matrix	create_matrix(char **values, int col, int row)
{
	int			i;
	int			j;
	t_matrix	m;

	if (!values || !*values)
		return (new_matrix(0, 0));
	m = new_matrix(col, row);
	i = 0;
	while (i < row)
	{
		j = -1;
		while (++j < col)
			m.node[i][j] = ft_atof(values[(i * col) + j]);
		i++;
	}
	return (m);
}

t_matrix	create_identity_matrix(void)
{
	t_matrix	m;

	m = new_matrix(4, 4);
	m.node[0][0] = 1;
	m.node[1][1] = 1;
	m.node[2][2] = 1;
	m.node[3][3] = 1;
	return (m);
}
