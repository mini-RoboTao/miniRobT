/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_together.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:59:37 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/20 19:35:05 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_put_together	set_put_together(void)
{
	t_put_together	pt;

	pt = (t_put_together){0};
	pt.s = new_sphere();
	pt.wall_size = 7.0;
	pt.pixel_size = pt.wall_size / WIDTH;
	pt.half = pt.wall_size / 2;
	pt.color = fill_color(231, 100, 0);
	pt.ray_origin = create_point(0, 0, -5);
	pt.w_z = 10;
	return (pt);
}

void	clean_cicle(t_put_together *pt)
{
	if (pt->ray)
	{
		if (pt->ray->direction)
			free(pt->ray->direction);
		free(pt->ray);
	}
	clean_obj(pt->position);
	clean_intersection_lst(&pt->xs.i);
}

void	put_together(t_data *d)
{
	t_put_together	pt;

	pt = set_put_together();
	while (pt.y < HEIGHT)
	{
		pt.w_y = pt.half - pt.pixel_size * pt.y;
		pt.x = 0;
		while (pt.x < WIDTH)
		{
			pt.w_x = (-pt.half) + pt.pixel_size * pt.x;
			pt.position = create_point(pt.w_x, pt.w_y, pt.w_z);
			pt.ray = create_ray(pt.ray_origin, \
			object_normalize(subtract_objects(pt.position, pt.ray_origin)));
			pt.xs = intersect(pt.s, pt.ray);
			if (pt.xs.i && hit(pt.xs))
				write_pixel(d->canvas, pt.x, HEIGHT - pt.y, pt.color);
			clean_cicle(&pt);
			pt.x++;
		}
		pt.y++;
	}
	clean_obj(pt.ray_origin);
	clean_sphere(pt.s);
}
