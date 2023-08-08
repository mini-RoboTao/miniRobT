#include "unit_test.h"

Test(transparency_and_refraction, transparency_and_refractive_index_for_the_default_material)
{
	t_material	m = new_material();
	cr_assert(epsilon_eq(flt, m.transparency, 0.0, EPSILON));
	cr_assert(epsilon_eq(flt, m.refractive_index, 1.0, EPSILON));
}

Test(transparency_and_refraction, a_helper_for_producing_a_sphere_with_a_glassy_material)
{
	t_shape		shape = glass_sphere();
	cr_assert(cr_matrix_eq(shape.sphere->transform, create_identity_matrix()));
	cr_assert(epsilon_eq(flt, shape.sphere->material.transparency, 1.0, EPSILON));
	cr_assert(epsilon_eq(flt, shape.sphere->material.refractive_index, 1.5, EPSILON));
	clean_shape(&shape);
}

typedef struct s_n
{
	double		n1;
	double		n2;
}				t_ns;

t_ns	expected_ns[6] = (t_ns[6]){
								{.n1 = 1.0, .n2 = 1.5},
								{.n1 = 1.5, .n2 = 2.0},
								{.n1 = 2.0, .n2 = 2.5},
								{.n1 = 2.5, .n2 = 2.5},
								{.n1 = 2.5, .n2 = 1.5},
								{.n1 = 1.5, .n2 = 1.0},
};

Test(transparency_and_refraction, finding_n1_and_n2_at_various_intersections)
{
	int				i = 0;
	t_precomp		comps;
	t_shape			A = glass_sphere();
	t_shape			B = glass_sphere();
	t_shape			C = glass_sphere();
	t_ray			ray = create_ray(create_point(0, 0, -4), create_vector(0, 0, 1));
	t_intersections	xs = (t_intersections){0};
	set_transform(&A, scaling(2, 2, 2));
	A.sphere->material.refractive_index = 1.5;
	set_transform(&B, translation(0, 0, -0.25));
	B.sphere->material.refractive_index = 2.0;
	set_transform(&C, translation(0, 0, 0.25));
	C.sphere->material.refractive_index = 2.5;

	intersections(&xs, intersection(2, A, &xs), intersection(2.75, B, &xs), 0);
	intersections(&xs, intersection(3.25, C, &xs), intersection(4.75, B, &xs), 0);
	intersections(&xs, intersection(5.25, C, &xs), intersection(6, A, &xs), 0);

	t_intersections list = xs;
	while (xs.i && i < 6)
	{
		comps = prepare_computations(xs.i, ray, &list);
		cr_assert(epsilon_eq(flt, comps.n1, expected_ns[i].n1, EPSILON));
		cr_assert(epsilon_eq(flt, comps.n2, expected_ns[i].n2, EPSILON));
		comps = (t_precomp){0};
		xs.i = xs.i->next;
		i++;
	}

	clean_intersection_lst(&list.i);
	clean_shape(&A);
	clean_shape(&B);
	clean_shape(&C);
}

Test(transparency_and_refraction, the_under_is_offset_below_the_surface)
{
	t_intersections	xs = (t_intersections){0};
	t_ray			ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	t_shape			shape = glass_sphere();
	set_transform(&shape, translation(0, 0, 1));
	t_intersection	*i = intersection(5, shape, &xs);
	intersections(&xs, i, NULL, 0);

	t_precomp		comps = prepare_computations(i, ray, &xs);
	cr_assert(gt(comps.under_point.z, EPSILON / 2));
	cr_assert(lt(comps.point.z, comps.under_point.z));
	clean_intersection_lst(&i);
	clean_shape(&shape);
}

Test(transparency_and_refraction, the_refracted_color_with_an_opaque_surface)
{
	t_world			w = default_world();
	t_shape			shape = w.shapes[0];
	t_ray			ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	t_intersections	xs = (t_intersections){0};
	intersections(&xs, intersection(4, shape, &xs), intersection(6, shape, &xs), 0);
	t_precomp		comps = prepare_computations(xs.i, ray, &xs);
	t_color			color = refracted_color(w, comps, 5);
	cr_assert(cr_color_eq(color, fill_color(0, 0, 0)));
	clean_intersection_lst(&xs.i);
	clean_world(w);
}

