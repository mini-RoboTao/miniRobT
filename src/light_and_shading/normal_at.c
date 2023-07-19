/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:49:46 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/18 23:56:10 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

	// point->x = point->x - sphere->x;
	// point->y = point->y - sphere->y;
	// point->z = point->z - sphere->z;

t_obj	*normal_at(t_sphere *sphere, t_obj *point)
{
	t_obj	*vec;

	vec = create_vector(point->x - sphere->x, point->y - sphere->y,
			point->z - sphere->z);
	return (object_normalize(vec));
}

// t_obj	*normal_at(t_sphere *sphere, t_obj *world_point)
// {
// 	t_obj	*vec;

// 	vec = create_vector(point->x - sphere->x, point->y - sphere->y,
// 			point->z - sphere->z);
// 	return (object_normalize(vec));
// }
