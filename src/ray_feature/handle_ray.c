/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:48:49 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/08 11:46:18 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	create_ray(t_obj point, t_obj vector)
{
	t_ray	ray;

	ray.position = point;
	ray.direction = vector;
	return (ray);
}

t_obj	cat_position(t_ray ray, double t)
{
	t_obj	o;
	t_obj	res;

	res = multiply_object(ray.direction, t);
	o = sum_objects(ray.position, res);
	return (o);
}
