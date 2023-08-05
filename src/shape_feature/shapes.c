/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:38 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/04 20:07:30 by dapaulin         ###   ########.fr       */
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
	s->radius = 1.0;
	s->transform = create_identity_matrix();
	s->material = new_material();
	shape.sphere = s;
	shape.id = 1;
	return (shape);
}

t_shape	new_plane(void)
{
	t_shape		shape;
	t_plane		*p;

	shape = (t_shape){0};
	p = malloc(sizeof(t_plane));
	if (!p)
		return ((t_shape){0});
	p->x = 0.0;
	p->y = 0.0;
	p->z = 0.0;
	p->radius = 1.0;
	p->transform = create_identity_matrix();
	p->material = new_material();
	shape.v = p;
	shape.id = 3;
	return (shape);
}