Test(transparency_and_refraction, the_refracted_color_at_the_maximum_recursive_depth)
{
	t_world			w = default_world();
	t_shape			shape = w.shapes[0];
	shape.any->material.transparency = 1.0;
	shape.any->material.refractive_index = 1.5;
	t_ray			ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	t_intersections	xs = (t_intersections){0};
	intersections(&xs, intersection(4, shape, &xs), intersection(6, shape, &xs), 0);
	t_precomp		comps = prepare_computations(xs.i, ray, &xs);
	t_color			color = refracted_color(w, comps, 0);
	cr_assert(cr_color_eq(color, fill_color(0, 0, 0)));
	clean_intersection_lst(&xs.i);
	clean_world(w);
}

Test(transparency_and_refraction, the_refracted_color_under_total_internal_reflection)
{
	t_world			w = default_world();
	t_shape			shape = w.shapes[0];
	shape.any->material.transparency = 1.0;
	shape.any->material.refractive_index = 1.5;
	t_ray			ray = create_ray(create_point(0, 0, (sqrt(2))/2), create_vector(0, 1, 0));
	t_intersections	xs = (t_intersections){0};
	intersections(&xs, intersection(-((sqrt(2))/2), shape, &xs), intersection((sqrt(2))/2, shape, &xs), 0);
	t_precomp		comps = prepare_computations(xs.i->next, ray, &xs);
	t_color			color = refracted_color(w, comps, 5);
	cr_assert(cr_color_eq(color, fill_color(0, 0, 0)));
	clean_intersection_lst(&xs.i);
	clean_world(w);
}

Test(transparency_and_refraction, the_refracted_color_with_a_refracted_ray)
{
	t_world			w = default_world();
	t_shape			A = w.shapes[0];
	A.any->material.ambient = 1.0;
	A.any->material.pattern = test_pattern();
	A.any->material.pattern.validate = true;
	t_shape			B = w.shapes[1];
	B.any->material.transparency = 1.0;
	B.any->material.refractive_index = 1.5;
	t_ray			ray = create_ray(create_point(0, 0, 0.1), create_vector(0, 1, 0));
	t_intersections	xs = (t_intersections){0};
	intersections(&xs, intersection(-0.9899, A, &xs), intersection(-0.4899, B, &xs), 0);
	intersections(&xs, intersection(0.4899, B, &xs), intersection(0.9899, A, &xs), 0);
	t_precomp		comps = prepare_computations(xs.i->next->next, ray, &xs);
	t_color			color = refracted_color(w, comps, 5);
	cr_assert(cr_color_eq(color, fill_color(0, 0.99888, 0.04725)));
	clean_intersection_lst(&xs.i);
	clean_world(w);
}

// Test(transparency_and_refraction, shade_hit_with_a_transparent_material)
// {
// 	t_world			w = default_world();
// 	w.amount_obj = 4;
// 	t_shape			floor = new_plane();
// 	set_transform(&floor, translation(0, -1, 0));
// 	floor.any->material.transparency = 0.5;
// 	floor.any->material.refractive_index = 1.5;
// 	w.shapes[2] = floor;
// 	t_shape			ball = new_sphere();
// 	ball.any->material.color = fill_color(1, 0, 0);
// 	ball.any->material.ambient = 0.5;
// 	set_transform(&ball, translation(0, -3.5, -0.5));
// 	w.shapes[3] = ball;
// 	t_ray			ray = create_ray(create_point(0, 0, -3), create_vector(0, -(sqrt(2))/2, (sqrt(2))/2));
// 	t_intersections	xs = (t_intersections){0};
// 	intersections(&xs, intersection(sqrt(2), floor, &xs), NULL, 0);
// 	t_precomp		comps = prepare_computations(xs.i, ray, &xs);
// 	t_color			color = shade_hit(&w, &comps, 5);
// 	printf("AQUI ESTAMOS\n");
// 	printf("%lf\t%lf\t%lf\n", color.red, color.green, color.blue);
// 	cr_assert(cr_color_eq(color, fill_color(0.93642, 0.68642, 0.68642)));
// 	clean_intersection_lst(&xs.i);
// 	clean_world(w);
// }

