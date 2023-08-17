#include "unit_test.h"

Test(Normal_vector_on_a_cylinder, Point_x_1_y_0_z_0)
{
	t_shape	cylinder = new_cylinder();
	t_obj	point = create_point(1, 0, 0);
	t_obj	normal = normal_at_cylinder(cylinder, point);

	cr_assert(cr_object_eq(normal, create_vector(1, 0, 0)));

	clean_shape(&cylinder);
}

Test(Normal_vector_on_a_cylinder, Point_x_0_y_5_z_minus_1)
{
	t_shape	cylinder = new_cylinder();
	t_obj	point = create_point(0, 5, -1);
	t_obj	normal = normal_at_cylinder(cylinder, point);

	cr_assert(cr_object_eq(normal, create_vector(0, 0, -1)));

	clean_shape(&cylinder);
}

Test(Normal_vector_on_a_cylinder, Point_x_0_y_minus_2_z_1)
{
	t_shape	cylinder = new_cylinder();
	t_obj	point = create_point(0, -2, 1);
	t_obj	normal = normal_at_cylinder(cylinder, point);

	cr_assert(cr_object_eq(normal, create_vector(0, 0, 1)));

	clean_shape(&cylinder);
}

Test(Normal_vector_on_a_cylinder, Point_x_minus_1_y_1_z_0)
{
	t_shape	cylinder = new_cylinder();
	t_obj	point = create_point(-1, 1, 0);
	t_obj	normal = normal_at_cylinder(cylinder, point);

	cr_assert(cr_object_eq(normal, create_vector(-1, 0, 0)));

	clean_shape(&cylinder);
}

Test(A_ray_misses_a_cylinder, On_x_1_y_0_z_0)
{
	t_shape			cylinder = new_cylinder();
	t_obj			direction = object_normalize(create_vector(0, 1, 0));
	t_ray			ray = create_ray(create_point(1, 0, 0), direction);
	t_intersections xs = (t_intersections){0};

	intersect_caps(&xs, cylinder, ray);
	cr_assert(eq(xs.amount, 0));

	clean_shape(&cylinder);
	clean_intersection_lst(&xs.i);
}

Test(A_ray_misses_a_cylinder, On_x_0_y_0_z_0)
{
	t_shape			cylinder = new_cylinder();
	t_obj			direction = object_normalize(create_vector(0, 1, 0));
	t_ray			ray = create_ray(create_point(0, 0, 0), direction);
	t_intersections xs = (t_intersections){0};

	intersect_caps(&xs, cylinder, ray);
	cr_assert(eq(xs.amount, 0));

	clean_shape(&cylinder);
	clean_intersection_lst(&xs.i);
}

Test(A_ray_misses_a_cylinder, On_x_0_y_0_z_minus_5)
{
	t_shape			cylinder = new_cylinder();
	t_obj			direction = object_normalize(create_vector(1, 1, 1));
	t_ray			ray = create_ray(create_point(0, 0, -5), direction);
	t_intersections xs = (t_intersections){0};

	intersect_caps(&xs, cylinder, ray);
	cr_assert(eq(xs.amount, 0));

	clean_shape(&cylinder);
	clean_intersection_lst(&xs.i);
}

Test(A_ray_strikes_a_cylinder, On_x_1_y_0_z_minus_5)
{
	t_shape			cylinder = new_cylinder();
	t_obj			direction = object_normalize(create_vector(0, 0, 1));
	t_ray			ray = create_ray(create_point(1, 0, -5), direction);
	t_intersections xs = (t_intersections){0};

	intersect_caps(&xs, cylinder, ray);
	cr_expect(eq(xs.amount, 2));
	cr_expect(epsilon_eq(flt, xs.i->t, 5, EPSILON));
	cr_expect(epsilon_eq(flt, xs.i->next->t, 5, EPSILON));

	clean_shape(&cylinder);
	clean_intersection_lst(&xs.i);
}

