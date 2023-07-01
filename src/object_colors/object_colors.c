/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:45:34 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/01 15:51:26 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#include <string.h>

t_color	fill_color(double red, double green, double blue)
{
	t_color	color;

	color.red = red;
	color.green = green;
	color.blue = blue;
	return (color);
}

t_color	sum_colors(t_color color_1, t_color color_2)
{
	t_color	res_color;

	res_color.red = color_1.red + color_2.red;
	res_color.green = color_1.green + color_2.green;
	res_color.blue = color_1.blue + color_2.blue;
	return (res_color);
}

t_color	subtract_colors(t_color color_1, t_color color_2)
{
	t_color	res_color;

	res_color.red = color_1.red - color_2.red;
	res_color.green = color_1.green - color_2.green;
	res_color.blue = color_1.blue - color_2.blue;
	return (res_color);
}

t_color	multiply_scalar_colors(t_color color_1, double scalar)
{
	t_color	res_color;

	res_color.red = color_1.red * scalar;
	res_color.green = color_1.green * scalar;
	res_color.blue = color_1.blue * scalar;
	return (res_color);
}

t_color	multiply_colors(t_color color_1, t_color color_2)
{
	t_color	res_color;

	res_color.red = color_1.red * color_2.red;
	res_color.green = color_1.green * color_2.green;
	res_color.blue = color_1.blue * color_2.blue;
	return (res_color);
}