Test(transparency_and_refraction, the_schlick_approximation_under_total_internal_reflection)
{
	t_shape			shape = glass_sphere();
	t_ray			ray = create_ray(create_point(0, 0, sqrt(2)/2), create_vector(0, 1, 0));
	t_intersections	xs = (t_intersections){0};
	intersections(&xs, intersection(-sqrt(2)/2, shape, &xs), intersection(sqrt(2)/2, shape, &xs), 0);
	t_precomp		comps = prepare_computations(xs.i->next, ray, &xs);
	double			reflectance = schlick(comps);
	cr_assert(epsilon_eq(flt, reflectance, 1.0, EPSILON));
	clean_intersection_lst(&xs.i);
	clean_shape(&shape);
}

Test(transparency_and_refraction, the_schlick_approximation_with_a_perpendicular_viewwing_angle)
{
	t_shape			shape = glass_sphere();
	t_ray			ray = create_ray(create_point(0, 0, 0), create_vector(0, 1, 0));
	t_intersections	xs = (t_intersections){0};
	intersections(&xs, intersection(-1, shape, &xs), intersection(1, shape, &xs), 0);
	t_precomp		comps = prepare_computations(xs.i->next, ray, &xs);
	double			reflectance = schlick(comps);
	cr_assert(epsilon_eq(flt, reflectance, 0.04, EPSILON));
	clean_intersection_lst(&xs.i);
	clean_shape(&shape);
}

Test(transparency_and_refraction, the_schlick_approximation_with_small_angle_and_n2_bigger_them_n1)
{
	t_shape			shape = glass_sphere();
	t_ray			ray = create_ray(create_point(0, 0.99, -2), create_vector(0, 0, 1));
	t_intersections	xs = (t_intersections){0};
	intersections(&xs, intersection(1.8589, shape, &xs), NULL, 0);
	t_precomp		comps = prepare_computations(xs.i, ray, &xs);
	double			reflectance = schlick(comps);
	cr_assert(epsilon_eq(flt, reflectance, 0.48873, EPSILON));
	clean_intersection_lst(&xs.i);
	clean_shape(&shape);
}

// Test(transparency_and_refraction, shade_hit_with_a_reflective_transparent_material)
// {
// 	t_world			w = default_world();
// 	w.amount_obj = 4;
// 	t_ray			ray = create_ray(create_point(0, 0, -3), create_vector(0, -(sqrt(2))/2, (sqrt(2))/2));
// 	t_shape			floor = new_plane();
// 	set_transform(&floor, translation(0, -1, 0));
// 	floor.any->material.transparency = 0.5;
// 	floor.any->material.reflective = 0.5;
// 	floor.any->material.refractive_index = 1.5;
// 	w.shapes[2] = floor;
// 	t_shape			ball = new_sphere();
// 	ball.any->material.color = fill_color(1, 0, 0);
// 	ball.any->material.ambient = 0.5;
// 	set_transform(&ball, translation(0, -3.5, -0.5));
// 	w.shapes[3] = ball;
// 	t_intersections	xs = (t_intersections){0};
// 	intersections(&xs, intersection(sqrt(2), floor, &xs), NULL, 0);
// 	t_precomp		comps = prepare_computations(xs.i, ray, &xs);
// 	t_color			color = shade_hit(&w, &comps, 5);
// 	printf("AQUI ESTAMOS\n");
// 	printf("%lf\t%lf\t%lf\n", color.red, color.green, color.blue);
// 	cr_assert(cr_color_eq(color, fill_color(0.93391, 0.69643, 0.69243)));
// 	clean_intersection_lst(&xs.i);
// 	clean_world(w);
// }
