/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:08:19 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/19 21:55:27 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_a_light(t_world *world, t_define_a_light al)
{
	world->a_light = al;
}

void	fill_light(t_world *world, t_define_light l)
{
	world->light = point_light(l.position,
			multiply_scalar_colors(l.color, l.intensity));
}

t_camera	new_camera(t_define_cam define)
{
	t_camera	c;

	c = (t_camera){
		.hsize = define.vsize,
		.vsize = define.hsize,
		.field_of_view = define.fov * (M_PI / 180),
		.pixel_size = 0,
		.half_width = 0,
		.half_height = 0,
		.transform = create_identity_matrix()
	};
	calculate_pixel_cam(&c);
	define.vector.z = -define.vector.z;
	c.transform = view_transformation(define.point, \
		define.vector, create_vector(0, 1, 0));
	return (c);
}
