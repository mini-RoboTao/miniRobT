#include "unit_test.h"

Test(Normal_on_a_sphere, The_normal_on_a_sphere_at_a_point_on_the_x_axis)
{
	t_shape		shape = new_sphere();
	t_obj		point = create_point(1, 0, 0);
	t_obj		vector = create_vector(1, 0, 0);
	t_obj		n = normal_at(shape, point);

	cr_assert(cr_object_eq(n, vector));
	clean_shape(&shape);
}

Test(Normal_on_a_sphere, The_normal_on_a_sphere_at_a_point_on_the_y_axis)
{
	t_shape		shape = new_sphere();
	t_obj		point = create_point(0, 1, 0);
	t_obj		vector = create_vector(0, 1, 0);
	t_obj		n = normal_at(shape, point);

	cr_assert(cr_object_eq(n, vector));
	clean_shape(&shape);
}

Test(Normal_on_a_sphere, The_normal_on_a_sphere_at_a_point_on_the_z_axis)
{
	t_shape		shape = new_sphere();
	t_obj		point = create_point(0, 0, 1);
	t_obj		vector = create_vector(0, 0, 1);
	t_obj		n = normal_at(shape, point);

	cr_assert(cr_object_eq(n, vector));
	clean_shape(&shape);
}

Test(Normal_on_a_sphere, The_normal_on_a_sphere_at_a_nonaxial_point)
{
	t_shape		shape = new_sphere();
	t_obj		point = create_point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3);
	t_obj		vector = create_vector(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3);
	t_obj		n = normal_at(shape, point);

	cr_assert(cr_object_eq(n, vector));
	clean_shape(&shape);;
}

Test(Normal_on_a_sphere, The_normal_is_a_normalized_vector)
{
	t_shape		shape = new_sphere();
	t_obj		point = create_point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3);
	t_obj		n = normal_at(shape, point);

	cr_assert(cr_object_eq(n, object_normalize(n)));
	clean_shape(&shape);
}

Test(Normal_on_a_sphere, Computing_the_normal_on_a_translated_sphere)
{
	t_shape		shape = new_sphere();
	t_obj		point = create_point(0, 1.70711, -0.70711);
	t_obj		vector = create_vector(0, 0.70711, -0.70711);
	set_transform(&shape, translation(0, 1, 0));
	t_obj		n = normal_at(shape, point);

	cr_expect(cr_object_eq(n, vector));
	clean_shape(&shape);
}

Test(Normal_on_a_sphere, Computing_the_normal_on_a_transformed_sphere)
{
	t_shape		shape = new_sphere();
	t_matrix	scaled = scaling(1, 0.5, 1);
	t_matrix	z_rotated = rotation_z(M_PI/5);
	t_matrix	res_matrix = multiply_matrix(scaled, z_rotated, 4, 4);
	t_obj		point = create_point(0, sqrt(2)/2, -sqrt(2)/2);
	set_transform(&shape, res_matrix);
	t_obj		vector = create_vector(0, 0.97014, -0.24254);
	t_obj		n = normal_at(shape, point);

	cr_expect(cr_object_eq(n, vector));
	clean_shape(&shape);
}
