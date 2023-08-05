/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:49:11 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/05 17:41:52 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	calculate_discriminat(double *abc, t_ray ray, t_shape shape)
{
	t_ray			r;
	t_obj			s_ray;
	double			discriminat;

	r = transform(ray, inverse_matrix(shape.sphere->transform));
	s_ray = subtract_objects(r.position, (t_obj){0, 0, 0, 1});
	abc[0] = object_dot(r.direction, r.direction);
	abc[1] = 2 * object_dot(r.direction, s_ray);
	abc[2] = object_dot(s_ray, s_ray) - 1;
	discriminat = pow(abc[1], 2) - 4 * abc[0] * abc[2];
	return (discriminat);
}

t_intersections	intersect(t_shape shape, t_ray ray)
{
	double			abc[3];
	double			discriminat;
	t_intersections	xs;

	xs = (t_intersections){0};
	discriminat = calculate_discriminat(abc, ray, shape);
	if (discriminat < 0)
		return ((t_intersections){0});
	intersections(&xs, \
	intersection((-abc[1] - (sqrt(discriminat))) / (2 * abc[0]), shape), \
	intersection((-abc[1] + (sqrt(discriminat))) / (2 * abc[0]), shape), 0);
	return (xs);
}

t_intersection	*intersection(double t, t_shape shape)
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
	xs->amount += 2;
	ft_lstrayadd_back(&xs->i, i1);
	ft_lstrayadd_back(&xs->i, i2);
}

// void	intersections(t_intersections *xs,
// 		t_intersection *i1, t_intersection *i2, int index)
// {
// 	xs->amount += 2;
// 	printf("intersections before xs\t%p\n", xs);
// 	printf("intersections before xs.i\t%p\n", xs->i);
// 	printf("intersection before i1\t%p\n", i1);
// 	printf("intersection before i2\t%p\n", i2);
// 	ft_lstrayadd_back(&xs->i, i1);
// 	// ft_lst_ray_sort_add(&xs->i, i1);
// 	printf("intersections after xs.i\t%p\n", xs->i);
// 	printf("intersection after i1\t%p\n", i1);
// 	printf("intersection after i2\t%p\n\n", i2);
// 	ft_lstrayadd_back(&xs->i, i2);
// 	// ft_lst_ray_sort_add(&xs->i, i2);
// }

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
