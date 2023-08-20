/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arctan.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:13:43 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/19 22:16:44 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	object_eq(t_obj a, t_obj b)
{
	return	(fabs(a.x - b.x) < EPSILON && \
			fabs(a.y - b.y) < EPSILON && \
			fabs(a.z - b.z) < EPSILON && \
			a.w == b.w);
}

double	arctan(double p1, double p2)
{
	if (!p1 || !p2)
		return (0);
	return (atan(p2 / p1));
}

void	rotate_xyz(t_shape *shape, t_obj vector)
{
	if (object_eq(vector, create_vector(0, 1, 0)))
		set_transform2(shape, rotation_y(M_PI / 2));
	else if (object_eq(vector, create_vector(0, -1, 0)))
		set_transform2(shape, rotation_y(M_PI / -2));
	else if (object_eq(vector, create_vector(1, 0, 0)))
		set_transform2(shape, rotation_x(M_PI / 2));
	else if (object_eq(vector, create_vector(-1, 0, 0)))
		set_transform2(shape, rotation_x(M_PI / -2));
	else if (object_eq(vector, create_vector(0, 0, 1)))
		set_transform2(shape, rotation_z(M_PI / 2));
	else if (object_eq(vector, create_vector(0, 0, -1)))
		set_transform2(shape, rotation_z(M_PI / -2));
	else if (vector.y == 0)
	{
		set_transform2(shape, rotation_x(M_PI / 2));
		set_transform2(shape, rotation_z(arctan(vector.x, vector.z)));
	}
	else
	{
		set_transform2(shape, rotation_z(arctan(-vector.x, vector.y)));
		set_transform2(shape, rotation_x(arctan(vector.y, vector.z)));
	}
}
