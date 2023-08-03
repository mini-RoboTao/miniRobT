#include "unit_test.h"

Test(Reflecting_vectors, Reflecting_a_vector_approaching_at_45_degree)
{
	t_obj	vector = create_vector(1, -1, 0);
	t_obj	n = create_vector(0, 1, 0);
	t_obj	r = reflect(vector, n);
	t_obj	res = create_vector(1, 1, 0);

	cr_assert(cr_object_eq(r, res));
}

Test(Reflecting_vector, Reflecting_a_vector_off_a_slanted_surface)
{
	t_obj	vector = create_vector(0, -1, 0);
	t_obj	n = create_vector(sqrt(2)/2, sqrt(2)/2, 0);
	t_obj	r = reflect(vector, n);
	t_obj	res = create_vector(1, 0, 0);

	cr_assert(cr_object_eq(r, res));
}