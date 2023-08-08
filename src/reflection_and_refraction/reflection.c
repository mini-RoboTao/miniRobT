/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:12:37 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/06 14:51:37 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	reflected_color(t_world w, t_precomp c, int remaining)
{
	t_color	color;
	t_ray	reflect_ray;

	color = fill_color(0, 0, 0);
	if (remaining <= 0)
		return (color);
	if (c.shape.any->material.reflective == 0)
		return (color);
	reflect_ray = create_ray(c.over_point, c.reflectv);
	color = color_at(&w, reflect_ray, remaining - 1);
	return (multiply_scalar_colors(color, c.shape.any->material.reflective));
}
