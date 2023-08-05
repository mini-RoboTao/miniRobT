#include "unit_test.h"

// Test(world_scene, create_a_world)
// {
// 	t_world	w;

// 	w = world();
// 	cr_assert(eq(w.shape->v, NULL));
// }

Test(world_scene, the_default_world)
{
	t_world w_exp = (t_world){0};
	t_world w_res = (t_world){0};
	w_exp.light = point_light(create_point(-10, 10, -10), fill_color(1, 1, 1));
	w_exp.shapes = malloc(sizeof(t_sphere) * 2);
	w_exp.shapes[0] = new_sphere();
	w_exp.shapes[0].sphere->material.color = fill_color(0.8, 1, 0.6);
	w_exp.shapes[0].sphere->material.diffuse = 0.7;
	w_exp.shapes[0].sphere->material.specular = 0.2;
	w_exp.shapes[1] = new_sphere();
	set_transform(&w_exp.shapes[1], scaling(0.5, 0.5, 0.5));

	w_res = default_world();
	cr_assert(cr_sphere_check_material_eq(w_res.shapes[0].v, w_exp.shapes[0].v));
	cr_assert(cr_sphere_check_material_eq(w_res.shapes[1].v, w_exp.shapes[1].v));
	cr_assert(cr_light_eq(w_res.light, w_exp.light));
	clean_world(w_res);
	clean_world(w_exp);
}

Test(world_scene, Intersect_a_world_with_a_ray)
{
	t_world			w 	= default_world();
	t_ray			r	= create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	t_intersections	xs	= intersect_world(&w, r);
	cr_assert(epsilon_eq(flt, xs.amount, 4, EPSILON));
	cr_assert(epsilon_eq(flt, xs.i->t, 4, EPSILON));
	cr_assert(epsilon_eq(flt, xs.i->next->t, 4.5, EPSILON));
	cr_assert(epsilon_eq(flt, xs.i->next->next->t, 5.5, EPSILON));
	cr_assert(epsilon_eq(flt, xs.i->next->next->next->t, 6, EPSILON));
	clean_intersection_lst(&xs.i);
	clean_world(w);
}

Test(world_scene, precomputing_the_state_of_an_intersection)
{
	t_ray			r = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	t_shape			shape = new_sphere();
	t_intersection	*i = intersection(4, shape);
	t_precomp		comps = prepare_computations(i, r);

	cr_assert(epsilon_eq(flt, comps.t, i->t, EPSILON));
	cr_assert(cr_sphere_eq(comps.shape.sphere, i->shape.sphere));
	cr_assert(cr_object_eq(comps.point, (t_obj){0, 0, -1, 1}));
	cr_assert(cr_object_eq(comps.eyev, (t_obj){0, 0, -1, 0}));
	cr_assert(cr_object_eq(comps.normalv, (t_obj){0, 0, -1, 0}));
	clean_intersection_lst(&i);
	clean_shape(&shape);
}

Test(world_scene, the_hit_when_an_intersection_occurs_on_the_outside)
{
	t_ray			r = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	t_shape			shape = new_sphere();
	t_intersection	*i = intersection(4, shape);
	t_precomp		comps = prepare_computations(i, r);
	cr_assert(eq(comps.inside, 0));
	clean_intersection_lst(&i);
	clean_shape(&shape);
}

Test(world_scene, the_hit_when_an_intersection_occurs_on_the_inside)
{
	t_ray			r = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	t_shape			shape = new_sphere();
	t_intersection	*i = intersection(1, shape);
	t_precomp		comps = prepare_computations(i, r);
	cr_assert(eq(comps.inside, 1));
	cr_assert(cr_object_eq(comps.point, (t_obj){0, 0, 1, 1}));
	cr_assert(cr_object_eq(comps.eyev, (t_obj){0, 0, -1, 0}));
	cr_assert(cr_object_eq(comps.normalv, (t_obj){0, 0, -1, 0}));
	clean_intersection_lst(&i);
	clean_shape(&shape);
}

Test(world_scene, shading_an_intersection)
{
	t_world			w = default_world();
	t_ray			r = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	t_shape			shape = w.shapes[0];
	t_intersection	*i = intersection(4, shape);
	t_precomp		comps = prepare_computations(i, r);
	t_color c = shade_hit(&w, &comps);
	cr_assert(cr_color_eq(c, (t_color){0.38066, 0.47583, 0.2855}));
	clean_intersection_lst(&i);
	clean_world(w);
}

Test(world_scene, shading_an_intersection_from_the_inside)
{
	t_world			w = default_world();
	w.light	= point_light(create_point(0, 0.25, 0), fill_color(1, 1, 1));
	t_ray			r = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	t_shape			shape = w.shapes[1];
	t_intersection	*i = intersection(0.5, shape);
	t_precomp		comps = prepare_computations(i, r);
	t_color c = shade_hit(&w, &comps);
	cr_assert(cr_color_eq(c, (t_color){0.90498, 0.90498, 0.90498}));
	clean_intersection_lst(&i);
	clean_world(w);
}

Test(Supporting_multiple_light, the_color_when_a_ray_misses)
{
	t_world			w = default_world();
	t_ray			r = create_ray(create_point(0, 0, -5), create_vector(0, 1, 0));
	t_color			c = color_at(&w, r);
	cr_assert(cr_color_eq(c, fill_color(0, 0, 0)));
	clean_world(w);
}

Test(Supporting_multiple_light, the_color_when_a_ray_hits)
{
	t_world			w = default_world();
	t_ray			r = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	t_color			c = color_at(&w, r);
	cr_assert(cr_color_eq(c, fill_color(0.38066, 0.47583, 0.2855)));
	clean_world(w);
}

Test(Supporting_multiple_light, the_color_with_an_intersection_behind_the_ray)
{
	t_world			w = default_world();
	w.shapes[0].sphere->material.ambient = 1;
	w.shapes[1].sphere->material.ambient = 1;
	t_ray			r = create_ray(create_point(0, 0, 0.75), create_vector(0, 0, -1));
	t_color			c = color_at(&w, r);
	cr_assert(cr_color_eq(c, w.shapes[1].sphere->material.color));
	clean_world(w);
}
