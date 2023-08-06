#include "unit_test.h"

Test(Generalizing_patterns, The_default_patterns_transformation)
{
	t_pattern	pattern = test_pattern();

	cr_assert(cr_matrix_eq(pattern.transform, create_identity_matrix()));
}

Test(Generalizing_patterns, Assigning_a_transformation)
{
	t_pattern	pattern = test_pattern();

	set_pattern_transform(&pattern, translation(1, 2, 3));
	cr_assert(cr_matrix_eq(pattern.transform, translation(1, 2, 3)));
}

Test(Generalizing_patterns, A_pattern_with_an_object_transformation)
{
	t_shape		shape = new_sphere();
	t_pattern	pattern = test_pattern();

	set_transform(&shape, scaling(2, 2, 2));
	t_color		c = pattern_at_shape(&pattern, shape, create_point(2, 3, 4));
	cr_expect(cr_color_eq(c, fill_color(1, 1.5, 2)));
	clean_shape(&shape);
}

Test(Generalizing_patterns, A_pattern_with_a_pattern_transformation)
{
	t_shape		shape = new_sphere();
	t_pattern	pattern = test_pattern();

	set_pattern_transform(&pattern, scaling(2, 2, 2));
	t_color		c = pattern_at_shape(&pattern, shape, create_point(2, 3, 4));
	cr_expect(cr_color_eq(c, fill_color(1, 1.5, 2)));
	clean_shape(&shape);
}

Test(Generalizing_patterns, A_pattern_with_both_an_object_and_a_pattern_transformation)
{
	t_shape		shape = new_sphere();
	t_pattern	pattern = test_pattern();

	set_transform(&shape, scaling(2, 2, 2));
	set_pattern_transform(&pattern, translation(0.5, 1, 1.5));
	t_color		c = pattern_at_shape(&pattern, shape, create_point(2.5, 3, 3.5));
	cr_expect(cr_color_eq(c, fill_color(0.75, 0.5, 0.25)));
	clean_shape(&shape);
}
