/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_define.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:38:28 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/15 23:28:33 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_define_sphere	define_sphere(char **params, t_world *world)
{
	t_define_sphere	sphere;
//	t_shape	shape;
//	double	scale;

	if (ft_arraylen(params) != 4)
		clean_parser_error(*world, params, "error code: 73 - Invalid quantity arguments");
	sphere.transform = create_identity_matrix();
	sphere.point = convert_point(params, world, 1);
	if (!is_valid_float(params[2]))
		clean_parser_error(*world, params, "error code: 33 - Number invalid");
	sphere.diameter = ft_atof(params[2]);
	sphere.material = new_material();
	sphere.material.color = convert_to_rgb(params, world, 3);
	//set_transform2(&shape, scaling(scale, scale, scale));
	//set_transform2(&sphere., convert_xyz(params, world, 1));
	//shape.any->material = new_material();
	//shape.any->material.color = convert_to_rgb(params, world, 3);
	//ft_lstadd_back(&world->lst, ft_lstnew(shape));
	//shape = new_sphere();
	return (sphere);
}

t_define_plane	define_plane(char **params, t_world *world)
{
	t_define_plane	plane;

	if (ft_arraylen(params) != 4)
		clean_parser_error(*world, params, "error code: 92 - Invalid quantity arguments");
	plane.point = convert_point(params, world, 1);
	plane.vector = convert_vector(params, world, 2);
	if (!check_vector_normalize(plane.vector))
		clean_parser_error(*world, params, "error code: 07 - Invalid value");
	plane.material = new_material();
	plane.material.color = convert_to_rgb(params, world, 3);
	//shape = new_plane();
	//set_transform2(&shape, convert_xyz(params, world, 1));
	//convert_normalize(params, &shape, world, 2);
	//shape.any->material = new_material();
	//shape.any->material.color = convert_to_rgb(params, world, 3);
	//ft_lstadd_back(&world->lst, ft_lstnew(shape));
	return (plane);
}

t_define_cylinder	define_cylinder(char **params, t_world *world)
{
	t_define_cylinder	cylinder;
	// t_shape	shape;
	// double	diameter;
	// double	height;

	cylinder = (t_define_cylinder){0};
	if (ft_arraylen(params) != 6)
		clean_parser_error(*world, params, "error code: 99 - Invalid quantity arguments");
	cylinder.point = convert_point(params, world, 1);
	cylinder.vector = convert_vector(params, world, 2);
	if (!check_vector_normalize(cylinder.vector))
		clean_parser_error(*world, params, "error code: 14 - Invalid value");
	cylinder.material = new_material();
	if (!is_valid_float(params[3]))
		clean_parser_error(*world, params, "error code: 31 - Invalid value");
	cylinder.diameter = ft_atof(params[3]);
	if (!is_valid_float(params[4]))
		clean_parser_error(*world, params, "error code: 27 - Invalid value");
	cylinder.height = ft_atof(params[4]);
	cylinder.material.color = convert_to_rgb(params, world, 5);
	// shape = new_cylinder();
	// set_transform2(&shape, convert_xyz(params, world, 1));
	// convert_normalize(params, &shape, world, 2);
	// if (is_valid_float(params[3]))
	// {
	// 	diameter = ft_atof(params[3]);
	// 	set_transform2(&shape, scaling(diameter, 1, diameter));
	// }
	// if (is_valid_float(params[4]))
	// {
	// 	height = ft_atof(params[4]);
	// 	shape.any->maximum = height / 2;
	// 	shape.any->minimum = -(height / 2);
	// }
	// shape.any->material = new_material();
	// shape.any->material.color = convert_to_rgb(params, world, 5);
	// ft_lstadd_back(&world->lst, ft_lstnew(shape));
	return (cylinder);
}
