/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_light_and_cam.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:45:32 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/16 18:51:28 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_define_a_light	define_ambient_light(char **params, t_world *world)
{
	t_define_a_light	a_light;

	a_light = (t_define_a_light){0};
	if (ft_arraylen(params) != 3)
		clean_parser_error(*world, params, "error code: 57 - Invalid quantity arguments");
	if (!is_valid_float(params[1]))
		clean_parser_error(*world, params, "error code: 54 - Number invalid");
	a_light.intensity = ft_atof(params[1]);
	if (a_light.intensity < 0 || a_light.intensity > 1)
		clean_parser_error(*world, params, "error code: 97 - Number out of range");	
	a_light.color = convert_to_rgb(params, world, 2);
	return (a_light);
}

t_define_light	define_light(char **params, t_world *world)
{
	t_define_light	light;

	light = (t_define_light){0};
	if (ft_arraylen(params) != 4)
		clean_parser_error(*world, params, "error code: 60 - Invalid quantity arguments");
	light.position = convert_point(params, world, 1);
	if (!is_valid_float(params[2]))
		clean_parser_error(*world, params, "error code: 01 - Number invalid");	
	light.intensity = ft_atof(params[2]);
	if (light.intensity < 0 || light.intensity > 1)
		clean_parser_error(*world, params, "error code: 98 - Number out of range");	
	light.color = convert_to_rgb(params, world, 3);
	return (light);
}

t_define_cam	define_camera(char **params, t_world *world)
{
	t_define_cam	cam;

	cam = (t_define_cam){0};
	cam.vsize = WIDTH;
	cam.hsize = HEIGHT;
	if (ft_arraylen(params) != 4)
		clean_parser_error(*world, params, "erro code: 11 - Invalid quantity arguments");
	if (!is_valid_float(params[3]))
		clean_parser_error(*world, params, "error code: 23 - Number invalid");
	cam.fov = ft_atof(params[3]);
	if (cam.fov < 0 || cam.fov > 180)
		clean_parser_error(*world, params, "error code: 24 - Number invalid");
	cam.point = convert_point(params, world, 1);
	cam.vector = convert_vector(params, world, 2);
	if (!check_vector_normalize(cam.vector))
		clean_parser_error(*world, params, "error code: 10 - Invalid param");
	return (cam);
}