Test(A_ray_strikes_a_cylinder, On_x_0_y_0_z_minus_5)
{
	t_shape			cylinder = new_cylinder();
	t_obj			direction = object_normalize(create_vector(0, 0, 1));
	t_ray			ray = create_ray(create_point(0, 0, -5), direction);
	t_intersections xs = (t_intersections){0};

	intersect_caps(&xs, cylinder, ray);
	cr_expect(eq(xs.amount, 2));
	cr_expect(epsilon_eq(flt, xs.i->t, 4, EPSILON));
	cr_expect(epsilon_eq(flt, xs.i->next->t, 6, EPSILON));

	clean_shape(&cylinder);
	clean_intersection_lst(&xs.i);
}

Test(A_ray_strikes_a_cylinder, On_x_0_dot_5_y_0_z_minus_5)
{
	t_shape			cylinder = new_cylinder();
	t_obj			direction = object_normalize(create_vector(0.1, 1, 1));
	t_ray			ray = create_ray(create_point(0.5, 0, -5), direction);
	t_intersections xs = (t_intersections){0};

	intersect_caps(&xs, cylinder, ray);
	cr_expect(eq(xs.amount, 2));
	cr_expect(epsilon_eq(flt, xs.i->t, 6.80798, EPSILON));
	cr_expect(epsilon_eq(flt, xs.i->next->t, 7.08872, EPSILON));

	clean_shape(&cylinder);
	clean_intersection_lst(&xs.i);
}

Test(Cylinder, The_default_minimum_and_maximum_for_a_cylinder)
{
	t_shape	cylinder = new_cylinder();

	cr_expect(eq(cylinder.any->minimum, -INFINITY));
	cr_expect(eq(cylinder.any->maximum, INFINITY));

	clean_shape(&cylinder);
}

Test(Intersecting_a_constrained_cylinder, On_x_0_y_1_dot_5_z_0)
{
	t_shape			cylinder = new_cylinder();
	t_obj			direction = object_normalize(create_vector(0.1, 1, 0));
	t_ray			ray = create_ray(create_point(0, 1.5, 0), direction);
	t_intersections xs = (t_intersections){0};

	cylinder.any->minimum = 1;
	cylinder.any->maximum = 2;
	cylinder.any->closed = false;

	intersect_caps(&xs, cylinder, ray);
	cr_expect(eq(xs.amount, 0));

	clean_shape(&cylinder);
	clean_intersection_lst(&xs.i);
}

Test(Intersecting_a_constrained_cylinder, On_x_0_y_3_z_minus_5)
{
	t_shape			cylinder = new_cylinder();
	t_obj			direction = object_normalize(create_vector(0, 0, 1));
	t_ray			ray = create_ray(create_point(0, 3, -5), direction);
	t_intersections xs = (t_intersections){0};

	cylinder.any->minimum = 1;
	cylinder.any->maximum = 2;

	intersect_caps(&xs, cylinder, ray);
	cr_expect(eq(xs.amount, 0));

	clean_shape(&cylinder);
	clean_intersection_lst(&xs.i);
}

Test(Intersecting_a_constrained_cylinder, On_x_0_y_0_z_minus_5)
{
	t_shape			cylinder = new_cylinder();
	t_obj			direction = object_normalize(create_vector(0, 0, 1));
	t_ray			ray = create_ray(create_point(0, 0, -5), direction);
	t_intersections xs = (t_intersections){0};

	cylinder.any->minimum = 1;
	cylinder.any->maximum = 2;

	intersect_caps(&xs, cylinder, ray);
	cr_expect(eq(xs.amount, 0));

	clean_shape(&cylinder);
	clean_intersection_lst(&xs.i);
}

Test(Intersecting_a_constrained_cylinder, On_x_0_y_2_z_minus_5)
{
	t_shape			cylinder = new_cylinder();
	t_obj			direction = object_normalize(create_vector(0, 0, 1));
	t_ray			ray = create_ray(create_point(0, 2, -5), direction);
	t_intersections xs = (t_intersections){0};

	cylinder.any->minimum = 1;
	cylinder.any->maximum = 2;

	intersect_caps(&xs, cylinder, ray);
	cr_expect(eq(xs.amount, 0));

	clean_shape(&cylinder);
	clean_intersection_lst(&xs.i);
}

