/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:49:11 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/16 17:03:30 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	calculate_discriminat(double *abc, t_ray ray, t_shape shape)
{
	t_ray			r;
	t_obj			s_ray;
	double			discriminat;

	shape.any->saved_ray = ray;
	s_ray = subtract_objects(ray.position, (t_obj){0, 0, 0, 1});
	abc[0] = object_dot(ray.direction, ray.direction);
	abc[1] = 2 * object_dot(ray.direction, s_ray);
	abc[2] = object_dot(s_ray, s_ray) - 1;
	discriminat = pow(abc[1], 2) - 4 * abc[0] * abc[2];
	return (discriminat);
}

void	intersect(t_intersections *xs, t_shape shape, t_ray ray)
{
	return (shape.intersect(xs, shape, \
		transform(ray, inverse_matrix(shape.any->transform))));
}

t_intersection	*intersection(double t, t_shape shape, t_intersections *xs)
{
	t_intersection	*head;

	head = malloc(sizeof(t_intersection));
	if (!head)
		return (NULL);
	head->shape = shape;
	head->t = t;
	head->next = NULL;
	return (head);
}

void	intersections(t_intersections *xs, \
		t_intersection *i1, t_intersection *i2)
{
	static size_t	id;

	if (i1)
	{
		xs->amount += 1;
		ft_lst_ray_sort_add(&xs->i, i1);
	}
	if (i2)
	{
		xs->amount += 1;
		ft_lst_ray_sort_add(&xs->i, i2);
	}
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
