#include "unit_test.h"

# define __PATH_TEST_ "fd_test/%s.test"

Test(define_sphere_output, test_pass_a_incorrect_param_of_xyz_point_should_be_exit)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_sphere_error_01");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 21 - Invalid params format: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_sphere_output, test_pass_a_incorrect_number_of_params_should_be_exit)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_sphere_error_02");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 73 - Invalid quantity arguments: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_sphere_output, test_pass_a_green_color_with_a_value_minor_than_0)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_sphere_error_03");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 79 - Invalid color: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_sphere_output, test_pass_a_green_color_with_a_value_bigger_than_255)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_sphere_error_04");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 78 - Invalid color: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_sphere_output, test_pass_a_incorrect_diameter_param)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_sphere_error_05");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 33 - Number invalid: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_plane_output, test_pass_a_incorrect_param_of_xyz_point_should_be_exit)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_plane_error_01");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 21 - Invalid params format: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_plane_output, test_pass_a_green_color_with_a_value_minor_than_0)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_plane_error_02");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 79 - Invalid color: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_plane_output, test_pass_a_green_color_with_a_value_bigger_than_255)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_plane_error_03");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 78 - Invalid color: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_plane_output, test_pass_a_vector_with_a_param_x_minor_than_minus_1)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_plane_error_04");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 07 - Invalid value: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_plane_output, test_pass_a_vector_with_a_param_x_bigger_than_1)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_plane_error_05");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 07 - Invalid value: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_plane_output, test_pass_a_vector_with_a_param_y_minor_than_minus_1)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_plane_error_06");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 07 - Invalid value: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_plane_output, test_pass_a_vector_with_a_param_y_bigger_than_1)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_plane_error_07");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 07 - Invalid value: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_plane_output, test_pass_a_vector_with_a_param_z_minor_than_minus_1)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_plane_error_08");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 07 - Invalid value: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_plane_output, test_pass_a_vector_with_a_param_z_bigger_than_1)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_plane_error_09");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 07 - Invalid value: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_cylinder_output, test_pass_a_incorrect_param_of_xyz_point_should_be_exit)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cylinder_error_01");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 21 - Invalid params format: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_cylinder_output, test_pass_a_green_color_with_a_value_minor_than_0)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cylinder_error_02");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 79 - Invalid color: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_cylinder_output, test_pass_a_green_color_with_a_value_bigger_than_255)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cylinder_error_03");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 78 - Invalid color: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_cylinder_output, test_pass_a_vector_with_a_param_x_minor_than_minus_1)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cylinder_error_04");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 14 - Invalid value: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_cylinder_output, test_pass_a_vector_with_a_param_x_bigger_than_1)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cylinder_error_05");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 14 - Invalid value: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_cylinder_output, test_pass_a_vector_with_a_param_y_minor_than_minus_1)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cylinder_error_06");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 14 - Invalid value: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_cylinder_output, test_pass_a_vector_with_a_param_y_bigger_than_1)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cylinder_error_07");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 14 - Invalid value: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_cylinder_output, test_pass_a_vector_with_a_param_z_minor_than_minus_1)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cylinder_error_08");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 14 - Invalid value: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_cylinder_output, test_pass_a_vector_with_a_param_z_bigger_than_1)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cylinder_error_09");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 14 - Invalid value: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_cylinder_output, test_pass_more_params_thats_need)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cylinder_error_10");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 99 - Invalid quantity arguments: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_cylinder_output, test_pass_a_incorrect_param_for_diameter)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cylinder_error_11");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 31 - Invalid value: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}

Test(define_cylinder_output, test_pass_a_incorrect_param_for_height)
{
	char	output[1000] = {0};
	char	name[200] = {0};
	sprintf(name, __PATH_TEST_, "test_define_cylinder_error_12");
	int			fd = open(name, O_RDONLY);
	char		*expected = RED"Error\n"YELLOW"error code: 27 - Invalid value: Resource temporarily unavailable\n"RESET_COLORS;
	usleep(10000);
	read(fd, output, 1000);
	cr_assert_str_eq(expected, output, "value expected [ %s ], result [ %s ].\n", expected, output);
	unlink(name);
}