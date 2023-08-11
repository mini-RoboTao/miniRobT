/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparency_and_refraction.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:19:54 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/11 06:37:14 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	determining_n(t_lst *containers)
{
	if (!containers)
		return (1.0);
	else
		return (ft_lstlast(containers)->shape.any->material.refractive_index);
}

int	shape_in_the_lst(t_lst *lst, t_shape find)
{
	while (lst)
	{
		if (lst->shape.any == find.any)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	determining_n1_and_n2(t_intersections *xs, t_intersection *hit, \
		t_precomp *comps)
{
	t_lst			*containers;
	t_intersection	*head;

	containers = NULL;
	head = xs->i;
	while (head)
	{
		if (head == hit)
			comps->n1 = determining_n(containers);
		if (shape_in_the_lst(containers, head->shape))
			ft_lstremove(&containers, head->shape);
		else
			ft_lstadd_back(&containers, ft_lstnew(head->shape));
		if (head == hit)
		{
			comps->n2 = determining_n(containers);
			ft_only_lstclean(&containers);
			break ;
		}
		head = head->next;
	}
}

t_color	refracted_color(t_world w, t_precomp comps, int remaining)
{
	double	n_ratio;
	double	cos_i;
	double	sin2_t;
	double	cos_t;
	t_obj	direction;

	n_ratio = comps.n1 / comps.n2;
	cos_i = object_dot(comps.eyev, comps.normalv);
	sin2_t = pow(n_ratio, 2) * (1 - pow(cos_i, 2));
	cos_t = sqrt(1.0 - sin2_t);
	direction = subtract_objects(\
				multiply_object(comps.normalv, (n_ratio * cos_i - cos_t)), \
				multiply_object(comps.eyev, n_ratio));
	if (remaining <= 0 || comps.shape.any->material.transparency == 0 \
		|| sin2_t > 1)
		return (fill_color(0, 0, 0));
	return (multiply_scalar_colors(color_at(&w, \
			create_ray(comps.under_point, direction), remaining - 1), \
			comps.shape.any->material.transparency));
}

double	schlick(t_precomp comps)
{
	double	cos;
	double	n;
	double	sin2_t;
	double	cos_t;
	double	r0;

	cos = object_dot(comps.eyev, comps.normalv);
	if (comps.n1 > comps.n2)
	{
		n = comps.n1 / comps.n2;
		sin2_t = pow(n, 2) * (1.0 - pow(cos, 2));
		if (sin2_t > 1.0)
			return (1.0);
		cos_t = sqrt(1.0 - sin2_t);
		cos = cos_t;
	}
	r0 = pow((comps.n1 - comps.n2) / (comps.n1 + comps.n2), 2);
	return (r0 + (1 - r0) * pow((1 - cos), 5));
}
