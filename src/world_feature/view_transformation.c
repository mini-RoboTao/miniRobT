/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transformation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:53:42 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/28 05:37:23 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	insert_row(t_matrix *m, t_obj o, int index)
{
	m->node[index][0] = o.x;
	m->node[index][1] = o.y;
	m->node[index][2] = o.z;
}

static t_matrix	*run_transform(t_obj left, t_obj true_up, \
								t_obj forward, t_obj from)
{
	t_matrix	*orientation;
	t_matrix	*m_translation;
	t_matrix	*m;

	orientation = alloc_matrix(4, 4);
	insert_row(orientation, left, 0);
	insert_row(orientation, true_up, 1);
	insert_row(orientation, negating_object(forward), 2);
	orientation->node[3][3] = 1;
	m_translation = translation(-from.x, -from.y, -from.z);
	m = multiply_matrix(orientation, m_translation, 4, 4);
	clean_matrix(m_translation);
	clean_matrix(orientation);
	return (m);
}

t_matrix	*view_transformation(t_obj from, t_obj to, t_obj up)
{
	t_obj		forward;
	t_obj		normalize_up;
	t_obj		left;
	t_obj		true_up;
	t_matrix	*m;

	forward = object_normalize(subtract_objects(to, from));
	normalize_up = object_normalize(up);
	left = object_cross_product(forward, normalize_up);
	true_up = object_cross_product(left, forward);
	m = run_transform(left, true_up, forward, from);
	// clean_obj(normalize_up);
	// clean_obj(forward);
	// clean_obj(left);
	// clean_obj(true_up);
	return (m);
}

t_color	color_at(t_world *w, t_ray *r)
{
	t_intersections	xs;
	t_intersection	*i;
	t_color			c;
	t_precomp		comps;

	xs = intersect_world(w, r);
	if (!xs.i)
	{
		if (xs.shape)
			free(xs.shape);
		return ((t_color){0, 0, 0});
	}
	i = hit(xs);
	c = (t_color){0, 0, 0};
	if (i)
	{
		comps = prepare_computations(i, r);
		c = shade_hit(w, &comps);
		// clean_obj(comps.point);
		// clean_obj(comps.normalv);
	}
	if (xs.shape)
		free(xs.shape);
	clean_intersection_lst(&xs.i);
	return (c);
}
