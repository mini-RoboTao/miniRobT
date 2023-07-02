#include <unit_test.h>

Test(Colors, colors_are_red_green_blue_tuples)
{
	t_color color = fill_color(-0.5, 0.4, 1.7);

	cr_expect(color.red == -0.5, "Expected red has a -0.5 value");
	cr_expect(color.green == 0.4, "Expected green has a 0.4 value");
	cr_expect(color.blue == 1.7, "Expected blue has a 1.7 value");
}

Test(Colors, adding_colors)
{
	t_color c1 = fill_color(0.9, 0.6, 0.75);
	t_color c2 = fill_color(0.7, 0.1, 0.25);
	t_color c_res = sum_colors(c1, c2);

	cr_expect(c_res.red == 1.6, "Expected red has a 1.6 value");
	cr_expect(c_res.green == 0.7, "Expected green has a 0.7 value");
	cr_expect(c_res.blue == 1.0, "Expected blue has a 1.0 value");
}

Test(Colors, subtracting_colors)
{
	t_color c1 = fill_color(0.9, 0.6, 0.75);
	t_color c2 = fill_color(0.7, 0.1, 0.25);
	t_color c_res = subtract_colors(c1, c2);

	cr_expect(c_res.red == 0.9 - 0.7, "Expected red has a 0.2 value");
	cr_expect(c_res.green == 0.5, "Expected green has a 0.5 value");
	cr_expect(c_res.blue == 0.5, "Expected blue has a 0.5 value");
}

Test(Colors, multiplying_a_color_by__a_scalar)
{
	t_color c1 = fill_color(0.2, 0.3, 0.4);
	t_color c_res = multiply_scalar_colors(c1, 2);

	cr_expect(c_res.red == 0.4, "Expected red has a 0.4 value");
	cr_expect(c_res.green == 0.6, "Expected green has a 0.6 value");
	cr_expect(c_res.blue == 0.8, "Expected blue has a 0.8 value");
}

Test(Colors, multiplying_colors)
{
	t_color c1 = fill_color(1, 0.2, 0.4);
	t_color c2 = fill_color(0.9, 1, 0.1);
	t_color c_res = multiply_colors(c1, c2);

	cr_expect(c_res.red == 0.9, "Expected red has a 0.9 value");
	cr_expect(c_res.green == 0.2, "Expected green has a 0.2 value");
	cr_expect(c_res.blue == 0.4 * 0.1, "Expected blue has a 0.04 value");
}