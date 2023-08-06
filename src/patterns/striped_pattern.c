/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striped_pattern.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:45:31 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/06 21:00:01 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pattern	stripe_pattern(t_color a, t_color b)
{
	t_pattern	pattern;

	pattern.a = a;
	pattern.b = b;
	pattern.validate = true;
	pattern.type = stripe;
	pattern.transform = create_identity_matrix();
	return (pattern);
}

t_color	stripe_at(t_pattern pattern, t_obj point)
{
	t_color	res;
	int		modx;

	modx = floor(point.x);
	if ((modx % 2) == 0)
		res = pattern.a;
	else
		res = pattern.b;
	return (res);
}

/*
t_color	stripe_at_object(t_pattern *pattern, t_shape shape, t_obj world_point)
{
	t_obj	obj_point;
	t_obj	pattern_point;

	obj_point = multiply_matrix_by_obj(inverse_matrix(shape.any->transform),
			world_point, 4, 4);
	pattern_point = multiply_matrix_by_obj(inverse_matrix(pattern->transform),
			obj_point, 4, 4);
	return (stripe_at(*pattern, pattern_point));
}
*/
