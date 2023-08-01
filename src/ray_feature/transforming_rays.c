/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforming_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:06:15 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/01 23:26:14 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	transform(t_ray r, t_matrix *m)
{
	return (create_ray(multiply_matrix_by_obj(m, r.position, 4, 4), \
	multiply_matrix_by_obj(m, r.direction, 4, 4)));
}

void	set_transform(t_sphere *s, t_matrix *t)
{
	if (s->transform)
		clean_matrix(s->transform);
	s->transform = t;
}
