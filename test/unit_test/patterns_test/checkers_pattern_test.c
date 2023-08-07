#include "unit_test.h"

Test(Checkers_pattern, Checkers_should_repeat_in_x)
{
	t_pattern	pattern = checkers_pattern(fill_color(1, 1, 1), fill_color(0, 0, 0));

	cr_expect(cr_color_eq(pattern_at(pattern, create_point(0, 0, 0)), fill_color(1, 1, 1)));
	cr_expect(cr_color_eq(pattern_at(pattern, create_point(0.99, 0, 0)), fill_color(1, 1, 1)));
	cr_expect(cr_color_eq(pattern_at(pattern, create_point(1.01, 0, 0)), fill_color(0, 0, 0)));
}

Test(Checkers_pattern, Checkers_should_repeat_in_y)
{
	t_pattern	pattern = checkers_pattern(fill_color(1, 1, 1), fill_color(0, 0, 0));

	cr_expect(cr_color_eq(pattern_at(pattern, create_point(0, 0, 0)), fill_color(1, 1, 1)));
	cr_expect(cr_color_eq(pattern_at(pattern, create_point(0, 0.99, 0)), fill_color(1, 1, 1)));
	cr_expect(cr_color_eq(pattern_at(pattern, create_point(0, 1.01, 0)), fill_color(0, 0, 0)));
}

Test(Checkers_pattern, Checkers_should_repeat_in_z)
{
	t_pattern	pattern = checkers_pattern(fill_color(1, 1, 1), fill_color(0, 0, 0));

	cr_expect(cr_color_eq(pattern_at(pattern, create_point(0, 0, 0)), fill_color(1, 1, 1)));
	cr_expect(cr_color_eq(pattern_at(pattern, create_point(0, 0, 0.99)), fill_color(1, 1, 1)));
	cr_expect(cr_color_eq(pattern_at(pattern, create_point(0, 0, 1.01)), fill_color(0, 0, 0)));
}
