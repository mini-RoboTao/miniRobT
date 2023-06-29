#include "unit_test.h"

Test(object_operations, test_sums_two_objects_one_of_type_vector_and_one_type_point_should_be_a_point)
{
	t_obj	*obj1 = create_object(3, -2, 5, 1);
	t_obj	*obj2 = create_object(-2, 3, 1, 0);
	t_obj	*expected = create_object(1, 1, 6, 1);
	t_obj	*result;

	result = sum_objects(obj1, obj2);
	cr_assert(cr_object_eq(result, expected));
	clean_obj(obj1);
	clean_obj(obj2);
	clean_obj(expected);
	clean_obj(result);
}

Test(object_operations, test_sums_two_objects_of_type_vector_should_be_a_vector)
{
	t_obj	*obj1 = create_object(3, -2, 5, 0);
	t_obj	*obj2 = create_object(-2, 3, 1, 0);
	t_obj	*expected = create_object(1, 1, 6, 0);
	t_obj	*result;

	result = sum_objects(obj1, obj2);
	cr_assert(cr_object_eq(result, expected));
	clean_obj(obj1);
	clean_obj(obj2);
	clean_obj(expected);
	clean_obj(result);
}

Test(object_operations, test_sums_two_objects_of_type_point_should_be_NULL)
{
	t_obj	*obj1 = create_object(3, -2, 5, 1);
	t_obj	*obj2 = create_object(-2, 3, 1, 1);
	t_obj	*expected = NULL;
	t_obj	*result;

	result = sum_objects(obj1, obj2);
	cr_assert(eq(result, expected));
	clean_obj(obj1);
	clean_obj(obj2);
}

Test(object_operations, test_sums_two_objects_one_NULL_and_another_type_vector)
{
	t_obj	*obj1 = NULL;
	t_obj	*obj2 = create_vector(5, 6, 7);
	t_obj	*expected = NULL;
	t_obj	*result;

	result = sum_objects(obj1, obj2);
	cr_assert(eq(result, expected));
	result = sum_objects(obj2, obj1);
	cr_assert(eq(result, expected));
	clean_obj(obj2);
}

Test(object_operations, test_subtractions_two_objects_of_type_point_should_be_a_vector)
{
	t_obj	*obj1 = create_point(3, 2, 1);
	t_obj	*obj2 = create_point(5, 6, 7);
	t_obj	*expected = create_vector(-2, -4, -6);
	t_obj	*result;

	result = subtract_objects(obj1, obj2);
	cr_assert(cr_object_eq(result, expected));
	clean_obj(obj1);
	clean_obj(obj2);
	clean_obj(expected);
	clean_obj(result);
}

Test(object_operations, test_subtractions_two_objects_one_of_type_point_minus_a_type_vector_should_be_a_point)
{
	t_obj	*obj1 = create_point(3, 2, 1);
	t_obj	*obj2 = create_vector(5, 6, 7);
	t_obj	*expected = create_point(-2, -4, -6);
	t_obj	*result;

	result = subtract_objects(obj1, obj2);
	cr_assert(cr_object_eq(result, expected));
	clean_obj(obj1);
	clean_obj(obj2);
	clean_obj(expected);
	clean_obj(result);
}

Test(object_operations, test_subtractions_two_objects_of_type_vector_should_be_a_vector)
{
	t_obj	*obj1 = create_vector(3, 2, 1);
	t_obj	*obj2 = create_vector(5, 6, 7);
	t_obj	*expected = create_vector(-2, -4, -6);
	t_obj	*result;

	result = subtract_objects(obj1, obj2);
	cr_assert(cr_object_eq(result, expected));
	clean_obj(obj1);
	clean_obj(obj2);
	clean_obj(expected);
	clean_obj(result);
}

Test(object_operations, test_subtractions_two_objects_one_of_type_vector_minus_a_type_point_should_be_NULL)
{
	t_obj	*obj1 = create_vector(5, 6, 7);
	t_obj	*obj2 = create_point(3, 2, 1);
	t_obj	*expected = NULL;
	t_obj	*result;

	result = subtract_objects(obj1, obj2);
	cr_assert(eq(result, expected));
	clean_obj(obj1);
	clean_obj(obj2);
}

