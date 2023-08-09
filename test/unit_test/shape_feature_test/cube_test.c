#include "unit_test.h"

Test(Check_axis, origin_2_direction_4)
{
	double *t = check_axis(2, 4);

	cr_assert(eq(t[0], -0.75));
	cr_assert(eq(t[1], -0.25));
	free(t);
}

Test(A_ray_intersects_a_cube, On_a_x_positive)
{
	t_shape				cube = new_cube();
	t_ray				ray = create_ray(create_point(5, 0.5, 0), create_vector(-1, 0, 0));
	t_intersections		xs = (t_intersections){0};

	intersect_cube(&xs, cube, ray);
	cr_expect(eq(xs.amount, 2));
	cr_expect(epsilon_eq(flt, xs.i->t, 4, EPSILON));
	cr_expect(epsilon_eq(flt, xs.i->next->t, 6, EPSILON));

	clean_shape(&cube);
	clean_intersection_lst(&xs.i);
}

Test(A_ray_intersects_a_cube, On_a_x_negative)
{
	t_shape				cube = new_cube();
	t_ray				ray = create_ray(create_point(-5, 0.5, 0), create_vector(1, 0, 0));
	t_intersections		xs = (t_intersections){0};

	intersect_cube(&xs, cube, ray);
	cr_assert(eq(xs.amount, 2));
	cr_assert(epsilon_eq(flt, xs.i->t, 4, EPSILON));
	cr_assert(epsilon_eq(flt, xs.i->next->t, 6, EPSILON));

	clean_shape(&cube);
	clean_intersection_lst(&xs.i);
}

Test(A_ray_intersects_a_cube, On_an_y_positive)
{
	t_shape				cube = new_cube();
	t_ray				ray = create_ray(create_point(0.5, 5, 0), create_vector(0, -1, 0));
	t_intersections		xs = (t_intersections){0};

	intersect_cube(&xs, cube, ray);
	cr_assert(eq(xs.amount, 2));
	cr_assert(epsilon_eq(flt, xs.i->t, 4, EPSILON));
	cr_assert(epsilon_eq(flt, xs.i->next->t, 6, EPSILON));

	clean_shape(&cube);
	clean_intersection_lst(&xs.i);
}

Test(A_ray_intersects_a_cube, On_an_y_negative)
{
	t_shape				cube = new_cube();
	t_ray				ray = create_ray(create_point(0.5, -5, 0), create_vector(0, 1, 0));
	t_intersections		xs = (t_intersections){0};

	intersect_cube(&xs, cube, ray);
	cr_assert(eq(xs.amount, 2));
	cr_assert(epsilon_eq(flt, xs.i->t, 4, EPSILON));
	cr_assert(epsilon_eq(flt, xs.i->next->t, 6, EPSILON));

	clean_shape(&cube);
	clean_intersection_lst(&xs.i);
}

Test(A_ray_intersects_a_cube, On_a_z_positive)
{
	t_shape				cube = new_cube();
	t_ray				ray = create_ray(create_point(0.5, 0, 5), create_vector(0, 0, -1));
	t_intersections		xs = (t_intersections){0};

	intersect_cube(&xs, cube, ray);
	cr_assert(eq(xs.amount, 2));
	cr_assert(epsilon_eq(flt, xs.i->t, 4, EPSILON));
	cr_assert(epsilon_eq(flt, xs.i->next->t, 6, EPSILON));

	clean_shape(&cube);
	clean_intersection_lst(&xs.i);
}

Test(A_ray_intersects_a_cube, On_a_z_negative)
{
	t_shape				cube = new_cube();
	t_ray				ray = create_ray(create_point(0.5, 0, -5), create_vector(0, 0, 1));
	t_intersections		xs = (t_intersections){0};

	intersect_cube(&xs, cube, ray);
	cr_assert(eq(xs.amount, 2));
	cr_assert(epsilon_eq(flt, xs.i->t, 4, EPSILON));
	cr_assert(epsilon_eq(flt, xs.i->next->t, 6, EPSILON));

	clean_shape(&cube);
	clean_intersection_lst(&xs.i);
}

Test(A_ray_intersects_a_cube, On_inside)
{
	t_shape				cube = new_cube();
	t_ray				ray = create_ray(create_point(0, 0.5, 0), create_vector(0, 0, 1));
	t_intersections		xs = (t_intersections){0};

	intersect_cube(&xs, cube, ray);
	cr_assert(eq(xs.amount, 2));
	cr_assert(epsilon_eq(flt, xs.i->t, -1, EPSILON));
	cr_assert(epsilon_eq(flt, xs.i->next->t, 1, EPSILON));

	clean_shape(&cube);
	clean_intersection_lst(&xs.i);
}

Test(A_ray_misses_a_cube, On_x_minus_two)
{
	t_shape				cube = new_cube();
	t_ray				ray = create_ray(create_point(-2, 0, 0), create_vector(0.2673, 0.5345, 0.8018));
	t_intersections		xs = (t_intersections){0};

	intersect_cube(&xs, cube, ray);
	cr_assert(eq(xs.amount, 0));

	clean_shape(&cube);
	clean_intersection_lst(&xs.i);
}

