#include "unit_test.h"

Test(Matrix_translations, Create_matrix_translation)
{
	t_matrix *res;

	// res = alloc_matrix(4, 4);
	res = translation(0.1, 0.2, 0.3);
	cr_assert(res != NULL);
	cr_assert(eq(res->node[0][3], 0.1));
	cr_assert(eq(res->node[1][3], 0.2));
	cr_assert(eq(res->node[2][3], 0.3));
	cr_assert(eq(res->node[0][0], 1));
	cr_assert(eq(res->node[1][1], 1));
	cr_assert(eq(res->node[2][2], 1));
	cr_assert(eq(res->node[3][3], 1));
	clean_matrix(res);
}

Test(Matrix_translations, Multiplying_by_a_translation_matrix)
{
	t_matrix	*transformation;
	t_obj		*point;
	t_obj		*result_reference;
	t_obj		*result;

	transformation = translation(5, -3, 2);
	cr_assert(eq(transformation->node[0][3], 5));
	cr_assert(eq(transformation->node[1][3], -3));
	cr_assert(eq(transformation->node[2][3], 2));
	cr_assert(eq(transformation->node[0][0], 1));
	cr_assert(eq(transformation->node[1][1], 1));
	cr_assert(eq(transformation->node[2][2], 1));
	cr_assert(eq(transformation->node[3][3], 1));

	point = create_point(-3, 4, 5);
	result = multiply_matrix_by_obj(transformation, point, 4, 4);
	result_reference = create_point(2, 1, 7);
	cr_assert(cr_object_eq(result, result_reference));

	clean_obj(point);
	clean_obj(result);
	clean_obj(result_reference);
	clean_matrix(transformation);
}

Test(Matrix_translations, Multiplying_by_the_inverse_of_a_translation_matrix)
{
	t_matrix	*transformation;
	t_matrix	*inverse_mtx;
	t_obj		*point;
	t_obj		*result_reference;
	t_obj		*result;

	transformation = translation(5, -3, 2);
	inverse_mtx = inverse_matrix(transformation);
	cr_assert(eq(inverse_mtx->node[0][3], -5));
	cr_assert(eq(inverse_mtx->node[1][3], 3));
	cr_assert(eq(inverse_mtx->node[2][3], -2));
	cr_assert(eq(inverse_mtx->node[0][0], 1));
	cr_assert(eq(inverse_mtx->node[1][1], 1));
	cr_assert(eq(inverse_mtx->node[2][2], 1));
	cr_assert(eq(inverse_mtx->node[3][3], 1));

	point = create_point(-3, 4, 5);
	result = multiply_matrix_by_obj(inverse_mtx, point, 4, 4);
	result_reference = create_point(-8, 7, 3);
	cr_assert(cr_object_eq(result, result_reference));

	clean_obj(point);
	clean_obj(result);
	clean_obj(result_reference);
	clean_matrix(transformation);
	clean_matrix(inverse_mtx);
}

Test(Matrix_translations, Translation_does_not_affect_vector)
{
	t_matrix	*transformation;
	t_obj		*vector;
	t_obj		*result;

	transformation = translation(5, -3, 2);
	vector = create_vector(-3, 4, 5);
	result = multiply_matrix_by_obj(transformation, vector, 4,4);
	cr_assert(cr_object_eq(result, vector));

	clean_obj(vector);
	clean_obj(result);
	clean_matrix(transformation);
}