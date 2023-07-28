/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_phong_reflection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 02:48:06 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/28 05:32:53 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	*point_light(t_obj position, t_color intensity)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->position = position;
	light->intensity = intensity;
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
		data->specular = multiply_scalar_colors(lig->light->intensity, \
			(lig->material.specular * data->factor));
	}
	// clean_obj(reflectv);
}

t_color	lighting(t_lighting lig)
{
	t_lighting_data	data;
	t_obj			lightv;

	data.eff_color = multiply_colors(lig.material.color, lig.light->intensity);
	lightv = subtract_objects(lig.light->position, lig.point);
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
	// clean_obj(lightv);
	if (lig.in_shadow)
		return (data.ambient);
	return (sum_colors(sum_colors(data.ambient, data.diffuse), data.specular));
}
