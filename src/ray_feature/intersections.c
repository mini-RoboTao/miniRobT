/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:49:11 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/12 12:56:59 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*new_sphere(void)
{
	t_sphere	*s;

	s = malloc(sizeof(t_sphere));
	if (!s)
		return (NULL);
	s->x = 0.0;
	s->y = 0.0;
	s->z = 0.0;
	s->radius = 1.0;
	return (s);
}

t_intersect	intersect(t_sphere *s, t_ray *r)
{
	double	a;
	double	b;
	double	c;
	double	discriminat;
	t_obj	*s_ray;

	s_ray = subtract_objects(r->position, &(t_obj){0, 0, 0, 1});
	a = object_dot(r->direction, r->direction);
	b = 2 * object_dot(r->direction, s_ray);
	c = object_dot(s_ray, s_ray) - 1;
	discriminat = pow(b, 2) - 4 * a * c;
	if (s_ray)
		free(s_ray);
	if (discriminat < 0)
		return ((t_intersect){.amount = 0, .collision = {0, 0}});
	return ((t_intersect){.amount = 2, .collision = {\
	(-b - (sqrt(discriminat))) / (2 * a), \
	(-b + (sqrt(discriminat))) / (2 * a)}});
}

t_intersection	*intersection(double t, t_sphere *s)
{
	t_intersection	*i;

	i = malloc(sizeof(t_intersection));
	i->sphere = s;
	i->t = t;
	return (i);
}
