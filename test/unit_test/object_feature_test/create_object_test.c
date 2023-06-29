#include "unit_test.h"
#include <math.h>

static void	clean_obj(t_obj *o)
{
	if (o)
	{
		free(o);
		o = NULL;
	}
}

int cr_object_eq(t_obj *a, t_obj *b)
{
    return	(fabs(a->x - b->x) < EPSILON && \
			fabs(a->y - b->y) < EPSILON && \
			fabs(a->z - b->z) < EPSILON && \
			a->w == b->w);
}

Test(object_feature_test, test_the_object_is_a_point)
{
	t_obj	*a = create_object(4.3, -4.2, 3.1, 1.0);

	cr_assert(epsilon_eq(flt, a->x, 4.3, EPSILON));
	cr_assert(epsilon_eq(flt, a->y, -4.2, EPSILON));
	cr_assert(epsilon_eq(flt, a->z, 3.1, EPSILON));
	cr_assert(eq(flt, a->w, 1.0));
	cr_assert(ne(flt, a->w, 0.0));
	clean_obj(a);
}

Test(object_feature_test, test_the_object_is_a_vector)
{
	t_obj	*a = create_object(4.3, -4.2, 3.1, 0.0);

	cr_assert(epsilon_eq(flt, a->x, 4.3, EPSILON));
	cr_assert(epsilon_eq(flt, a->y, -4.2, EPSILON));
	cr_assert(epsilon_eq(flt, a->z, 3.1, EPSILON));
	cr_assert(eq(flt, a->w, 0.0));
	cr_assert(ne(flt, a->w, 1.0));
	clean_obj(a);
}

Test(object_point, test_the_if_function_point_create_a_point_object)
{
	t_obj	*res = create_point(4.0, -4.0, 3.0);
	t_obj	*exp = create_object(4.0, -4.0, 3.0, 1.0);

	cr_assert(cr_object_eq(res, exp));
	clean_obj(res);
	clean_obj(exp);
}

Test(object_vector, test_the_if_function_vector_create_a_vector_object)
{
	t_obj	*res = create_vector(4.0, -4.0, 3.0);
	t_obj	*exp = create_object(4.0, -4.0, 3.0, 0.0);

	cr_assert(cr_object_eq(res, exp));
	clean_obj(res);
	clean_obj(exp);
}

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

Test(object_operations, test_subtractions_two_objects_one_of_type_vector_and_another_of_type_point_should_be_a_point)
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