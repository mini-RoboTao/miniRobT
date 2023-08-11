#include "unit_test.h"

Test(RGB_Validate, valid_min_params)
{
	char	*input = "0,0,0";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(cr_color_eq(rgb, fill_color(0, 0, 0)));
}

Test(RGB_Validate, valid_max_params)
{
	char	*input = "255,255,255";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(cr_color_eq(rgb, fill_color(1, 1, 1)));
}

Test(RGB_Validate, invalid__1st_params)
{
	char	*input = "a0,0,0";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(eq(is_valid, F));
	cr_assert(cr_color_eq(rgb, fill_color(0, 0, 0)));
}

Test(RGB_Validate, invalid_2nd_params)
{
	char	*input = "0,a0,0";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(eq(is_valid, F));
	cr_assert(cr_color_eq(rgb, fill_color(0, 0, 0)));
}

Test(RGB_Validate, invalid_3rd_params)
{
	char	*input = "0,0,a0";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(eq(is_valid, F));
	cr_assert(cr_color_eq(rgb, fill_color(0, 0, 0)));
}

Test(RGB_Validate, negative_1st_params)
{
	char	*input = "-1,0,0";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(eq(is_valid, F));
	cr_assert(cr_color_eq(rgb, fill_color(0, 0, 0)));
}

Test(RGB_Validate, negative_2nd_params)
{
	char	*input = "0,-1,0";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(eq(is_valid, F));
	cr_assert(cr_color_eq(rgb, fill_color(0, 0, 0)));
}

Test(RGB_Validate, negative_3rd_params)
{
	char	*input = "0,0,-1";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(eq(is_valid, F));
	cr_assert(cr_color_eq(rgb, fill_color(0, 0, 0)));
}

Test(RGB_Validate, overflow_1st_params)
{
	char	*input = "256,0,0";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(eq(is_valid, F));
	cr_assert(cr_color_eq(rgb, fill_color(-1, 0, 0)));
}

Test(RGB_Validate, overflow_2nd_params)
{
	char	*input = "0,256,0";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(eq(is_valid, F));
	cr_assert(cr_color_eq(rgb, fill_color(0, -1, 0)));
}

Test(RGB_Validate, overflow_3rd_params)
{
	char	*input = "0,0,256";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(eq(is_valid, F));
	cr_assert(cr_color_eq(rgb, fill_color(0, 0, -1)));
}

Test(RGB_check_conversion, white)
{
	char	*input = "255,255,255";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(eq(is_valid, T));
	cr_assert(cr_color_eq(rgb, fill_color(1, 1, 1)));
}

Test(RGB_check_conversion, black)
{
	char	*input = "0,0,0";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(eq(is_valid, T));
	cr_assert(cr_color_eq(rgb, fill_color(0, 0, 0)));
}

Test(RGB_check_conversion, red)
{
	char	*input = "255,0,0";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(eq(is_valid, T));
	cr_assert(cr_color_eq(rgb, fill_color(1, 0, 0)));
}

Test(RGB_check_conversion, green)
{
	char	*input = "0,255,0";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(eq(is_valid, T));
	cr_assert(cr_color_eq(rgb, fill_color(0, 1, 0)));
}

Test(RGB_check_conversion, blue)
{
	char	*input = "0,0,255";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(eq(is_valid, T));
	cr_assert(cr_color_eq(rgb, fill_color(0, 0, 1)));
}

Test(RGB_check_conversion, gray)
{
	char	*input = "127,127,127";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(eq(is_valid, T));
	cr_assert(cr_color_eq(rgb, fill_color(0.4980392157, 0.4980392157, 0.4980392157)));
}

Test(RGB_check_conversion, half_red)
{
	char	*input = "127,0,0";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(eq(is_valid, T));
	cr_assert(cr_color_eq(rgb, fill_color(0.4980392157, 0, 0)));
}

Test(RGB_check_conversion, half_green)
{
	char	*input = "0,127,0";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(eq(is_valid, T));
	cr_assert(cr_color_eq(rgb, fill_color(0, 0.4980392157, 0)));
}

Test(RGB_check_conversion, half_blue)
{
	char	*input = "0,0,127";
	t_color	rgb;

	t_bool	is_valid;

	rgb = convert_to_rgb(input, &is_valid);

	cr_assert(eq(is_valid, T));
	cr_assert(cr_color_eq(rgb, fill_color(0, 0, 0.4980392157)));
}
