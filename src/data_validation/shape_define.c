/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_define.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:38:28 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/11 19:35:27 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	define_sphere(char **params, t_world *world)
{
	t_shape	shape;
	double	scale;

	shape = new_sphere();
	set_transform2(&shape, convert_xyz(params[1], world));
	if (is_valid_float(params[2]))
	{
		scale = ft_atof(params[2]);
		set_transform2(&shape, scaling(scale, scale, scale));
	}
	shape.any->material = new_material();
	shape.any->material.color = convert_to_rgb(params[3], world);
	ft_lstadd_back(&world->lst, ft_lstnew(shape));
	return (true);
}

t_bool	define_plane(char **params, t_world *world)
{
	t_shape	shape;
	double	scale;

	shape = new_plane();
	set_transform2(&shape, convert_xyz(params[1], world));
	convert_normalize(params[2], &shape, world);
	shape.any->material = new_material();
	shape.any->material.color = convert_to_rgb(params[3], world);
	ft_lstadd_back(&world->lst, ft_lstnew(shape));
	return (true);
}

t_bool	define_cylinder(char **params, t_world *world)
{
	t_shape	shape;
	double	diameter;
	double	height;

	shape = new_cylinder();
	set_transform2(&shape, convert_xyz(params[1], world));
	convert_normalize(params[2], &shape, world);
	if (is_valid_float(params[3]))
	{
		diameter = ft_atof(params[3]);
		set_transform2(&shape, scaling(diameter, 1, diameter));
	}
	if (is_valid_float(params[4]))
	{
		height = ft_atof(params[4]);
		shape.any->maximum = height / 2;
		shape.any->minimum = -(height / 2);
	}
	shape.any->material = new_material();
	shape.any->material.color = convert_to_rgb(params[5], world);
	ft_lstadd_back(&world->lst, ft_lstnew(shape));
	return (true);
}
