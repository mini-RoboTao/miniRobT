/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_pattern.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:45:22 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/06 22:42:56 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pattern	gradient_pattern(t_color a, t_color b)
{
	t_pattern	pattern;

	pattern.a = a;
	pattern.b = b;
	pattern.validate = true;
	pattern.type = gradient;
	pattern.transform = create_identity_matrix();
	return (pattern);
}

t_color	gradient_at(t_pattern pattern, t_obj point)
{
	t_color	distance;
	double	fraction;

	distance = subtract_colors(pattern.b, pattern.a);
	fraction = point.x - floor(point.x);
	return (sum_colors(pattern.a, multiply_scalar_colors(distance, fraction)));
}
