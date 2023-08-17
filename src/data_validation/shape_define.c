/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_define.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:38:28 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/16 20:23:20 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_define_sphere	define_sphere(char **params, t_world *world)
{
	t_define_sphere	sphere;

	sphere = (t_define_sphere){0};
	if (ft_arraylen(params) != 4)
		clean_parser_error(*world, params, "error code: 73 - Invalid quantity arguments");
	sphere.point = convert_point(params, world, 1);
	if (!is_valid_float(params[2]))
		clean_parser_error(*world, params, "error code: 33 - Number invalid");
	sphere.diameter = ft_atof(params[2]);
	sphere.material = new_material();
	sphere.transform = create_identity_matrix();
	sphere.material.color = convert_to_rgb(params, world, 3);
	return (sphere);
}

t_define_plane	define_plane(char **params, t_world *world)
{
	t_define_plane	plane;

	plane = (t_define_plane){0};
	if (ft_arraylen(params) != 4)
		clean_parser_error(*world, params, "error code: 92 - Invalid quantity arguments");
	plane.point = convert_point(params, world, 1);
	plane.vector = convert_vector(params, world, 2);
	if (!check_vector_normalize(plane.vector))
		clean_parser_error(*world, params, "error code: 07 - Invalid value");
	plane.material = new_material();
	plane.transform = create_identity_matrix();
	plane.material.color = convert_to_rgb(params, world, 3);
	return (plane);
}

t_define_cylinder	define_cylinder(char **params, t_world *world)
{
	t_define_cylinder	cylinder;

	cylinder = (t_define_cylinder){0};
	if (ft_arraylen(params) != 6)
		clean_parser_error(*world, params, "error code: 99 - Invalid quantity arguments");
	cylinder.point = convert_point(params, world, 1);
	cylinder.vector = convert_vector(params, world, 2);
	if (!check_vector_normalize(cylinder.vector))
		clean_parser_error(*world, params, "error code: 14 - Invalid value");
	if (!is_valid_float(params[3]))
		clean_parser_error(*world, params, "error code: 31 - Invalid value");
	cylinder.diameter = ft_atof(params[3]);
	if (!is_valid_float(params[4]))
		clean_parser_error(*world, params, "error code: 27 - Invalid value");
	cylinder.height = ft_atof(params[4]);
	cylinder.material = new_material();
	cylinder.transform = create_identity_matrix();
	cylinder.material.color = convert_to_rgb(params, world, 5);
	return (cylinder);
}
