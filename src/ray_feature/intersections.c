/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:49:11 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/09 05:52:37 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// double	calculate_discriminat(double *abc, t_ray ray, t_shape shape)
// {
// 	t_obj			s_ray;
// 	double			discriminat;

// 	//transform(ray, inverse_matrix(shape.any->transform));
// 	s_ray = subtract_objects(ray.position, (t_obj){0, 0, 0, 1});
// 	abc[0] = object_dot(ray.direction, ray.direction);
// 	abc[1] = 2 * object_dot(ray.direction, s_ray);
// 	abc[2] = object_dot(s_ray, s_ray) - 1;
// 	discriminat = pow(abc[1], 2) - 4 * abc[0] * abc[2];
// 	return (discriminat);
// }

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

t_intersections	intersect(t_shape shape, t_ray ray)
{
	return (shape.intersect(shape, \
		transform(ray, inverse_matrix(shape.any->transform))));
}

// t_intersections	intersect(t_shape shape, t_ray ray)
// {
// 	double			abc[3];
// 	double			discriminat;
// 	double			sqrtdis;
// 	t_ray			tmp_ray;
// 	t_intersections	xs;

// 	xs = (t_intersections){0};
// 	tmp_ray = transform(ray, inverse_matrix(shape.any->transform));
// 	if (shape.id == 3)
// 	{
// 		if (fabs(tmp_ray.direction.y) < EPSILON)
// 			return ((t_intersections){0});
// 		intersections(&xs,
// 		intersection((-tmp_ray.position.y) / tmp_ray.direction.y, shape, &xs),
// 		NULL, 0);
// 	}
// 	else if (shape.id == 1)
// 	{
// 		discriminat = calculate_discriminat(abc, tmp_ray, shape);
// 		if (discriminat < 0)
// 			return ((t_intersections){0});
// 		sqrtdis = sqrt(discriminat);
// 		intersections(&xs,
// 		intersection((-abc[1] - (sqrtdis)) / (2 * abc[0]), shape, &xs),
// 		intersection((-abc[1] + (sqrtdis)) / (2 * abc[0]), shape, &xs), 0);
// 	}
// 	return (xs);
// }

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
		t_intersection *i1, t_intersection *i2, int index)
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
