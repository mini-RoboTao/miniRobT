#include "unit_test.h"

Test(Matrix_shearing, Create_matrix_shearing)
{
	t_matrix 	res;
	t_shearing	shearing_points;

	shearing_points.x_to_y = 2;
	shearing_points.x_to_z = 3;
	shearing_points.y_to_x = 4;
	shearing_points.y_to_z = 5;
	shearing_points.z_to_x = 6;
	shearing_points.z_to_y = 7;

	res = shearing(shearing_points);
	cr_assert(eq(res.node[0][0], 1));
	cr_assert(eq(res.node[1][1], 1));
	cr_assert(eq(res.node[2][2], 1));
	cr_assert(eq(res.node[3][3], 1));
	cr_assert(eq(res.node[0][1], shearing_points.x_to_y));
	cr_assert(eq(res.node[0][2], shearing_points.x_to_z));
	cr_assert(eq(res.node[1][0], shearing_points.y_to_x));
	cr_assert(eq(res.node[1][2], shearing_points.y_to_z));
	cr_assert(eq(res.node[2][0], shearing_points.z_to_x));
	cr_assert(eq(res.node[2][1], shearing_points.z_to_y));
}

Test(Matrix_shearing, A_shearing_transformation_movex_x_in_proportion_to_y)
{
	t_matrix	transformation;
	t_obj		point;
	t_obj		result_reference;
	t_obj		result;
	t_shearing	shearing_points;

	shearing_points.x_to_y = 1;
	shearing_points.x_to_z = 0;
	shearing_points.y_to_x = 0;
	shearing_points.y_to_z = 0;
	shearing_points.z_to_x = 0;
	shearing_points.z_to_y = 0;
	transformation = shearing(shearing_points);

	cr_assert(eq(transformation.node[0][1], 1));
	cr_assert(eq(transformation.node[0][0], 1));
	cr_assert(eq(transformation.node[1][1], 1));
	cr_assert(eq(transformation.node[2][2], 1));
	cr_assert(eq(transformation.node[3][3], 1));

	point = create_point(2, 3, 4);
	result = multiply_matrix_by_obj(transformation, point, 4, 4);
	result_reference = create_point(5, 3, 4);
	cr_assert(cr_object_eq(result, result_reference));
}

Test(Matrix_shearing, A_shearing_transformation_movex_x_in_proportion_to_z)
{
	t_matrix	transformation;
	t_obj		point;
	t_obj		result_reference;
	t_obj		result;
	t_shearing	shearing_points;

	shearing_points.x_to_y = 0;
	shearing_points.x_to_z = 1;
	shearing_points.y_to_x = 0;
	shearing_points.y_to_z = 0;
	shearing_points.z_to_x = 0;
	shearing_points.z_to_y = 0;

	transformation = shearing(shearing_points);

	cr_assert(eq(transformation.node[0][2], 1));
	cr_assert(eq(transformation.node[0][0], 1));
	cr_assert(eq(transformation.node[1][1], 1));
	cr_assert(eq(transformation.node[2][2], 1));
	cr_assert(eq(transformation.node[3][3], 1));

	point = create_point(2, 3, 4);
	result = multiply_matrix_by_obj(transformation, point, 4, 4);
	result_reference = create_point(6, 3, 4);
	cr_assert(cr_object_eq(result, result_reference));
}

Test(Matrix_shearing, A_shearing_transformation_movex_y_in_proportion_to_x)
{
	t_matrix	transformation;
	t_obj		point;
	t_obj		result_reference;
	t_obj		result;
	t_shearing	shearing_points;

	shearing_points.x_to_y = 0;
	shearing_points.x_to_z = 0;
	shearing_points.y_to_x = 1;
	shearing_points.y_to_z = 0;
	shearing_points.z_to_x = 0;
	shearing_points.z_to_y = 0;

	transformation = shearing(shearing_points);

	cr_assert(eq(transformation.node[1][0], 1));
	cr_assert(eq(transformation.node[0][0], 1));
	cr_assert(eq(transformation.node[1][1], 1));
	cr_assert(eq(transformation.node[2][2], 1));
	cr_assert(eq(transformation.node[3][3], 1));

	point = create_point(2, 3, 4);
	result = multiply_matrix_by_obj(transformation, point, 4, 4);
	result_reference = create_point(2, 5, 4);
	cr_assert(cr_object_eq(result, result_reference));
}

Test(Matrix_shearing, A_shearing_transformation_movex_y_in_proportion_to_z)
{
	t_matrix	transformation;
	t_obj		point;
	t_obj		result_reference;
	t_obj		result;
	t_shearing	shearing_points;

	shearing_points.x_to_y = 0;
	shearing_points.x_to_z = 0;
	shearing_points.y_to_x = 0;
	shearing_points.y_to_z = 1;
	shearing_points.z_to_x = 0;
	shearing_points.z_to_y = 0;

	transformation = shearing(shearing_points);

	cr_assert(eq(transformation.node[1][2], 1));
	cr_assert(eq(transformation.node[0][0], 1));
	cr_assert(eq(transformation.node[1][1], 1));
	cr_assert(eq(transformation.node[2][2], 1));
	cr_assert(eq(transformation.node[3][3], 1));

	point = create_point(2, 3, 4);
	result = multiply_matrix_by_obj(transformation, point, 4, 4);
	result_reference = create_point(2, 7, 4);
	cr_assert(cr_object_eq(result, result_reference));
}

Test(Matrix_shearing, A_shearing_transformation_movex_z_in_proportion_to_x)
{
	t_matrix	transformation;
	t_obj		point;
	t_obj		result_reference;
	t_obj		result;
	t_shearing	shearing_points;

	shearing_points.x_to_y = 0;
	shearing_points.x_to_z = 0;
	shearing_points.y_to_x = 0;
	shearing_points.y_to_z = 0;
	shearing_points.z_to_x = 1;
	shearing_points.z_to_y = 0;

	transformation = shearing(shearing_points);

	cr_assert(eq(transformation.node[2][0], 1));
	cr_assert(eq(transformation.node[0][0], 1));
	cr_assert(eq(transformation.node[1][1], 1));
	cr_assert(eq(transformation.node[2][2], 1));
	cr_assert(eq(transformation.node[3][3], 1));

	point = create_point(2, 3, 4);
	result = multiply_matrix_by_obj(transformation, point, 4, 4);
	result_reference = create_point(2, 3, 6);
	cr_assert(cr_object_eq(result, result_reference));
}

Test(Matrix_shearing, A_shearing_transformation_movex_z_in_proportion_to_y)
{
	t_matrix	transformation;
	t_obj		point;
	t_obj		result_reference;
	t_obj		result;
	t_shearing	shearing_points;

	shearing_points.x_to_y = 0;
	shearing_points.x_to_z = 0;
	shearing_points.y_to_x = 0;
	shearing_points.y_to_z = 0;
	shearing_points.z_to_x = 0;
	shearing_points.z_to_y = 1;

	transformation = shearing(shearing_points);

	cr_assert(eq(transformation.node[2][1], 1));
	cr_assert(eq(transformation.node[0][0], 1));
	cr_assert(eq(transformation.node[1][1], 1));
	cr_assert(eq(transformation.node[2][2], 1));
	cr_assert(eq(transformation.node[3][3], 1));

	point = create_point(2, 3, 4);
	result = multiply_matrix_by_obj(transformation, point, 4, 4);
	result_reference = create_point(2, 3, 7);
	cr_assert(cr_object_eq(result, result_reference));
}
