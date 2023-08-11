/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforming_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:06:15 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/11 19:18:40 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	transform(t_ray r, t_matrix m)
{
	return (create_ray(multiply_matrix_by_obj(m, r.position, 4, 4), \
	multiply_matrix_by_obj(m, r.direction, 4, 4)));
}

void	set_transform(t_shape *shape, t_matrix t)
{
	shape->any->transform = t;
}

void	set_transform2(t_shape *shape, t_matrix t)
{
	shape->any->transform = multiply_matrix(shape->any->transform, t, 4, 4);
}

// void	set_transform_cam(t_camera *cam, t_matrix t)
// {
// 	cam->transform = multiply_matrix(cam->transform, t, 4, 4);
// }
