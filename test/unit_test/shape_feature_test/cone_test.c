#include "unit_test.h"

Test(Intersecting_a_cone_with_a_ray, On_x_0_y_0_z_minus_5)
{
	t_shape	cone	= new_cone();
	t_obj	direction = object_normalize(create_vector(0, 0, 1));
	t_ray	ray = create_ray(create_point(0, 0, -5), direction);

	t_intersections	xs = (t_intersections){0};

	intersect_cone_caps(&xs, cone, ray);

	cr_expect(eq(xs.amount, 2));
	cr_expect(epsilon_eq(flt, xs.i->t, 5, EPSILON));
	cr_expect(epsilon_eq(flt, xs.i->next->t, 5, EPSILON));

	clean_shape(&cone);
	clean_intersection_lst(&xs.i);
}

Test(Intersecting_a_cone_with_a_ray, On_x_0_y_0_z_minus_5_vector_1)
{
	t_shape	cone	= new_cone();
	t_obj	direction = object_normalize(create_vector(1, 1, 1));
	t_ray	ray = create_ray(create_point(0, 0, -5), direction);

	t_intersections	xs = (t_intersections){0};

	intersect_cone_caps(&xs, cone, ray);

	cr_expect(eq(xs.amount, 2));
	cr_expect(epsilon_eq(flt, xs.i->t, 8.66025, EPSILON));
	cr_expect(epsilon_eq(flt, xs.i->next->t, 8.66025, EPSILON));

	clean_shape(&cone);
	clean_intersection_lst(&xs.i);
}

Test(Intersecting_a_cone_with_a_ray, On_x_1_y_1_z_minus_5)
{
	t_shape	cone	= new_cone();
	t_obj	direction = object_normalize(create_vector(-0.5, -1, 1));
	t_ray	ray = create_ray(create_point(1, 1, -5), direction);

	t_intersections	xs = (t_intersections){0};

	intersect_cone_caps(&xs, cone, ray);

	cr_expect(eq(xs.amount, 2));
	cr_expect(epsilon_eq(flt, xs.i->t, 4.55006, EPSILON));
	cr_expect(epsilon_eq(flt, xs.i->next->t, 49.44994, EPSILON));

	clean_shape(&cone);
	clean_intersection_lst(&xs.i);
}

Test(Cone, Intersecting_a_cone_with_a_ray_parallel_to_one_of_its_halves)
{
	t_shape	cone	= new_cone();
	t_obj	direction = object_normalize(create_vector(0, 1, 1));
	t_ray	ray = create_ray(create_point(0, 0, -1), direction);

	t_intersections	xs = (t_intersections){0};

	intersect_cone_caps(&xs, cone, ray);

	cr_expect(eq(xs.amount, 1));
	cr_expect(epsilon_eq(flt, xs.i->t, 0.35355, EPSILON));

	clean_shape(&cone);
	clean_intersection_lst(&xs.i);
}

Test(Intersecting_a_cone_end_caps, On_x_0_y_0_z_minus_5_vector_0_1_0)
{
	t_shape	cone	= new_cone();
	t_obj	direction = object_normalize(create_vector(0, 1, 0));
	t_ray	ray = create_ray(create_point(0, 0, -5), direction);

	t_intersections	xs = (t_intersections){0};

	cone.cone->minimum = -0.5;
	cone.cone->maximum = 0.5;
	cone.cone->closed = true;
	intersect_cone_caps(&xs, cone, ray);

	cr_expect(eq(xs.amount, 0));

	clean_shape(&cone);
	clean_intersection_lst(&xs.i);
}

Test(Intersecting_a_cone_end_caps, On_x_0_y_0_z_minus_0_dot_25_vector_0_1_1)
{
	t_shape	cone	= new_cone();
	t_obj	direction = object_normalize(create_vector(0, 1, 1));
	t_ray	ray = create_ray(create_point(0, 0, -0.25), direction);

	t_intersections	xs = (t_intersections){0};

	cone.cone->minimum = -0.5;
	cone.cone->maximum = 0.5;
	cone.cone->closed = true;
	intersect_cone_caps(&xs, cone, ray);

	cr_expect(eq(xs.amount, 2));

	clean_shape(&cone);
	clean_intersection_lst(&xs.i);
}

Test(Intersecting_a_cone_end_caps, On_x_0_y_0_z_minus_0_dot_25_vector_0_1_0)
{
	t_shape	cone	= new_cone();
	t_obj	direction = object_normalize(create_vector(0, 1, 0));
	t_ray	ray = create_ray(create_point(0, 0, -0.25), direction);

	t_intersections	xs = (t_intersections){0};

	cone.cone->minimum = -0.5;
	cone.cone->maximum = 0.5;
	cone.cone->closed = true;
	intersect_cone_caps(&xs, cone, ray);

	cr_expect(eq(xs.amount, 4));

	clean_shape(&cone);
	clean_intersection_lst(&xs.i);
}

Test(Computing_the_normal_vector_on_a_cone, On_x_0_y_0_z_0)
{
	t_shape	cone = new_cone();
	t_obj	normal = normal_at_cone(cone, create_point(0, 0, 0));

	cr_assert(cr_object_eq(normal, create_vector(0, 0, 0)));

	clean_shape(&cone);
}

Test(Computing_the_normal_vector_on_a_cone, On_x_1_y_1_z_1)
{
	t_shape	cone = new_cone();
	t_obj	normal = normal_at_cone(cone, create_point(1, 1, 1));

	cr_assert(cr_object_eq(normal, create_vector(1, -sqrt(2), 1)));

	clean_shape(&cone);
}

Test(Computing_the_normal_vector_on_a_cone, On_x_minus_1_y_minus_1_z_0)
{
	t_shape	cone = new_cone();
	t_obj	normal = normal_at_cone(cone, create_point(-1, -1, 0));

	cr_assert(cr_object_eq(normal, create_vector(-1, 1, 0)));

	clean_shape(&cone);
}