Test(Intersecting_a_constrained_cylinder, On_x_0_y_1_z_minus_5)
{
	t_shape			cylinder = new_cylinder();
	t_obj			direction = object_normalize(create_vector(0, 0, 1));
	t_ray			ray = create_ray(create_point(0, 1, -5), direction);
	t_intersections xs = (t_intersections){0};

	cylinder.any->minimum = 1;
	cylinder.any->maximum = 2;

	intersect_caps(&xs, cylinder, ray);
	cr_expect(eq(xs.amount, 0));

	clean_shape(&cylinder);
	clean_intersection_lst(&xs.i);
}

Test(Intersecting_a_constrained_cylinder, On_x_0_y_1_dot_5_z_minus_2)
{
	t_shape			cylinder = new_cylinder();
	t_obj			direction = object_normalize(create_vector(0, 0, 1));
	t_ray			ray = create_ray(create_point(0, 1.5, -2), direction);
	t_intersections xs = (t_intersections){0};

	cylinder.any->minimum = 1;
	cylinder.any->maximum = 2;

	intersect_caps(&xs, cylinder, ray);
	cr_expect(eq(xs.amount, 2));

	clean_shape(&cylinder);
	clean_intersection_lst(&xs.i);
}

Test(Cylinder, The_default_closed_value_for_a_cylinder)
{
	t_shape	cylinder = new_cylinder();
	cylinder.any->closed = false;
	cr_assert(eq(cylinder.any->closed, F));

	clean_shape(&cylinder);
}

Test(Intersectiong_the_caps_of_a_closed_cylinder, On_x_0_y_3_z_0)
{
	t_shape	cylinder = new_cylinder();

	cylinder.any->minimum = 1;
	cylinder.any->maximum = 2;
	cylinder.any->closed = true;

	t_obj			direction = object_normalize(create_vector(0, -1, 0));
	t_ray			ray = create_ray(create_point(0, 3, 0), direction);
	t_intersections xs = (t_intersections){0};


	intersect_caps(&xs, cylinder, ray);
	cr_expect(eq(xs.amount, 2));

	clean_shape(&cylinder);
	clean_intersection_lst(&xs.i);
}

Test(Intersectiong_the_caps_of_a_closed_cylinder, On_x_0_y_3_z_minus_2)
{
	t_shape	cylinder = new_cylinder();

	cylinder.any->minimum = 1;
	cylinder.any->maximum = 2;
	cylinder.any->closed = true;

	t_obj			direction = object_normalize(create_vector(0, -1, 2));
	t_ray			ray = create_ray(create_point(0, 3, -2), direction);
	t_intersections xs = (t_intersections){0};

	intersect_caps(&xs, cylinder, ray);
	cr_expect(eq(xs.amount, 2));

	clean_shape(&cylinder);
	clean_intersection_lst(&xs.i);
}

Test(Intersectiong_the_caps_of_a_closed_cylinder, On_x_0_y_4_z_minus_2)
{
	t_shape	cylinder = new_cylinder();

	cylinder.any->minimum = 1;
	cylinder.any->maximum = 2;
	cylinder.any->closed = true;

	t_obj			direction = object_normalize(create_vector(0, -1, 1));
	t_ray			ray = create_ray(create_point(0, 4, -2), direction);
	t_intersections xs = (t_intersections){0};

	intersect_caps(&xs, cylinder, ray);
	cr_expect(eq(xs.amount, 2));

	clean_shape(&cylinder);
	clean_intersection_lst(&xs.i);
}

