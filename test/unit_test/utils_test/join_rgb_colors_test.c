#include "unit_test.h"

Test(Join_RGB_Colors, red_0_green_0_blue_0)
{
    t_color color = fill_color(0, 0, 0);
    cr_expect(eq(str, join_rgb_colors(color), "000000"));
}

Test(Join_RGB_Colors, red_1_green_0_blue_0)
{
    t_color color = fill_color(1, 0, 0);
    cr_expect(eq(str, join_rgb_colors(color), "FF0000"));
}

Test(Join_RGB_Colors, red_0_green_1_blue_0)
{
    t_color color = fill_color(0, 1, 0);
    cr_expect(eq(str, join_rgb_colors(color), "00FF00"));
}

Test(Join_RGB_Colors, red_0_green_0_blue_1)
{
    t_color color = fill_color(0, 0, 1);
    cr_expect(eq(str, join_rgb_colors(color), "0000FF"));
}

Test(Join_RGB_Colors, red_1_green_1_blue_1)
{
    t_color color = fill_color(1, 1, 1);
    cr_expect(eq(str, join_rgb_colors(color), "FFFFFF"));
}

Test(Join_RGB_Colors, red_2_green_1_blue_1)
{
    t_color color = fill_color(2, 1, 1);
    cr_expect(eq(str, join_rgb_colors(color), "FFFFFF"));
}

Test(Join_RGB_Colors, red_1_green_2_blue_1)
{
    t_color color = fill_color(1, 2, 1);
    cr_expect(eq(str, join_rgb_colors(color), "FFFFFF"));
}

Test(Join_RGB_Colors, red_1_green_1_blue_2)
{
    t_color color = fill_color(1, 1, 2);
    cr_expect(eq(str, join_rgb_colors(color), "FFFFFF"));
}

Test(Join_RGB_Colors, red_minus_1_green_1_blue_2)
{
    t_color color = fill_color(-1, 1, 2);
    cr_expect(eq(str, join_rgb_colors(color), "00FFFF"));
}

Test(Join_RGB_Colors, red_minus_1_green_minus_1_blue_2)
{
    t_color color = fill_color(-1, -1, 2);
    cr_expect(eq(str, join_rgb_colors(color), "0000FF"));
}

Test(Join_RGB_Colors, red_minus_1_green_minus_1_blue_minus_1)
{
    t_color color = fill_color(-1, -1, -1);
    cr_expect(eq(str, join_rgb_colors(color), "000000"));
}

Test(Test, white_to_int)
{
    t_color color = fill_color(1, 1, 1);
    cr_expect(eq(int, hex_to_int(join_rgb_colors(color)), 16777215));
}

Test(Test, blue_to_int)
{
    t_color color = fill_color(0, 0, 1);
    cr_expect(eq(int, hex_to_int(join_rgb_colors(color)), 255));
}

Test(Test, green_to_int)
{
    t_color color = fill_color(0, 1, 0);
    cr_expect(eq(int, hex_to_int(join_rgb_colors(color)), 65280));
}

Test(Test, red_to_int)
{
    t_color color = fill_color(1, 0, 0);
    cr_expect(eq(int, hex_to_int(join_rgb_colors(color)), 16711680));
}

Test(Test, red_05_to_int)
{
    t_color color = fill_color(0.5, 0, 0);
    cr_expect(eq(int, hex_to_int(join_rgb_colors(color)), 8323072));
}

Test(Test, green_05_to_int)
{
    t_color color = fill_color(0, 0.5, 0);
    cr_expect(eq(int, hex_to_int(join_rgb_colors(color)), 32512));
}

Test(Test, blue_05_to_int)
{
    t_color color = fill_color(0, 0, 0.5);
    cr_expect(eq(int, hex_to_int(join_rgb_colors(color)), 127));
}
