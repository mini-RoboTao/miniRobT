#include "unit_test.h"

Test(Matrix_scale, Create_matrix_scaling)
{
	t_matrix *res;

	res = scaling(0.1, 0.2, 0.3);
	cr_assert(res != NULL);
	cr_assert(eq(res->node[0][0], 0.1));
	cr_assert(eq(res->node[1][1], 0.2));
	cr_assert(eq(res->node[2][2], 0.3));
	cr_assert(eq(res->node[3][3], 1));
	clean_matrix(res);
}

Test(Matrix_scale, A_scalling_matrix_applied_to_a_point)
{
	t_matrix	*transformation;
	t_obj		point;
	t_obj		result_reference;
	t_obj		result;

	transformation = scaling(2, 3, 4);
	cr_assert(eq(transformation->node[0][0], 2));
	cr_assert(eq(transformation->node[1][1], 3));
	cr_assert(eq(transformation->node[2][2], 4));
	cr_assert(eq(transformation->node[3][3], 1));

	point = create_point(-4, 6, 8);
	result = multiply_matrix_by_obj(transformation, point, 4, 4);
	result_reference = create_point(-8, 18, 32);
	cr_assert(cr_object_eq(result, result_reference));

	// clean_obj(point);
	// clean_obj(result);
	// clean_obj(result_reference);
	clean_matrix(transformation);
}

Test(Matrix_scale, Multiplying_by_the_inverse_of_a_scaling_matrix)
{
	t_matrix	*transformation;
	t_matrix	*inverse_mtx;
	t_obj		vector;
	t_obj		result_reference;
	t_obj		result;

	transformation = scaling(2, 3, 4);
	inverse_mtx = inverse_matrix(transformation);

	vector = create_vector(-4, 6, 8);
	result = multiply_matrix_by_obj(inverse_mtx, vector, 4, 4);
	result_reference = create_vector(-2, 2, 2);
	cr_assert(cr_object_eq(result, result_reference));

	// clean_obj(vector);
	// clean_obj(result);
	// clean_obj(result_reference);
	clean_matrix(transformation);
	clean_matrix(inverse_mtx);
}

Test(Matrix_scale, A_scalling_matrix_applied_to_a_vector)
{
	t_matrix	*transformation;
	t_obj		vector;
	t_obj		result;
	t_obj		result_reference;

	transformation = scaling(2, 3, 4);
	vector = create_vector(-4, 6, 8);
	result = multiply_matrix_by_obj(transformation, vector, 4,4);
	result_reference = create_vector(-8, 18, 32);
	cr_assert(cr_object_eq(result, result_reference));

	// clean_obj(vector);
	// clean_obj(result);
	// clean_obj(result_reference);
	clean_matrix(transformation);
}

Test(Matrix_reflection, Reflection_is_scalling_by_a_negative_value)
{
	t_matrix	*transformation;
	t_obj		point;
	t_obj		result;
	t_obj		result_reference;

	transformation = scaling(-1, 1, 1);
	point = create_point(2, 3, 4);
	result = multiply_matrix_by_obj(transformation, point, 4,4);
	result_reference = create_point(-2, 3, 4);
	cr_assert(cr_object_eq(result, result_reference));

	// clean_obj(point);
	// clean_obj(result);
	// clean_obj(result_reference);
	clean_matrix(transformation);
}