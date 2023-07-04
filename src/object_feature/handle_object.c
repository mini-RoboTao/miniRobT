/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:11:28 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/02 18:42:24 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_feature.h"

double	object_magnitude(t_obj *o)
{
	double	res;

	if (!o)
		return (0);
	res = sqrt(pow(o->x, 2) + pow(o->y, 2) + pow(o->z, 2) + pow(o->w, 2));
	return (res);
}

t_obj	*object_normalize(t_obj *o)
{
	double	magnitude;

	if (!o)
		return (NULL);
	magnitude = object_magnitude(o);
	o->x = o->x / magnitude;
	o->y = o->y / magnitude;
	o->z = o->z / magnitude;
	o->w = o->w / magnitude;
	return (o);
}

double	object_dot(t_obj *o_one, t_obj *o_two)
{
	if (!o_one || !o_two)
		return (0);
	return (o_one->x * o_two->x + o_one->y * o_two->y + o_one->z * \
	o_two->z + o_one->w * o_two->w);
}

t_obj	*object_cross_product(t_obj *o_one, t_obj *o_two)
{
	if (!o_one || !o_two)
		return (NULL);
	return (create_vector(o_one->y * o_two->z - o_one->z * o_two->y, \
	o_one->z * o_two->x - o_one->x * o_two->z, \
	o_one->x * o_two->y - o_one->y * o_two->x));
}
