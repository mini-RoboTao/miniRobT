/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:11:28 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/28 05:05:46 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_feature.h"

double	object_magnitude(t_obj o)
{
	double	res;

	res = sqrt(pow(o.x, 2) + pow(o.y, 2) + pow(o.z, 2) + pow(o.w, 2));
	return (res);
}

t_obj	object_normalize(t_obj o)
{
	double	magnitude;

	magnitude = object_magnitude(o);
	o.x = o.x / magnitude;
	o.y = o.y / magnitude;
	o.z = o.z / magnitude;
	o.w = o.w / magnitude;
	return (o);
}

double	object_dot(t_obj o_one, t_obj o_two)
{
	return (o_one.x * o_two.x + o_one.y * o_two.y + o_one.z * \
	o_two.z + o_one.w * o_two.w);
}

t_obj	object_cross_product(t_obj o_one, t_obj o_two)
{
	return (create_vector(o_one.y * o_two.z - o_one.z * o_two.y, \
	o_one.z * o_two.x - o_one.x * o_two.z, \
	o_one.x * o_two.y - o_one.y * o_two.x));
}
