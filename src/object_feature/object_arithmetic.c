/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_arithmetic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:18:48 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/29 10:47:30 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_feature.h"

t_obj	*sum_objects(t_obj *o_one, t_obj *o_two)
{
	t_obj	*o;

	o = malloc(sizeof(t_obj));
	if (!o_one || !o_two)
		return (NULL);
	if (!o || (o_one->w == 1 && o_two->w == 1))
		return (NULL);
	o->x = o_one->x + o_two->x;
	o->y = o_one->y + o_two->y;
	o->z = o_one->z + o_two->z;
	o->w = o_one->w + o_two->w;
	return (o);
}

t_obj	*subtract_objects(t_obj *o_one, t_obj *o_two)
{
	t_obj	*o;

	o = malloc(sizeof(t_obj));
	if (!o_one || !o_two)
		return (NULL);
	if (!o || (o_one->w == 0 && o_two->w == 1))
		return (NULL);
	o->x = o_one->x - o_two->x;
	o->y = o_one->y - o_two->y;
	o->z = o_one->z - o_two->z;
	o->w = o_one->w - o_two->w;
	return (o);
}

t_obj	*negating_object(t_obj *vector)
{
	if (!vector)
		return (NULL);
	vector->x = -vector->x;
	vector->y = -vector->y;
	vector->z = -vector->z;
	vector->w = -vector->w;
	return (vector);
}

t_obj	*multiply_object(t_obj *o, double value)
{
	if (!o)
		return (NULL);
	o->x = o->x * value;
	o->y = o->y * value;
	o->z = o->z * value;
	o->w = o->w * value;
	return (o);
}

t_obj	*divide_object(t_obj *o, double value)
{
	if (!o || !value)
		return (NULL);
	o->x = o->x / value;
	o->y = o->y / value;
	o->z = o->z / value;
	o->w = o->w / value;
	return (o);
}
