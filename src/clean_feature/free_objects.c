/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:07:36 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/05 17:12:24 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clean_shape(t_shape *obj)
{
	if (obj->v)
		free(obj->v);
}

void	clean_sphere(t_sphere *s)
{
	if (s)
		free(s);
}

void	clean_ray_inter_shape(t_intersection **i, void **shape)
{
	clean_intersection_lst(i);
	free(shape);
}
