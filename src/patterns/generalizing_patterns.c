/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generalizing_patterns.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:50:46 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/10 03:38:38 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pattern	test_pattern(void)
{
	t_pattern	pattern;

	pattern.transform = create_identity_matrix();
	pattern.type = test;
	pattern.b = fill_color(1, 1, 1);
	pattern.a = fill_color(0, 0, 0);
	return (pattern);
}

t_color	pattern_at(t_pattern pattern, t_obj point)
{
	if (pattern.type == stripe)
		return (stripe_at(pattern, point));
	if (pattern.type == gradient)
		return (gradient_at(pattern, point));
	if (pattern.type == ring)
		return (ring_at(pattern, point));
	if (pattern.type == checkers)
		return (checkers_at(pattern, point));
	if (pattern.type == alt_checkers)
		return (alt_checkers_at(pattern, point));
	return (fill_color(point.x, point.y, point.z));
}

t_color	pattern_at_shape(t_pattern *pattern, t_shape shape, t_obj world_point)
{
	t_obj	obj_point;
	t_obj	pattern_point;

	obj_point = multiply_matrix_by_obj(inverse_matrix(shape.any->transform),
			world_point, 4, 4);
	pattern_point = multiply_matrix_by_obj(inverse_matrix(pattern->transform),
			obj_point, 4, 4);
	if (pattern->type == stripe)
		return (stripe_at(*pattern, pattern_point));
	else if (pattern->type == gradient)
		return (gradient_at(*pattern, pattern_point));
	else if (pattern->type == ring)
		return (ring_at(*pattern, pattern_point));
	else if (pattern->type == checkers)
		return (checkers_at(*pattern, pattern_point));
	return (pattern_at(*pattern, pattern_point));
}
