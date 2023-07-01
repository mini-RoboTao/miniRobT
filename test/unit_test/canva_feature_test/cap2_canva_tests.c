#include "unit_test.h"

Test(Canvas, creating_a_canvas)
{
	c = canvas(10, 20);

	cr_expect(c.width == 10, "Expected width is 10");
	cr_expect(c.height == 20, "Expected height is 20");
	for (int w = 0; w < c.width; w++)
	{
		for (int h = 0; h < c.height; h++)
		{
			cr_expect(c.canvas[w][h].red == 0);
			cr_expect(c.canvas[w][h].green == 0);
			cr_expect(c.canvas[w][h].blue == 0);
		}
	}
}

Test(Canvas, writing_pixels_to_a_canvas)
{
	c = canvas(10,20);
	red = fill_color(1, 0, 0);
	write_pixel(c, 2, 3, red);

	cr_expect(c.canvas[2][3].red == 1 && c.canvas[2][3].green == 0 && c.canvas[2][3].blue == 0);
}