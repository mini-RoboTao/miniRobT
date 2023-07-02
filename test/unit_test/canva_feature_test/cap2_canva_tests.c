#include <unit_test.h>

Test(Canvas, creating_a_canvas)
{
	t_canvas *c = generate_canvas(10, 20);

	cr_expect(c->width == 10, "Expected width is 10");
	cr_expect(c->height == 20, "Expected height is 20");
	for (int w = 0; w < c->width; w++)
	{
		for (int h = 0; h < c->height; h++)
		{
			cr_expect(c->canvas[w][h].red == 0);
			cr_expect(c->canvas[w][h].green == 0);
			cr_expect(c->canvas[w][h].blue == 0);
			cr_expect(c->canvas[w][h].red != 1);
			cr_expect(c->canvas[w][h].green != 1);
			cr_expect(c->canvas[w][h].blue != 1);
		}
	}
}

Test(Canvas, writing_red_pixel_to_a_canvas)
{
	t_canvas *c = generate_canvas(10, 20);
	t_color red = fill_color(1, 0, 0);
	write_pixel(c, 2, 3, red);

	cr_expect(c->canvas[2][3].red == 1 && c->canvas[2][3].green == 0 && c->canvas[2][3].blue == 0);
}

Test(Canvas, writing_green_pixel_to_a_canvas)
{
	t_canvas *c = generate_canvas(10, 20);
	t_color green = fill_color(0, 1, 0);
	write_pixel(c, 2, 3, green);

	cr_expect(c->canvas[2][3].red == 0 && c->canvas[2][3].green == 1 && c->canvas[2][3].blue == 0);
}

Test(Canvas, writing_white_pixel_to_a_canvas)
{
	t_canvas *c = generate_canvas(10, 20);
	t_color white = fill_color(1, 1, 1);
	write_pixel(c, 2, 3, white);

	cr_expect(c->canvas[2][3].red == 1 && c->canvas[2][3].green == 1 && c->canvas[2][3].blue == 1);
}

Test(Canvas, writing_float_pixel_to_a_canvas)
{
	t_canvas *c = generate_canvas(10, 20);
	t_color gray = fill_color(0.8, 0.8, 0.8);
	write_pixel(c, 2, 3, gray);

	cr_expect(c->canvas[2][3].red == 0.8 && c->canvas[2][3].green == 0.8 && c->canvas[2][3].blue == 0.8);
}
