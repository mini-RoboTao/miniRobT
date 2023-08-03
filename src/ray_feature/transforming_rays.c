/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforming_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:06:15 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/03 02:01:03 by dapaulin         ###   ########.fr       */
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
