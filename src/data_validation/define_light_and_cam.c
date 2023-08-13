/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_light_and_cam.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:45:32 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/12 22:27:31 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	define_ambient_light(char **params, t_world *world)
{
	double	scalar;

	if (ft_arraylen(params) != 3)
		clean_parser_error(*world, params, "error code: 57 - Invalid quantity arguments");
	if (!is_valid_float(params[1]))
		clean_parser_error(*world, params, "error code: 54 - Number invalid");
	scalar = ft_atof(params[1]);
	world->a_light = convert_to_rgb(params, world, 2);
	world->a_light = multiply_scalar_colors(world->a_light, scalar);
	return (true);
}

t_bool	define_light(char **params, t_world *world)
{
	t_color	color;
	t_obj	position;
	double	intensity;

	if (ft_arraylen(params) != 4)
		clean_parser_error(*world, params, "error code: 60 - Invalid quantity arguments");
	position = convert_point(params, world, 1);
	if (is_valid_float(params[2]))
		intensity = ft_atof(params[2]);
	color = convert_to_rgb(params, world, 3);
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

	printf("CAMERAAAA\n");
	if (ft_arraylen(params) != 4)
		clean_parser_error(*world, params, "Invalid quantity arguments");
	if (!is_valid_float(params[3]))
		clean_parser_error(*world, params, "Number invalid");
	fov = ft_atof(params[3]);
	norm = convert_normalize_cam(params, world, 2);
	cam = camera(WIDTH, HEIGHT, fov);
	cam.transform = view_transformation(convert_point(params, world, 1), norm, create_vector(0, 1, 0));
	world->camera = cam;
	return (true);
}
