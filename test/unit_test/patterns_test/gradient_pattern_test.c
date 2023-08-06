#include "unit_test.h"

Test(Gradient_pattern, A_gradient_linearly_interpolates_between_colors)
{
	t_pattern	pattern = gradient_pattern(fill_color(1, 1, 1), fill_color(0, 0, 0));

	cr_expect(cr_color_eq(gradient_at(pattern, create_point(0, 0, 0)), fill_color(1, 1, 1)));
	cr_expect(cr_color_eq(gradient_at(pattern, create_point(0.25, 0, 0)), fill_color(0.75, 0.75, 0.75)));
	cr_expect(cr_color_eq(gradient_at(pattern, create_point(0.5, 0, 0)), fill_color(0.5, 0.5, 0.5)));
	cr_expect(cr_color_eq(gradient_at(pattern, create_point(0.75, 0, 0)), fill_color(0.25, 0.25, 0.25)));
}
