/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:38 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/08 12:08:05 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	test_shape(void)
{
	t_shape		shape;
	t_sphere	*s;

	shape = (t_shape){0};
	s = malloc(sizeof(t_sphere));
	if (!s)
		return ((t_shape){0});
	s->x = 0.0;
	s->y = 0.0;
	s->z = 0.0;
	s->transform = create_identity_matrix();
	s->material = new_material();
	shape.sphere = s;
	shape.intersect = intersect_sphere;
	shape.normal_at = normal_at_sphere;
	shape.id = 1;
	return (shape);
}
