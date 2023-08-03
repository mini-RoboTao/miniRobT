#include "unit_test.h"

Test(Chaining_transformations, Individual_transformations_are_applied_in_sequence)
{
	t_matrix	rotation_matrix;
	t_matrix	scaling_matrix;
	t_matrix	translation_matrix;
	t_obj		point;
	t_obj		result_rotation;
	t_obj		result_scaling;
	t_obj		result_translation;
	t_obj		result_reference_after_rotation;
	t_obj		result_reference_after_scaling;
	t_obj		result_reference_after_translation;

	point = create_point(1, 0, 1);
	rotation_matrix = rotation_x(M_PI/2);
	scaling_matrix = scaling(5, 5, 5);
	translation_matrix = translation(10, 5, 7);

	result_rotation = multiply_matrix_by_obj(rotation_matrix, point, 4, 4);
	result_reference_after_rotation = create_point(1, -1, 0);
	cr_assert(cr_object_eq(result_rotation, result_reference_after_rotation));

	result_scaling = multiply_matrix_by_obj(scaling_matrix, result_rotation, 4, 4);
	result_reference_after_scaling = create_point(5, -5, 0);
	cr_assert(cr_object_eq(result_scaling, result_reference_after_scaling));

	result_translation = multiply_matrix_by_obj(translation_matrix, result_scaling, 4, 4);
	result_reference_after_translation = create_point(15, 0, 7);
	cr_assert(cr_object_eq(result_translation, result_reference_after_translation));
}

Test(Chaining_transformations, Chained_transformations_must_be_applied_in_reverse_order)
{
	t_matrix	rotation_matrix;
	t_matrix	scaling_matrix;
	t_matrix	translation_matrix;
	t_matrix	result_matrix_after_one_operation;
	t_matrix	result_matrix;
	t_obj		point;
	t_obj		result;
	t_obj		result_reference;

	point = create_point(1, 0, 1);
	rotation_matrix = rotation_x(M_PI/2);
	scaling_matrix = scaling(5, 5, 5);
	translation_matrix = translation(10, 5, 7);

	result_reference = create_point(15, 0, 7);

	result_matrix_after_one_operation = multiply_matrix(translation_matrix, scaling_matrix, 4, 4);
	result_matrix = multiply_matrix(result_matrix_after_one_operation, rotation_matrix, 4, 4);

	result = multiply_matrix_by_obj(result_matrix, point, 4, 4);
	cr_assert(cr_object_eq(result, result_reference));
}
