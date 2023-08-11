#include "unit_test.h"

Test(shapes, the_dafault_transformation)
{
	t_shape	shape = test_shape();
	cr_assert(\
		cr_matrix_eq(create_identity_matrix(),\
		shape.any->transform));
	clean_shape(&shape);
}

Test(shapes, assigning_a_transformation)
{
	t_shape	shape = test_shape();
	set_transform(&shape, translation(2, 3, 4));
	cr_assert(cr_matrix_eq(\
		translation(2, 3, 4),\
		shape.any->transform));
	clean_shape(&shape);
}

Test(shapes, the_default_material)
{
	t_shape	shape = test_shape();
	cr_assert(cr_material_eq(\
		shape.any->material,\
		new_material()));
	clean_shape(&shape);
}

Test(shapes, assigning_a_material)
{
	t_material	m = new_material();
	m.ambient = 1;

	t_shape	shape = test_shape();
	shape.any->material = m;
	cr_assert(cr_material_eq(\
		shape.any->material, m));
	clean_shape(&shape);
}

Test(shapes, intersectiong_a_scaled_shape_with_a_ray)
{
	t_intersections		xs = (t_intersections){0};
	t_ray	ray			= create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	t_shape	shape		= test_shape();

	set_transform(&shape, scaling(2, 2, 2));
	intersect(&xs, shape, ray);
	cr_assert(cr_object_eq(shape.any->saved_ray.position, create_point(0, 0, -2.5)));
	cr_assert(cr_object_eq(shape.any->saved_ray.direction, create_vector(0, 0, 0.5)));
	clean_shape(&shape);
	clean_intersection_lst(&xs.i);
}

Test(shapes, intersectiong_a_translated_shape_with_a_ray)
{
	t_intersections		xs;
	t_ray	ray			= create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	t_shape	shape		= test_shape();

	set_transform(&shape, translation(5, 0, 0));
	intersect(&xs, shape, ray);
	cr_assert(cr_object_eq(shape.any->saved_ray.position, create_point(-5, 0, -5)));
	cr_assert(cr_object_eq(shape.any->saved_ray.direction, create_vector(0, 0, 1)));
	clean_shape(&shape);
}

Test(shapes, computing_the_normal_on_a_translated_shape)
{
	t_obj	norm;
	t_shape	shape = test_shape();

	set_transform(&shape, translation(0, 1, 0));
	norm = normal_at(shape, create_point(0, 1.70711, -0.70711));
	cr_assert(cr_object_eq(norm, create_vector(0, 0.70711, -0.70711)));
	clean_shape(&shape);
}

Test(shapes, computing_the_normal_on_a_transformed_shape)
{
	t_obj		norm;
	t_shape		shape = test_shape();
	t_matrix	matrix = multiply_matrix(scaling(1, 0.5, 1), rotation_z(M_PI / 5), 4, 4);

	set_transform(&shape, matrix);
	norm = normal_at(shape, create_point(0, (sqrt(2)) / 2, -((sqrt(2)) / 2)));
	cr_assert(cr_object_eq(norm, create_vector(0, 0.97014, -0.24254)));
	clean_shape(&shape);
}

Test(Plane, the_normal_of_a_plane_is_constant_everywhere)
{
	t_shape	plane = new_plane();
	t_obj	norm1 =	plane.normal_at(plane, create_point(0, 0, 0));
	t_obj	norm2 = plane.normal_at(plane, create_point(10, 0, -10));
	t_obj	norm3 = plane.normal_at(plane, create_point(-5, 0, 150));

	cr_assert(cr_object_eq(norm1, create_vector(0, 1, 0)));
	cr_assert(cr_object_eq(norm2, create_vector(0, 1, 0)));
	cr_assert(cr_object_eq(norm3, create_vector(0, 1, 0)));
	clean_shape(&plane);
}

Test(Plane, intersect_with_a_ray_parallel_to_the_plane)
{
	t_shape				plane = new_plane();
	t_ray				ray = create_ray(create_point(0, 10, 0), create_vector(0, 0, 1));
	t_intersections		xs = (t_intersections){0};

	intersect(&xs, plane, ray);
	cr_assert(eq(xs.i, NULL));
	cr_assert(eq(xs.amount, 0));
	clean_shape(&plane);
}

Test(Plane, intersect_with_a_coplanar_ray)
{
	t_shape				plane = new_plane();
	t_ray				ray = create_ray(create_point(0, 10, 0), create_vector(0, 0, 1));
	t_intersections		xs = (t_intersections){0};

	intersect(&xs, plane, ray);
	cr_assert(eq(xs.i, NULL));
	cr_assert(eq(xs.amount, 0));
	clean_shape(&plane);
}

Test(Plane, a_ray_intersecting_a_plane_from_above)
{
	t_shape				plane = new_plane();
	t_ray				ray = create_ray(create_point(0, 1, 0), create_vector(0, -1, 0));
	t_intersections		xs = (t_intersections){0};

	intersect(&xs, plane, ray);
	cr_assert(eq(xs.amount, 1));
	cr_assert(eq(xs.i->t, 1));
	cr_assert(cr_plane_eq(xs.i->shape.any, plane.any));
	clean_shape(&plane);
	clean_intersection_lst(&xs.i);
}

Test(Plane, a_ray_intersecting_a_plane_from_below)
{
	t_shape				 plane = new_plane();
	t_ray				ray = create_ray(create_point(0, -1, 0), create_vector(0, 1, 0));
	t_intersections		xs = (t_intersections){0};

	intersect(&xs, plane, ray);
	cr_assert(eq(xs.amount, 1));
	cr_assert(eq(xs.i->t, 1));
	cr_assert(cr_plane_eq(xs.i->shape.any, plane.any));
	clean_shape(&plane);
	clean_intersection_lst(&xs.i);
}