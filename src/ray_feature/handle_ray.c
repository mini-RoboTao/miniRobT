/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:48:49 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/11 20:50:00 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	*create_ray(t_obj *point, t_obj *vector)
{
	t_ray	*ray;

	if (!point || !vector)
		return (NULL);
	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->position = point;
	ray->direction = vector;
	return (ray);
}

t_obj	*cat_position(t_ray *ray, double t)
{
	t_obj	*o;

	multiply_object(ray->direction, t);
	o = sum_objects(ray->position, ray->direction);
	if (!o)
		return (NULL);
	return (o);
}
