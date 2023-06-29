/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:02:45 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/28 20:47:06 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_feature.h"

t_obj	*create_object(double x, double y, double z, double w)
{
	t_obj	*o;

	o = malloc(sizeof(t_obj));
	if (!o)
		return (NULL);
	o->x = x;
	o->y = y;
	o->z = z;
	o->w = w;
	return (o);
}

t_obj	*create_point(double x, double y, double z)
{
	return (create_object(x, y, z, 1));
}

t_obj	*create_vector(double x, double y, double z)
{
	return (create_object(x, y, z, 0));
}
