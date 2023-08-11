/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_light_and_cam.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:45:32 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/11 19:38:00 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	define_ambient_light(char **params, t_world *world)
{
	double	scalar;

	if (is_valid_float(params[1]))
	{
		scalar = ft_atof(params[1]);
		world->a_light = convert_to_rgb(params[2], world);
		world->a_light = multiply_scalar_colors(world->a_light, scalar);
	}
	return (true);
}

t_bool	define_light(char **params, t_world *world)
{
	t_color	color;
	t_obj	position;
	double	intensity;

	position = convert_point(params[1], world);
	if (is_valid_float(params[2]))
		intensity = ft_atof(params[2]);
	color = convert_to_rgb(params[3], world);
	color = multiply_scalar_colors(color, intensity);
	world->light = point_light(position, sum_colors(color, world->a_light));
	return (true);
}

t_bool	define_camera(char **params, t_world *world)
{
	t_camera	cam;
	t_obj		norm;
	double		fov;
	double		scale;

	if (is_valid_float(params[3]))
		fov = ft_atof(params[3]);
	cam = camera(WIDTH, HEIGHT, fov);
	norm = convert_normalize_cam(params[2], world);
	cam.transform = view_transformation(convert_point(params[1], world), \
	norm, create_vector(0, 1, 0));
	world->camera = cam;
	return (true);
}
