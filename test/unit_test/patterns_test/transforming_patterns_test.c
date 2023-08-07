#include "unit_test.h"

Test(Transforming_patterns, Stripes_with_an_object_transformation)
{
	t_shape		sphere = new_sphere();
	t_pattern	pattern = stripe_pattern(fill_color(1, 1, 1), fill_color(0, 0, 0));

	set_transform(&sphere, scaling(2, 2, 2));

	t_color		c = pattern_at_shape(&pattern, sphere, create_point(1.5, 0, 0));

	cr_assert(cr_color_eq(c, fill_color(1, 1, 1)));
	clean_shape(&sphere);
}

Test(Transforming_patterns, Stripes_with_a_pattern_transformation)
{
	t_shape		sphere = new_sphere();
	t_pattern	pattern = stripe_pattern(fill_color(1, 1, 1), fill_color(0, 0, 0));

	set_pattern_transform(&pattern, scaling(2, 2, 2));

	t_color		c = pattern_at_shape(&pattern, sphere, create_point(1.5, 0, 0));

	cr_assert(cr_color_eq(c, fill_color(1, 1, 1)));
	clean_shape(&sphere);
}

Test(Transforming_patterns, Stripes_with_both_an_object_and_a_pattern_transformation)
{
	t_shape		sphere = new_sphere();
	t_pattern	pattern = stripe_pattern(fill_color(1, 1, 1), fill_color(0, 0, 0));

	set_transform(&sphere, scaling(2, 2, 2));
	set_pattern_transform(&pattern, translation(0.5, 0, 0));

	t_color		c = pattern_at_shape(&pattern, sphere, create_point(2.5, 0, 0));

	cr_assert(cr_color_eq(c, fill_color(1, 1, 1)));
	clean_shape(&sphere);
}
