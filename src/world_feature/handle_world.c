/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:11:08 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/08 12:40:47 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_world	world(void)
{
	return ((t_world){0});
}

t_world	default_world(void)
{
	t_world	w;

	w = (t_world){0};
	w.amount_obj = 2;
	w.light = point_light(create_point(-10, 10, -10), fill_color(1, 1, 1));
	w.shapes = malloc(sizeof(t_shape) * 10);
	w.shapes[0] = new_sphere();
	w.shapes[0].sphere->material.color = fill_color(0.8, 1, 0.6);
	w.shapes[0].sphere->material.diffuse = 0.7;
	w.shapes[0].sphere->material.specular = 0.2;
	w.shapes[1] = new_sphere();
	set_transform(&w.shapes[1], scaling(0.5, 0.5, 0.5));
	return (w);
}

t_intersections	intersect_world(t_world *w, t_ray ray)
{
	int				i;
	double			abc[3];
	double			discriminat;
	t_intersections	xs;

	i = 0;
	xs = (t_intersections){0};
	abc[0] = 0;
	abc[1] = 0;
	abc[2] = 0;
	while (i < w->amount_obj)
	{
		ray = transform(ray, inverse_matrix(w->shapes[i].any->transform));
		discriminat = calculate_discriminat(abc, ray);
		if (discriminat >= 0)
		{
			intersections(&xs, \
			intersection((-abc[1] - (sqrt(discriminat))) \
			/ (2 * abc[0]), w->shapes[i], &xs), \
			intersection((-abc[1] + (sqrt(discriminat))) \
			/ (2 * abc[0]), w->shapes[i], &xs), i);
		}
		i++;
	}
	return (xs);
}

t_precomp	prepare_computations(t_intersection *i, t_ray r, \
			t_intersections *xs)
{
	t_precomp		comps;
	t_obj			res_multiply;
	t_intersection	*containers;

	comps = (t_precomp){0};
	comps.t = i->t;
	comps.shape = i->shape;
	determining_n1_and_n2(xs, i, &comps);
	comps.point = cat_position(r, comps.t);
	comps.eyev = negating_object(object_normalize(r.direction));
	comps.normalv = normal_at(comps.shape, comps.point);
	if (object_dot(comps.normalv, comps.eyev) < 0)
	{
		comps.normalv = negating_object(object_normalize(comps.normalv));
		comps.inside = 1;
	}
	comps.reflectv = reflect(r.direction, comps.normalv);
	res_multiply = create_object(comps.normalv.x, comps.normalv.y, \
	comps.normalv.z, comps.normalv.w);
	res_multiply = multiply_object(res_multiply, EPSILON);
	comps.over_point = sum_objects(comps.point, res_multiply);
	comps.under_point = subtract_objects(comps.point, res_multiply);
	return (comps);
}

t_color	shade_hit(t_world *w, t_precomp *comps, int remaining)
{
	t_lighting		lig;
	t_color			surface;
	t_color			reflected;
	t_color			refracted;
	t_material		material;

	lig = (t_lighting){0};
	lig.material = comps->shape.sphere->material;
	lig.shape = comps->shape;
	lig.light = w->light;
	lig.point = comps->point;
	lig.eyev = comps->eyev;
	lig.normalv = comps->normalv;
	lig.in_shadow = is_shadowed(w, comps->over_point);
	surface = lighting(lig);
	refracted = refracted_color(*w, *comps, remaining);
	reflected = reflected_color(*w, *comps, remaining);
	material = comps->shape.any->material;
	if (material.reflective > 0 && material.transparency > 0)
	{
		return (sum_colors(sum_colors(surface, \
			multiply_scalar_colors(reflected, schlick(*comps))), \
			multiply_scalar_colors(refracted, (1 - schlick(*comps)))));
	}
	return (sum_colors(sum_colors(surface, reflected), refracted));
}
