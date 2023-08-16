/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_light_and_cam.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:45:32 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/16 03:54:44 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_define_a_light	define_ambient_light(char **params, t_world *world)
{
	t_define_a_light	a_light;
	double	scalar;

	if (ft_arraylen(params) != 3)
		clean_parser_error(*world, params, "error code: 57 - Invalid quantity arguments");
	if (!is_valid_float(params[1]))
		clean_parser_error(*world, params, "error code: 54 - Number invalid");
	a_light.intensity = ft_atof(params[1]);
	if (a_light.intensity < 0 || a_light.intensity > 1)
		clean_parser_error(*world, params, "error code: 97 - Number out of range");	
	// a_light.color = convert_to_rgb(params, world, 2);
	a_light.color = multiply_scalar_colors(convert_to_rgb(params, world, 2), a_light.intensity);
	//world->a_light = convert_to_rgb(params, world, 2);
	//world->a_light = multiply_scalar_colors(world->a_light, scalar);
	printf("define a_light: %f %f %f\n", a_light.color.red, a_light.color.green, a_light.color.blue);
	return (a_light);
}

t_define_light	define_light(char **params, t_world *world)
{
	t_define_light	light;

	if (ft_arraylen(params) != 4)
		clean_parser_error(*world, params, "error code: 60 - Invalid quantity arguments");
	light.position = convert_point(params, world, 1);
	if (!is_valid_float(params[2]))
		clean_parser_error(*world, params, "error code: 01 - Number invalid");	
	light.intensity = ft_atof(params[2]);
	if (light.intensity < 0 || light.intensity > 1)
		clean_parser_error(*world, params, "error code: 98 - Number out of range");	
	light.color = convert_to_rgb(params, world, 3);
	//color = multiply_scalar_colors(color, intensity);
	//world->light = point_light(position, color);
	// world->light = point_light(position, sum_colors(color, world->a_light));
	printf("define light: %f %f %f\n", light.color.red, light.color.green, light.color.blue);
	return (light);
}

t_define_cam	define_camera(char **params, t_world *world)
{
	t_define_cam	cam;

	if (ft_arraylen(params) != 4)
		clean_parser_error(*world, params, "erro code: 11 - Invalid quantity arguments");
	if (!is_valid_float(params[3]))
		clean_parser_error(*world, params, "error code: 23 - Number invalid");
	cam.fov = ft_atof(params[3]);
	if (cam.fov < 0 || cam.fov > 180)
		clean_parser_error(*world, params, "error code: 24 - Number invalid");
	cam.vector = convert_normalize_cam(params, world, 2);
	cam.point = convert_point(params, world, 1);
	cam.vsize = WIDTH;
	cam.hsize = HEIGHT;
	return (cam);
}
