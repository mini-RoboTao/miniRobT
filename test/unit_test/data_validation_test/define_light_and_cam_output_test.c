#include "unit_test.h"

# define __PATH_TEST_ "fd_test/%s.test"

Test(define_camera_output, test_output_of_pass_a_incorrect_param_of_xyz_point)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_01");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 21 - Invalid params format: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_camera_output, test_pass_a_param_fov_with_a_minor_value)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_02");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 24 - Number invalid: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_camera_output, test_pass_a_param_fov_with_a_bigger_value)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_03");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 24 - Number invalid: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_camera_output, test_pass_a_param_vector_with_a_x_bigger_them_1_value)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_04");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 10 - Invalid param: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_camera_output, test_pass_a_param_vector_with_a_x_minor_them_minus_1_value)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_05");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 10 - Invalid param: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_camera_output, test_pass_a_param_vector_with_a_y_bigger_them_1_value)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_06");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 10 - Invalid param: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_camera_output, test_pass_a_param_vector_with_a_y_minor_them_minus_1_value)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_07");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 10 - Invalid param: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_camera_output, test_pass_a_param_vector_with_a_z_bigger_them_1_value)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_08");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 10 - Invalid param: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_camera_output, test_pass_a_param_vector_with_a_z_minor_them_minus_1_value)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_09");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 10 - Invalid param: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_camera_output, test_pass_a_invalid_number_of_params)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_10");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"erro code: 11 - Invalid quantity arguments: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_light_output, test_pass_a_incorrect_param_to_point)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_11");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 21 - Invalid params format: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_light_output, test_pass_a_brightness_bigger_them_1)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_12");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 98 - Number out of range: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_light_output, test_pass_a_brightness_minor_them_0)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_13");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 98 - Number out of range: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_light_output, test_pass_a_rgb_value_minor_them_0)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_14");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 79 - Invalid color: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_light_output, test_pass_a_rgb_value_bigger_them_255)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_15");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 78 - Invalid color: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_light_output, test_pass_a_rgb_without_color_green)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_16");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 79 - Invalid color: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_light_output, test_without_one_param_of_light)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_17");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 60 - Invalid quantity arguments: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_ambient_light_output, test_pass_intensity_bigger_them_1)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_18");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 97 - Number out of range: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_ambient_light_output, test_pass_intensity_minor_them_0)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_19");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 97 - Number out of range: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_ambient_light_output, test_pass_a_rgb_value_minor_them_0)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_20");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 79 - Invalid color: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_ambient_light_output, test_pass_a_rgb_value_bigger_them_255)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_21");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 78 - Invalid color: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_ambient_light_output, test_pass_a_rgb_without_color_green)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_22");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 79 - Invalid color: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_ambient_light_output, test_without_one_param_of_light)
{
	char	output[1000] = {0};
	char	name[300] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cam_error_23");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 57 - Invalid quantity arguments: Resource temporarily unavailable\n"RESET_COLORS;
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}
