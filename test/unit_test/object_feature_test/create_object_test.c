#include "unit_test.h"

Test(object_feature_test, test_the_object_is_a_point)
{
	t_obj	a = create_object(4.3, -4.2, 3.1, 1.0);

	cr_assert(epsilon_eq(flt, a.x, 4.3, EPSILON));
	cr_assert(epsilon_eq(flt, a.y, -4.2, EPSILON));
	cr_assert(epsilon_eq(flt, a.z, 3.1, EPSILON));
	cr_assert(eq(flt, a.w, 1.0));
	cr_assert(ne(flt, a.w, 0.0));
}

Test(object_feature_test, test_the_object_is_a_vector)
{
	t_obj	a = create_object(4.3, -4.2, 3.1, 0.0);

	cr_assert(epsilon_eq(flt, a.x, 4.3, EPSILON));
	cr_assert(epsilon_eq(flt, a.y, -4.2, EPSILON));
	cr_assert(epsilon_eq(flt, a.z, 3.1, EPSILON));
	cr_assert(eq(flt, a.w, 0.0));
	cr_assert(ne(flt, a.w, 1.0));
}

Test(object_point, test_the_if_function_point_create_a_point_object)
{
	t_obj	res = create_point(4.0, -4.0, 3.0);
	t_obj	exp = create_object(4.0, -4.0, 3.0, 1.0);

	cr_assert(cr_object_eq(res, exp));
}

Test(object_vector, test_the_if_function_vector_create_a_vector_object)
{
	t_obj	res = create_vector(4.0, -4.0, 3.0);
	t_obj	exp = create_object(4.0, -4.0, 3.0, 0.0);

	cr_assert(cr_object_eq(res, exp));
}
