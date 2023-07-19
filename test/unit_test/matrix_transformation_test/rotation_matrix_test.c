#include "unit_test.h"

// ROTATION X AXIS

Test(Matrix_rotation_x, Create_matrix_rotation_x)
{
	t_matrix *res;

	res = rotation_x(M_PI / 4);
	cr_assert(res != NULL);

	cr_assert(eq(res->node[0][0], 1));
	cr_assert(eq(res->node[1][1], cos(M_PI / 4)));
	cr_assert(eq(res->node[1][2], sin(M_PI / 4) * -1));
	cr_assert(eq(res->node[2][1], sin(M_PI / 4)));
	cr_assert(eq(res->node[2][2], cos(M_PI / 4)));
	cr_assert(eq(res->node[3][3], 1));

	clean_matrix(res);
}

Test(Matrix_rotation_x, Rotating_a_point_around_x_axis_half_quarter)
{
	t_matrix	*half_quarter;
	t_obj		*point;
	t_obj		*result_reference_half_quarter;
	t_obj		*result_half_quarter;

	half_quarter = rotation_x(M_PI / 4);

	point = create_point(0, 1, 0);

	result_half_quarter = multiply_matrix_by_obj(half_quarter, point, 4, 4);
	result_reference_half_quarter = create_point(0, sqrt(2) / 2, sqrt(2) / 2);
	cr_assert(cr_object_eq(result_half_quarter, result_reference_half_quarter));

	clean_obj(point);
	clean_obj(result_half_quarter);
	clean_obj(result_reference_half_quarter);
	clean_matrix(half_quarter);
}
Test(Matrix_rotation_x, Rotating_a_point_around_x_axis_full_quarter)
{
	t_matrix	*full_quarter;
	t_obj		*point;
	t_obj		*result_reference_full_quarter;
	t_obj		*result_full_quarter;

	full_quarter = rotation_x(M_PI / 2);

	point = create_point(0, 1, 0);

	result_full_quarter = multiply_matrix_by_obj(full_quarter, point, 4, 4);
	result_reference_full_quarter = create_point(0, 0, 1);
	cr_assert(cr_object_eq(result_full_quarter, result_reference_full_quarter));

	clean_obj(point);
	clean_obj(result_full_quarter);
	clean_obj(result_reference_full_quarter);
	clean_matrix(full_quarter);
}

Test(Matrix_rotation_x, The_inverse_of_an_x_rotation_rotates_in_the_opposite_direction)
{
	t_matrix	*transformation;
	t_matrix	*inverse_mtx;
	t_obj		*point;
	t_obj		*result_reference;
	t_obj		*result;

	transformation = rotation_x(M_PI / 4);
	inverse_mtx = inverse_matrix(transformation);

	point = create_point(0, 1, 0);
	result = multiply_matrix_by_obj(inverse_mtx, point, 4, 4);
	result_reference = create_point(0, sqrt(2) / 2, sqrt(2) / 2 * -1);
	cr_assert(cr_object_eq(result, result_reference));

	clean_obj(point);
	clean_obj(result);
	clean_obj(result_reference);
	clean_matrix(transformation);
	clean_matrix(inverse_mtx);
}

// ROTATION Y AXIS

Test(Matrix_rotation_y, Create_matrix_rotation_y)
{
	t_matrix *res;

	res = rotation_y(M_PI / 4);
	cr_assert(res != NULL);

	cr_assert(eq(res->node[0][0], cos(M_PI / 4)));
	cr_assert(eq(res->node[0][2], sin(M_PI / 4)));
	cr_assert(eq(res->node[1][1], 1));
	cr_assert(eq(res->node[2][0], sin(M_PI / 4) * -1));
	cr_assert(eq(res->node[2][2], cos(M_PI / 4)));
	cr_assert(eq(res->node[3][3], 1));

	clean_matrix(res);
}

Test(Matrix_rotation_y, Rotating_a_point_around_y_axis_half_quarter)
{
	t_matrix	*half_quarter;
	t_obj		*point;
	t_obj		*result_reference_half_quarter;
	t_obj		*result_half_quarter;

	half_quarter = rotation_y(M_PI / 4);

	point = create_point(0, 0, 1);

	result_half_quarter = multiply_matrix_by_obj(half_quarter, point, 4, 4);
	result_reference_half_quarter = create_point(sqrt(2) / 2, 0, sqrt(2) / 2);
	cr_assert(cr_object_eq(result_half_quarter, result_reference_half_quarter));

	clean_obj(point);
	clean_obj(result_half_quarter);
	clean_obj(result_reference_half_quarter);
	clean_matrix(half_quarter);
}

Test(Matrix_rotation_y, Rotating_a_point_around_y_axis_full_quarter)
{
	t_matrix	*full_quarter;
	t_obj		*point;
	t_obj		*result_reference_full_quarter;
	t_obj		*result_full_quarter;

	full_quarter = rotation_y(M_PI / 2);

	point = create_point(0, 0, 1);

	result_full_quarter = multiply_matrix_by_obj(full_quarter, point, 4, 4);
	result_reference_full_quarter = create_point(1, 0, 0);
	cr_assert(cr_object_eq(result_full_quarter, result_reference_full_quarter));

	clean_obj(point);
	clean_obj(result_full_quarter);
	clean_obj(result_reference_full_quarter);
	clean_matrix(full_quarter);
}

// ROTATION Z AXIS

Test(Matrix_rotation_z, Create_matrix_rotation_z)
{
	t_matrix *res;

	res = rotation_z(M_PI / 4);
	cr_assert(res != NULL);

	cr_assert(eq(res->node[0][0], cos(M_PI / 4)));
	cr_assert(eq(res->node[0][1], sin(M_PI / 4) * -1));
	cr_assert(eq(res->node[1][0], sin(M_PI / 4)));
	cr_assert(eq(res->node[1][1], cos(M_PI / 4)));
	cr_assert(eq(res->node[2][2], 1));
	cr_assert(eq(res->node[3][3], 1));

	clean_matrix(res);
}

Test(Matrix_rotation_z, Rotating_a_point_around_y_axis_half_quarter)
{
	t_matrix	*half_quarter;
	t_obj		*point;
	t_obj		*result_reference_half_quarter;
	t_obj		*result_half_quarter;

	half_quarter = rotation_z(M_PI / 4);

	point = create_point(0, 1, 0);

	result_half_quarter = multiply_matrix_by_obj(half_quarter, point, 4, 4);
	result_reference_half_quarter = create_point(sqrt(2) / 2 * -1, sqrt(2) / 2, 0);
	cr_assert(cr_object_eq(result_half_quarter, result_reference_half_quarter));

	clean_obj(point);
	clean_obj(result_half_quarter);
	clean_obj(result_reference_half_quarter);
	clean_matrix(half_quarter);
}

Test(Matrix_rotation_z, Rotating_a_point_around_y_axis_full_quarter)
{
	t_matrix	*full_quarter;
	t_obj		*point;
	t_obj		*result_reference_full_quarter;
	t_obj		*result_full_quarter;

	full_quarter = rotation_z(M_PI / 2);

	point = create_point(0, 1, 0);

	result_full_quarter = multiply_matrix_by_obj(full_quarter, point, 4, 4);
	result_reference_full_quarter = create_point(-1, 0, 0);
	cr_assert(cr_object_eq(result_full_quarter, result_reference_full_quarter));

	clean_obj(point);
	clean_obj(result_full_quarter);
	clean_obj(result_reference_full_quarter);
	clean_matrix(full_quarter);
}
