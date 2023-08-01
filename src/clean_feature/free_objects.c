/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:07:36 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/02 00:25:00 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	clean_env(t_environment *c)
// {
// 	if (c)
// 	{
// 		if (c->gravity)
// 			free(c->gravity);
// 		if (c->wind)
// 			free(c->wind);
// 		free(c);
// 	}
// }

// void	clean_ray(t_ray *r)
// {
// 	if (r)
// 	{
// 		if (r->position)
// 			free(r->position);
// 		if (r->direction)
// 			free(r->direction);
// 		free(r);
// 	}
// }

// void	clean_proj(t_projectile *c)
// {
// 	if (c)
// 	{
// 		if (c->position)
// 			free(c->position);
// 		if (c->velocity)
// 			free(c->velocity);
// 		free(c);
// 	}
// }

void	clean_sphere(t_sphere *s)
{
	if (s)
	{
		clean_matrix(s->transform);
		free(s);
	}
}

void	clean_ray_inter_shape(t_intersection **i, void **shape)
{
	clean_intersection_lst(i);
	free(shape);
}