Test(Intersectiong_the_caps_of_a_closed_cylinder, On_x_0_y_0_z_minus_2)
{
	t_shape	cylinder = new_cylinder();

	cylinder.any->minimum = 1;
	cylinder.any->maximum = 2;
	cylinder.any->closed = true;

	t_obj			direction = object_normalize(create_vector(0, 1, 2));
	t_ray			ray = create_ray(create_point(0, 0, -2), direction);
	t_intersections xs = (t_intersections){0};

	intersect_caps(&xs, cylinder, ray);
	cr_expect(eq(xs.amount, 2));

	clean_shape(&cylinder);
	clean_intersection_lst(&xs.i);
}

Test(Intersectiong_the_caps_of_a_closed_cylinder, On_x_0_y_minus_1_z_minus_2)
{
	t_shape	cylinder = new_cylinder();

	cylinder.any->minimum = 1;
	cylinder.any->maximum = 2;
	cylinder.any->closed = true;

	t_obj			direction = object_normalize(create_vector(0, 1, 1));
	t_ray			ray = create_ray(create_point(0, -1, -2), direction);
	t_intersections xs = (t_intersections){0};

	intersect_caps(&xs, cylinder, ray);
	cr_expect(eq(xs.amount, 2));

	clean_shape(&cylinder);
	clean_intersection_lst(&xs.i);
}

Test(The_normal_vector_on_a_cylinders_end_caps, On_x_0_y_1_z_0)
{
	t_shape		cylinder = new_cylinder();

	cylinder.any->minimum = 1;
	cylinder.any->maximum = 2;
	cylinder.any->closed = true;

	t_obj		normal = normal_at_cylinder(cylinder, create_point(0, 1, 0));

	cr_assert(cr_object_eq(normal, create_vector(0, -1, 0)));

	clean_shape(&cylinder);
}

Test(The_normal_vector_on_a_cylinders_end_caps, On_x_0_dot_5_y_1_z_0)
{
	t_shape		cylinder = new_cylinder();

	cylinder.any->minimum = 1;
	cylinder.any->maximum = 2;
	cylinder.any->closed = true;

	t_obj		normal = normal_at_cylinder(cylinder, create_point(0.5, 1, 0));

	cr_assert(cr_object_eq(normal, create_vector(0, -1, 0)));

	clean_shape(&cylinder);
}

Test(The_normal_vector_on_a_cylinders_end_caps, On_x_0_y_1_z_0_dot_5)
{
	t_shape		cylinder = new_cylinder();

	cylinder.any->minimum = 1;
	cylinder.any->maximum = 2;
	cylinder.any->closed = true;

	t_obj		normal = normal_at_cylinder(cylinder, create_point(0, 1, 0.5));

	cr_assert(cr_object_eq(normal, create_vector(0, -1, 0)));

	clean_shape(&cylinder);
}

Test(The_normal_vector_on_a_cylinders_end_caps, On_x_0_y_2_z_0)
{
	t_shape		cylinder = new_cylinder();

	cylinder.any->minimum = 1;
	cylinder.any->maximum = 2;
	cylinder.any->closed = true;

	t_obj		normal = normal_at_cylinder(cylinder, create_point(0, 2, 0));

	cr_assert(cr_object_eq(normal, create_vector(0, 1, 0)));

	clean_shape(&cylinder);
}

Test(The_normal_vector_on_a_cylinders_end_caps, On_x_0_dot_5_y_2_z_0)
{
	t_shape		cylinder = new_cylinder();

	cylinder.any->minimum = 1;
	cylinder.any->maximum = 2;
	cylinder.any->closed = true;

	t_obj		normal = normal_at_cylinder(cylinder, create_point(0.5, 2, 0));

	cr_assert(cr_object_eq(normal, create_vector(0, 1, 0)));

	clean_shape(&cylinder);
}

Test(The_normal_vector_on_a_cylinders_end_caps, On_x_0_y_2_z_0_dot_5)
{
	t_shape		cylinder = new_cylinder();

	cylinder.any->minimum = 1;
	cylinder.any->maximum = 2;
	cylinder.any->closed = true;

	t_obj		normal = normal_at_cylinder(cylinder, create_point(0, 2, 0.5));

	cr_assert(cr_object_eq(normal, create_vector(0, 1, 0)));

	clean_shape(&cylinder);
}
