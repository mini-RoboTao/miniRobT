#include "unit_test.h"

Test(Ring_pattern, A_ring_should_extend_in_both_x_and_z)
{
	t_pattern	pattern = ring_pattern(fill_color(1, 1, 1), fill_color(0, 0, 0));

	cr_expect(cr_color_eq(ring_at(pattern, create_point(0, 0, 0)), fill_color(1, 1, 1)));
	cr_expect(cr_color_eq(ring_at(pattern, create_point(1, 0, 0)), fill_color(0, 0, 0)));
	cr_expect(cr_color_eq(ring_at(pattern, create_point(0, 0, 1)), fill_color(0, 0, 0)));
	cr_expect(cr_color_eq(ring_at(pattern, create_point(0.708, 0.708, 0.708)), fill_color(0, 0, 0)));
}
