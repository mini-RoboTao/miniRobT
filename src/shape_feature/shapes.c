/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:38 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/16 19:08:17 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	test_shape(void)
{
	t_shape			shape;
	t_common_shape	*s;

	shape = (t_shape){0};
	shape.any = malloc(sizeof(t_common_shape));
	if (!shape.any)
		return ((t_shape){0});
	shape.any->x = 0.0;
	shape.any->y = 0.0;
	shape.any->z = 0.0;
	shape.any->transform = create_identity_matrix();
	shape.any->material = new_material();
	shape.intersect = intersect_sphere;
	shape.normal_at = normal_at_sphere;
	shape.id = 1;
	return (shape);
}
