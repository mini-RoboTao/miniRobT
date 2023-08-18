/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:08:19 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/17 22:47:53 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_a_light(t_world *world, t_define_a_light al)
{
	world->a_light = multiply_scalar_colors(al.color, al.intensity);
}

void	fill_light(t_world *world, t_define_light l)
{
	world->light = point_light(l.position, l.color);
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
	c.transform = view_transformation(define.point, \
		create_point(0, 0, 0), define.vector);
	return (c);
}
