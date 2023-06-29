/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_arithmetic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:18:48 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/29 00:11:27 by dapaulin         ###   ########.fr       */
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
	if (!o || !o_one || !o_two)
		return (NULL);
	o->x = o_one->x - o_two->x;
	o->y = o_one->y - o_two->y;
	o->z = o_one->z - o_two->z;
	o->w = o_one->w - o_two->w;
	return (o);
}
