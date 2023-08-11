#include "unit_test.h"

Test(reflection, reflectivity_for_the_default_material)
{
	t_material	m = new_material();
	cr_assert(epsilon_eq(flt, m.reflective, 0.0, EPSILON));
}

Test(reflection, precomputing_the_reflection_vector)
{
	t_shape			plane = new_plane();
	t_ray			ray = create_ray(create_point(0, 1, -1), create_vector(0, -((sqrt(2)) / 2), (sqrt(2)) / 2));
	t_intersection	*i = intersection(sqrt(2), plane, XS_CONST);
	t_precomp		comp = prepare_computations(i, ray, XS_CONST);
	cr_assert(cr_object_eq(comp.reflectv, create_vector(0, (sqrt(2))/2, (sqrt(2))/2)));
	clean_intersection_lst(&i);
	clean_shape(&plane);
}

Test(reflection, the_reflected_color_for_a_nonreflective_material)
{
	t_world			w = default_world();
	t_ray			ray = create_ray(create_point(0, 0, 0), create_vector(0, 0, 1));
	t_shape			shape = w.lst->shape;
	shape.any->material.ambient = 1;
	t_intersection	*i = intersection(1, shape, XS_CONST);
	t_precomp		comps = prepare_computations(i, ray, XS_CONST);
	t_color			color = reflected_color(w, comps, 1);
	cr_assert(cr_color_eq(color, fill_color(0, 0, 0)));
	clean_intersection_lst(&i);
	clean_world(w);
}

Test(reflection, the_reflected_color_for_a_reflective_material)
{
	t_world			w = default_world();
	t_shape			shape = new_plane();
	set_transform(&shape, translation(0, -1, 0));
	shape.any->material.reflective = 0.5;
	ft_lstadd_back(&w.lst, ft_lstnew(shape));
	t_ray			ray = create_ray(create_point(0, 0, -3), create_vector(0, (sqrt(2))/2, (sqrt(2))/2));
	t_intersection	*i = intersection(sqrt(2), shape, XS_CONST);
	t_precomp		comps = prepare_computations(i, ray, XS_CONST);

	t_color			color = reflected_color(w, comps, 1);

	cr_assert(cr_color_eq(color, fill_color(0.19032, 0.2379, 0.14274)));
	clean_world(w);
	clean_intersection_lst(&i);
}

Test(reflection, shade_hit_with_a_reflective_material)
{
	t_world			w = default_world();
	t_shape			shape = new_plane();
	shape.any->material.reflective = 0.5;
	set_transform(&shape, translation(0, -1, 0));
	ft_lstadd_back(&w.lst, ft_lstnew(shape));
	t_ray			ray = create_ray(create_point(0, 0, -3), create_vector(0, -(sqrt(2))/2, (sqrt(2))/2));
	t_intersection	*i = intersection(sqrt(2), shape, XS_CONST);
	t_precomp		comps = prepare_computations(i, ray, XS_CONST);

	t_color			color = shade_hit(&w, &comps, 1);
	cr_assert(cr_color_eq(color, fill_color(0.87677, 0.92436, 0.82918)));
	clean_intersection_lst(&i);
	clean_world(w);
}

Test(reflection, color_at_with_mutually_reflective_surfaces)
{
	t_world			w = world();
	w.light = point_light(create_point(0, 0, 0), fill_color(1, 1, 1));
	ft_lstadd_back(&w.lst, ft_lstnew(new_plane()));
	w.lst->shape.any->material.reflective = 1;
	set_transform(&w.lst->shape, translation(0, -1, 0));
	ft_lstadd_back(&w.lst, ft_lstnew(new_plane()));
	w.lst->next->shape.any->material.reflective = 1;
	set_transform(&w.lst->next->shape, translation(0, 1, 0));

	t_ray			ray = create_ray(create_point(0, 0, 0), create_vector(0, 1, 0));
	color_at(&w, ray, 1);
	clean_world(w);
}

Test(reflection, the_reflected_color_at_the_maximum_recursive_depth)
{
	t_world			w = default_world();
	t_shape			shape = new_plane();
	shape.any->material.reflective = 0.5;
	set_transform(&shape, translation(0, -1, 0));
	ft_lstadd_back(&w.lst, ft_lstnew(shape));
	t_ray			ray = create_ray(create_point(0, 0, -3), create_vector(0, -(sqrt(2))/2, (sqrt(2))/2));
	t_intersection	*i = intersection(sqrt(2), shape, XS_CONST);
	t_precomp		comps = prepare_computations(i, ray, XS_CONST);

	t_color			color = reflected_color( w, comps, 0);
	cr_assert(cr_color_eq(color, fill_color(0, 0, 0)));
	clean_intersection_lst(&i);
	clean_world(w);
}