Test(A_ray_misses_a_cube, On_y_minus_two)
{
	t_shape				cube = new_cube();
	t_ray				ray = create_ray(create_point(0, -2, 0), create_vector(0.8018, 0.2673, 0.5345));
	t_intersections		xs = (t_intersections){0};

	intersect_cube(&xs, cube, ray);
	cr_assert(eq(xs.amount, 0));

	clean_shape(&cube);
	clean_intersection_lst(&xs.i);
}

Test(A_ray_misses_a_cube, On_z_minus_two)
{
	t_shape				cube = new_cube();
	t_ray				ray = create_ray(create_point(0, 0, -2), create_vector(0.5345, 0.8018, 0.2673));
	t_intersections		xs = (t_intersections){0};

	intersect_cube(&xs, cube, ray);
	cr_assert(eq(xs.amount, 0));

	clean_shape(&cube);
	clean_intersection_lst(&xs.i);
}

Test(A_ray_misses_a_cube, On_x_two_and_z_two)
{
	t_shape				cube = new_cube();
	t_ray				ray = create_ray(create_point(2, 0, 2), create_vector(0, 0, -1));
	t_intersections		xs = (t_intersections){0};

	intersect_cube(&xs, cube, ray);
	cr_assert(eq(xs.amount, 0));

	clean_shape(&cube);
	clean_intersection_lst(&xs.i);
}

Test(A_ray_misses_a_cube, On_y_two_and_z_two)
{
	t_shape				cube = new_cube();
	t_ray				ray = create_ray(create_point(0, 2, 2), create_vector(0, -1, 0));
	t_intersections		xs = (t_intersections){0};

	intersect_cube(&xs, cube, ray);
	cr_assert(eq(xs.amount, 0));

	clean_shape(&cube);
	clean_intersection_lst(&xs.i);
}

Test(A_ray_misses_a_cube, On_x_two_and_y_two)
{
	t_shape				cube = new_cube();
	t_ray				ray = create_ray(create_point(2, 2, 0), create_vector(-1, 0, 0));
	t_intersections		xs = (t_intersections){0};

	intersect_cube(&xs, cube, ray);
	cr_assert(eq(xs.amount, 0));

	clean_shape(&cube);
	clean_intersection_lst(&xs.i);
}

Test(The_normal_on_the_surface_of_a_cube, Point_x_one_y_zero_dot_five_z_minus_zero_dot_eight)
{
	t_shape	cube = new_cube();
	t_obj	point = create_point(1, 0.5, -0.8);
	t_obj	normal = normal_at_cube(cube, point);

	cr_assert(cr_object_eq(normal, create_vector(1, 0, 0)));

	clean_shape(&cube);
}

Test(The_normal_on_the_surface_of_a_cube, Point_x_minus_one_y_minus_zero_dot_two_z_zero_dot_nine)
{
	t_shape	cube = new_cube();
	t_obj	point = create_point(-1, -0.2, 0.9);
	t_obj	normal = normal_at_cube(cube, point);

	cr_assert(cr_object_eq(normal, create_vector(-1, 0, 0)));

	clean_shape(&cube);
}

Test(The_normal_on_the_surface_of_a_cube, Point_x_minus_zero_dot_four_y_one_z_minus_zero_dot_one)
{
	t_shape	cube = new_cube();
	t_obj	point = create_point(-0.4, 1, -0.1);
	t_obj	normal = normal_at_cube(cube, point);

	cr_assert(cr_object_eq(normal, create_vector(0, 1, 0)));

	clean_shape(&cube);
}

Test(The_normal_on_the_surface_of_a_cube, Point_x_zero_dot_three_y_minus_one_z_minus_zero_dot_seven)
{
	t_shape	cube = new_cube();
	t_obj	point = create_point(0.3, -1, -0.7);
	t_obj	normal = normal_at_cube(cube, point);

	cr_assert(cr_object_eq(normal, create_vector(0, -1, 0)));

	clean_shape(&cube);
}

Test(The_normal_on_the_surface_of_a_cube, Point_x_minus_zero_dot_six_y_zero_dot_three_z_one)
{
	t_shape	cube = new_cube();
	t_obj	point = create_point(-0.6, 0.3, 1);
	t_obj	normal = normal_at_cube(cube, point);

	cr_assert(cr_object_eq(normal, create_vector(0, 0, 1)));

	clean_shape(&cube);
}

Test(The_normal_on_the_surface_of_a_cube, Point_x_zero_dot_four_y_zero_dot_four_z_minus_one)
{
	t_shape	cube = new_cube();
	t_obj	point = create_point(0.4, 0.4, -1);
	t_obj	normal = normal_at_cube(cube, point);

	cr_assert(cr_object_eq(normal, create_vector(0, 0, -1)));

	clean_shape(&cube);
}

Test(The_normal_on_the_surface_of_a_cube, Point_x_one_y_one_z_one)
{
	t_shape	cube = new_cube();
	t_obj	point = create_point(1, 1, 1);
	t_obj	normal = normal_at_cube(cube, point);

	cr_assert(cr_object_eq(normal, create_vector(1, 0, 0)));

	clean_shape(&cube);
}

Test(The_normal_on_the_surface_of_a_cube, Point_x_minus_one_y_minus_one_z_minus_one)
{
	t_shape	cube = new_cube();
	t_obj	point = create_point(-1, -1, -1);
	t_obj	normal = normal_at_cube(cube, point);

	cr_assert(cr_object_eq(normal, create_vector(-1, 0, 0)));

	clean_shape(&cube);
}
