/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:57:28 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/02 00:24:14 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	calculate_pixel_cam(t_camera *c)
{
	double	half_view;
	double	aspect;

	half_view = tan(c->field_of_view / 2);
	aspect = c->hsize / c->vsize;
	if (aspect >= 1)
	{
		c->half_width = half_view;
		c->half_height = half_view / aspect;
	}
	else
	{
		c->half_width = half_view * aspect;
		c->half_height = half_view;
	}
	c->pixel_size = (c->half_width * 2) / (double)c->hsize;
}

t_camera	camera(int hsize, int vsize, double fov)
{
	t_camera	c;

	c = (t_camera){
		.hsize = hsize,
		.vsize = vsize,
		.field_of_view = fov,
		.pixel_size = 0,
		.half_width = 0,
		.half_height = 0,
		.transform = create_identity_matrix()
	};
	calculate_pixel_cam(&c);
	return (c);
}

static t_ray	calculate_ray_cam(t_camera *c, t_matrix *inv_trans, \
									double wx, double wy)
{
	t_obj	pixel;
	t_obj	origin;
	t_obj	direction;

	pixel = multiply_matrix_by_obj(inv_trans, (t_obj){wx, wy, -1, 1}, 4, 4);
	origin = multiply_matrix_by_obj(inv_trans, (t_obj){0, 0, 0, 1}, 4, 4);
	direction = object_normalize(subtract_objects(pixel, origin));
	clean_matrix(inv_trans);
	return (create_ray(origin, direction));
}

t_ray	ray_for_pixel(t_camera *c, double px, double py)
{
	double		world_x;
	double		world_y;
	t_matrix	*inverse_transform;
	t_matrix	*origin;

	world_x = c->half_width - ((px + 0.5) * c->pixel_size);
	world_y = c->half_height - ((py + 0.5) * c->pixel_size);
	inverse_transform = inverse_matrix(c->transform);
	return (calculate_ray_cam(c, inverse_transform, world_x, world_y));
}

t_canvas	*render(t_camera *c, t_world *w)
{
	int			y;
	int			x;
	t_ray		ray;
	t_color		color;
	t_canvas	*image;

	y = 0;
	image = generate_canvas(c->hsize, c->vsize);
	while (y < c->vsize - 1)
	{
		x = 0;
		while (x < c->hsize - 1)
		{
			ray = ray_for_pixel(c, x, y);
			color = color_at(w, ray);
			write_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
	return (image);
}
