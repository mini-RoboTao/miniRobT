/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:49:11 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/28 06:08:11 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	calculate_discriminat(double *abc, t_ray *ray, t_sphere *s)
{
	t_ray			*r;
	t_obj			s_ray;
	t_matrix		*m;
	double			discriminat;

	m = inverse_matrix(s->transform);
	r = transform(ray, m);
	clean_matrix(m);
	s_ray = subtract_objects(r->position, (t_obj){0, 0, 0, 1});
	abc[0] = object_dot(r->direction, r->direction);
	abc[1] = 2 * object_dot(r->direction, s_ray);
	abc[2] = object_dot(s_ray, s_ray) - 1;
	discriminat = pow(abc[1], 2) - 4 * abc[0] * abc[2];
	return (discriminat);
}

t_intersections	intersect(t_sphere *s, t_ray *ray)
{
	double			abc[3];
	double			discriminat;
	t_intersections	xs;

	xs = (t_intersections){0};
	discriminat = calculate_discriminat(abc, ray, s);
	if (discriminat < 0)
		return ((t_intersections){0});
	xs.shape = malloc(sizeof(void *));
	intersections(&xs, \
	intersection((-abc[1] - (sqrt(discriminat))) / (2 * abc[0]), s), \
	intersection((-abc[1] + (sqrt(discriminat))) / (2 * abc[0]), s), 0);
	xs.shape[0] = s;
	return (xs);
}

t_intersection	*intersection(double t, void *shape)
{
	t_intersection	*head;

	head = malloc(sizeof(t_intersection));
	if (!head)
		return (NULL);
	head->v = shape;
	head->t = t;
	head->next = NULL;
	return (head);
}

void	intersections(t_intersections *xs, \
		t_intersection *i1, t_intersection *i2, int index)
{
	if (!xs->i)
		xs->shape[index] = i1->v;
	xs->amount += 2;
	ft_lstrayadd_back(&xs->i, i1);
	ft_lstrayadd_back(&xs->i, i2);
}

t_intersection	*hit(t_intersections xs)
{
	int				i;
	double			minor_value;
	int				pos;
	t_intersection	*start;

	i = 0;
	pos = 0;
	start = xs.i;
	minor_value = xs.i->t;
	while (xs.i)
	{
		if ((xs.i->t < minor_value || minor_value < 0) && xs.i->t >= 0)
		{
			minor_value = xs.i->t;
			pos = i;
		}
		xs.i = xs.i->next;
		i++;
	}
	if (minor_value < 0)
		return (NULL);
	i = -1;
	while (start && ++i < pos)
		start = start->next;
	return (start);
}
