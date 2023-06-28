#include "criterion-2.4.2/include/criterion/criterion.h"
#include "criterion-2.4.2/include/criterion/new/assert.h"
#include "../src/include/object_feature.h"
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
