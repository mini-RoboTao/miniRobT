/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_phong_reflection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 02:48:06 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/21 05:25:57 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	*point_light(t_obj *position, t_color intensity)
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

// t_color	lighting(t_lighting lig)
// {
// 	t_color	effective_color;
// 	effective_color = multiply_colors(lig.material.color, lig.light->intensity);
// 	t_obj	*lightv;
// 	t_obj	*light_pos_minus_point;
// 	light_pos_minus_point = subtract_objects(lig.light->position, lig.point);
// 	lightv = object_normalize(light_pos_minus_point);

// 	t_color	ambient;
// 	ambient = multiply_scalar_colors(effective_color, lig.material.ambient);

// 	double	light_dot_normal;
// 	light_dot_normal = object_dot(lightv, lig.normalv);

// 	t_color	diffuse;
// 	t_color	specular;
// 	if (light_dot_normal < 0)
// 	{
// 		diffuse = fill_color(0, 0, 0);
// 		specular = fill_color(0, 0, 0);
// 	}
// 	else
// 	{
// 		diffuse = multiply_scalar_colors(effective_color,
// 			(lig.material.diffuse * light_dot_normal));
// 		t_obj	*reflectv;
// 		t_obj	*neglightv = multiply_object(lightv, -1);
// 		reflectv = reflect(neglightv, lig.normalv);
// 		double reflect_dot_eye;
// 		reflect_dot_eye = object_dot(reflectv, lig.eyev);
// 		printf("reflect_dot_eye %f\n", reflect_dot_eye);
// 		if (reflect_dot_eye <= 0)
// 			specular = fill_color(0, 0, 0);
// 		else
// 		{
// 			double	factor;
// 			factor = pow(reflect_dot_eye, lig.material.shininess);
// 			printf("factor %f\n", factor);
// 			specular = multiply_scalar_colors(lig.light->intensity,
// 				(lig.material.specular * factor));
// 		}
// 	}
// 	printf("%f %f %f\n", ambient.red, ambient.green, ambient.blue);
// 	printf("%f %f %f\n", diffuse.red, diffuse.green, diffuse.blue);
// 	printf("%f %f %f\n", specular.red, specular.green, specular.blue);

// 	t_color res = sum_colors(ambient, diffuse);
// 	printf("%f %f %f\n", res.red, res.green, res.blue);

// 	t_color	res2 = sum_colors(res, specular);
// 	printf("%f %f %f\n", res2.red, res2.green, res2.blue);

// 	return (res2);
// }