Test(object_operations, test_subtractions_two_objects_one_NULL_and_another_type_vector)
{
	t_obj	*obj1 = NULL;
	t_obj	*obj2 = create_vector(5, 6, 7);
	t_obj	*expected = NULL;
	t_obj	*result;

	result = subtract_objects(obj1, obj2);
	cr_assert(eq(result, expected));
	result = subtract_objects(obj2, obj1);
	cr_assert(eq(result, expected));
	clean_obj(obj2);
}

Test(object_operations, test_negate_a_object_of_type_vector)
{
	t_obj	*vector = create_vector(1, -2, 3);
	t_obj	*expected = create_vector(-1, 2, -3);
	t_obj	*result;

	result = negating_object(vector);
	cr_assert(cr_object_eq(result, expected));
	clean_obj(result);
	clean_obj(expected);
}

Test(object_operations, test_negate_a_object_of_type_vector_with_all_values_zero)
{
	t_obj	*vector = create_vector(0, 0, 0);
	t_obj	*expected = create_vector(0, 0, 0);
	t_obj	*result;

	result = negating_object(vector);
	cr_assert(cr_object_eq(result, expected));
	clean_obj(result);
	clean_obj(expected);
}

Test(object_operations, test_negate_a_object_NULL_should_be_NULL)
{
	t_obj	*vector = NULL;
	t_obj	*expected = NULL;
	t_obj	*result;

	result = negating_object(vector);
	cr_assert(eq(result, expected));
}

Test(object_operations, test_negate_a_object_should_be_the_object_negate)
{
	t_obj	*obj = create_object(1, -2, 3, -4);
	t_obj	*expected = create_object(-1, 2, -3, 4);
	t_obj	*result;

	result = negating_object(obj);
	cr_assert(cr_object_eq(result, expected));
	clean_obj(result);
	clean_obj(expected);
}

Test(object_operations, test_multiply_a_object_by_a_scalar_3_dot_5)
{
	double	scale = 3.5;
	t_obj	*result;
	t_obj	*obj1 = create_object(1, -2, 3, -4);
	t_obj	*expected = create_object(3.5, -7, 10.5, -14.0);

	result = multiply_object(obj1, scale);
	cr_assert(cr_object_eq(result, expected));
	clean_obj(result);
	clean_obj(expected);
}

Test(object_operations, test_multiply_a_object_by_a_fraction_0_dot_5)
{
	double	scale = 0.5;
	t_obj	*result;
	t_obj	*obj1 = create_object(1, -2, 3, -4);
	t_obj	*expected = create_object(0.5, -1, 1.5, -2);

	result = multiply_object(obj1, scale);
	cr_assert(cr_object_eq(result, expected));
	clean_obj(result);
	clean_obj(expected);
}

Test(object_operations, test_multiply_a_object_by_0)
{
	double	scale = 0;
	t_obj	*result;
	t_obj	*obj1 = create_object(1, -2, 3, -4);
	t_obj	*expected = create_object(0, 0, 0, 0);

	result = multiply_object(obj1, scale);
	cr_assert(cr_object_eq(result, expected));
	clean_obj(result);
	clean_obj(expected);
}

Test(object_operations, test_multiply_a_NULL_object_should_be_NULL)
{
	double	scale = 0.5;
	t_obj	*result;
	t_obj	*obj1 = NULL;
	t_obj	*expected = NULL;

	result = multiply_object(obj1, scale);
	cr_assert(eq(result, expected));
}

Test(object_operations, test_divide_a_object_by_a_scalar_2)
{
	double	scale = 2;
	t_obj	*result;
	t_obj	*obj1 = create_object(1, -2, 3, -4);
	t_obj	*expected = create_object(0.5, -1, 1.5, -2);

	result = divide_object(obj1, scale);
	cr_assert(cr_object_eq(result, expected));
	clean_obj(result);
	clean_obj(expected);
}

Test(object_operations, test_divide_a_object_by_0)
{
	double	scale = 0;
	t_obj	*result;
	t_obj	*obj1 = create_object(1, -2, 3, -4);
	t_obj	*expected = NULL;

	result = divide_object(obj1, scale);
	cr_assert(eq(result, expected));
	clean_obj(obj1);
}

Test(object_operations, test_divide_a_NULL_object_should_be_NULL)
{
	double	scale = 0.5;
	t_obj	*result;
	t_obj	*obj1 = NULL;
	t_obj	*expected = NULL;

	result = divide_object(obj1, scale);
	cr_assert(eq(result, expected));
}
