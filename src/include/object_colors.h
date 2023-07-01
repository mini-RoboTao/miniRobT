/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_colors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:43:05 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/01 16:05:37 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_COLORS_H
# define OBJECT_COLORS_H

# include "minirt.h"

t_color	fill_color(double red, double green, double blue);
t_color	sum_colors(t_color color_1, t_color color_2);
t_color	subtract_colors(t_color color_1, t_color color_2);
t_color	multiply_scalar_colors(t_color color_1, double scalar);
t_color	multiply_colors(t_color color_1, t_color color_2);

#endif