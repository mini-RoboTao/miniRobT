/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_phong_reflection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 02:48:06 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/16 03:34:47 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	point_light(t_obj position, t_color intensity)
{
	t_light	light;

	light.position = position;
	light.intensity = intensity;
	return (light);
}

t_material	new_material(void)
{
	t_material	material;

	material.color = fill_color(1, 1, 1);
	material.ambient = 0.1;
	material.diffuse = 0.9;
	material.specular = 0.9;
	material.shininess = 200.0;
	material.reflective = 0.0;
	material.transparency = 0.0;
	material.refractive_index = 1.0;
	material.pattern.validate = false;
	return (material);
}

static void	calculate_diffuse_specular(t_lighting_data *data,
		t_lighting *lig, t_obj lightv)
{
	t_obj	reflectv;

	data->diffuse = multiply_scalar_colors(data->eff_color,
			(lig->material.diffuse * data->light_dot_normal));
	lightv = multiply_object(lightv, -1);
	reflectv = reflect(lightv, lig->normalv);
	data->reflect_dot_eye = object_dot(reflectv, lig->eyev);
	if (data->reflect_dot_eye <= 0)
		data->specular = fill_color(0, 0, 0);
	else
	{
		data->factor = pow(data->reflect_dot_eye, lig->material.shininess);
		data->specular = multiply_scalar_colors(lig->light.intensity, \
			(lig->material.specular * data->factor));
	}
}

t_color	lighting(t_lighting lig, t_obj over_point, t_color a_light)
{
	t_lighting_data	data;
	t_obj			lightv;
	t_color			color;

	if (lig.material.pattern.validate)
		color = pattern_at_shape(&lig.material.pattern, lig.shape, over_point);
	else
		color = multiply_colors(lig.material.color, a_light);
	data.eff_color = multiply_colors(color, lig.light.intensity);
	lightv = subtract_objects(lig.light.position, lig.point);
	lightv = object_normalize(lightv);
	data.ambient = multiply_scalar_colors(data.eff_color, lig.material.ambient);
	data.light_dot_normal = object_dot(lightv, lig.normalv);
	if (data.light_dot_normal < 0)
	{
		data.diffuse = fill_color(0, 0, 0);
		data.specular = fill_color(0, 0, 0);
	}
	else
		calculate_diffuse_specular(&data, &lig, lightv);
	if (lig.light.intensity.red == 0 && lig.light.intensity.green == 0 && lig.light.intensity.blue == 0)
		return (multiply_colors(color, a_light));
	if (lig.in_shadow)
		return (data.ambient);
	// printf("COLORS:\n\n");
	// printf("AMBIENT:\n%f\t%f\t%f\n", data.ambient.red, data.ambient.green, data.ambient.blue);
	// printf("AMBIENT:\n%f\t%f\t%f\n", a_light.red, a_light.green, a_light.blue);
	// return (multiply_colors(color, a_light));
	// return (color);
	return (sum_colors(sum_colors(data.ambient, data.diffuse), data.specular));
}
