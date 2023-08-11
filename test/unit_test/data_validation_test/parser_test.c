#include "unit_test.h"

# define __PATH_TEST_ "fd_test/%s.test"

void	create_file_test(int *fd, char *name, char *expected)
{
	char	path[300];
	// Create the file and input the text.
	sprintf(path, __PATH_TEST_, name);
	*fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO);
	if (write(*fd, expected, ft_strlen(expected)) == -1)
		printf("Your shall pass!\n");
	close(*fd);
}

void	open_filename(char *name, int *fd)
{
	char	path[300];
	// Open file
	sprintf(path, __PATH_TEST_, name);
	*fd = open(path, O_RDONLY);
}

void	delete_file_test(int *fd, char *name)
{
	char	path[300];
	// Delete file.
	close(*fd);
	sprintf(path, __PATH_TEST_, name);
	unlink(path);
}

Test(Parser, test_use_parser_line_for_make_pieces_of_a_plane_param)
{
	int			fd;
	char		*file_name = "plane";
	create_file_test(&fd, file_name, "pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225");
	open_filename(file_name, &fd);
	char		**result;
	char		*expected[] = {
								"pl",
								"0.0,0.0,-10.0",
								"0.0,1.0,0.0",
								"0,0,225"
							};

	result = parser_line(fd);

	for (int i = 0; i < 4; i++) {
		cr_assert_str_eq(result[i], expected[i], "value expected [ %s ], result [ %s ].\n", expected[i], result[i]);
	}
	delete_file_test(&fd, file_name);
	clean_array(result);
}

Test(Parser, test_use_parser_line_a_line_with_a_space_character)
{
	int			fd;
	char		*file_name = "space";
	create_file_test(&fd, file_name, " ");
	open_filename(file_name, &fd);
	char		**result;

	result = parser_line(fd);

	cr_assert_null(result[0], "Value is not NULL, result [ %p ].\n", result[0]);
	cr_assert_not_null(result, "Value is not NULL, result [ %p ].\n", result);
	delete_file_test(&fd, file_name);
	clean_array(result);
}

Test(Parser, test_use_parser_line_a_line_with_a_mult_spaces_character)
{
	int			fd;
	char		*file_name = "space";
	create_file_test(&fd, file_name, " \t       \t");
	open_filename(file_name, &fd);
	char		**result;

	result = parser_line(fd);

	cr_assert_null(result[0], "Value is not NULL, result [ %p ].\n", result[0]);
	cr_assert_not_null(result, "Value is not NULL, result [ %p ].\n", result);
	delete_file_test(&fd, file_name);
	clean_array(result);
}

// Test(Parser_valid_xyz, test_a_valid_string_xyz)
// {
// 	t_bool	is_valid;
// 	char	*str = "0.0,1.0,0.0";
// 	t_obj	expected = create_point(0, 1, 0);
// 	t_obj	result;

// 	result = convert_xyz(str, &is_valid);

// 	cr_assert(eq(is_valid, T));
// 	cr_assert(cr_object_eq(result, expected));
// }

// Test(Parser_valid_xyz, test_a_string_with_a_invalid_y_value_xyz)
// {
// 	t_bool	is_valid;
// 	char	*str = "0.0,A.0,0.0";
// 	t_obj	expected = create_point(0, 0, 0);
// 	t_obj	result;

// 	result = convert_xyz(str, &is_valid);

// 	cr_assert(eq(is_valid, F));
// 	cr_assert(cr_object_eq(result, expected));
// }

// Test(Parser_valid_xyz, test_a_string_with_a_invalid_x_value_xyz)
// {
// 	t_bool	is_valid;
// 	char	*str = "0.B,0.0,0.0";
// 	t_obj	expected = create_point(0, 0, 0);
// 	t_obj	result;

// 	result = convert_xyz(str, &is_valid);

// 	cr_assert(eq(is_valid, F));
// 	cr_assert(cr_object_eq(result, expected));
// }

// Test(Parser_valid_xyz, test_a_string_with_a_invalid_z_value_xyz)
// {
// 	t_bool	is_valid;
// 	char	*str = "0.0,0.0,0.&";
// 	t_obj	expected = create_point(0, 0, 0);
// 	t_obj	result;

// 	result = convert_xyz(str, &is_valid);

// 	cr_assert(eq(is_valid, F));
// 	cr_assert(cr_object_eq(result, expected));
// }

// Test(Parser_valid_xyz, test_a_string_with_more_params_xyz)
// {
// 	t_bool	is_valid;
// 	char	*str = "0.0,0.0,0.0,0.1";
// 	t_obj	expected = create_point(0, 0, 0);
// 	t_obj	result;

// 	result = convert_xyz(str, &is_valid);

// 	cr_assert(eq(is_valid, F));
// 	cr_assert(cr_object_eq(result, expected));
// }

// Test(Parser_valid_xyz, test_a_string_with_minus_params_xyz)
// {
// 	t_bool	is_valid;
// 	char	*str = "0.0,0.0";
// 	t_obj	expected = create_point(0, 0, 0);
// 	t_obj	result;

// 	result = convert_xyz(str, &is_valid);

// 	cr_assert(eq(is_valid, F));
// 	cr_assert(cr_object_eq(result, expected));
// }

// Test(Parser_valid_xyz, test_a_string_with_a_big_x_value_params_xyz)
// {
// 	t_bool	is_valid;
// 	char	*str = "7798797985454.654646544564,0.0,0.0";
// 	t_obj	expected = create_point(7798797985454.654646544564, 0, 0);
// 	t_obj	result;

// 	result = convert_xyz(str, &is_valid);

// 	cr_assert(eq(is_valid, T));
// 	cr_assert(cr_object_eq(result, expected));
// }

// Test(Parser_valid_xyz, test_valid_3d_normalized_with_a_big_x_value)
// {
// 	t_bool	is_valid;
// 	char	*str = "7798797985454.654646544564,0.0,0.0";
// 	t_obj	expected = create_vector(0, 0, 0);
// 	t_obj	result;

// 	result = convert_3d_normalized(str, &is_valid);

// 	cr_assert(eq(is_valid, F));
// 	cr_assert(cr_object_eq(result, expected));
// }

// Test(Parser_valid_xyz, test_valid_3d_normalized_with_valid_values)
// {
// 	t_bool	is_valid;
// 	char	*str = "0.99,0.0,0.0";
// 	t_obj	expected = create_vector(0.99, 0, 0);
// 	t_obj	result;

// 	result = convert_3d_normalized(str, &is_valid);

// 	cr_assert(eq(is_valid, T));
// 	cr_assert(cr_object_eq(result, expected));
// }

// Test(Parser, test_read_a_file_with_a_plane_declaration)
// {
// 	int	fd;
// 	char				*file_name = "plane_shape";
// 	create_file_test(&fd, file_name, "pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225");
// 	open_filename(file_name, &fd);
// 	t_lst				*expected = NULL;
// 	ft_lstadd_back(&expected, ft_lstnew(new_plane()));
// 	expected->shape.id = plane;
// 	expected->shape.any->x = 0;
// 	expected->shape.any->y = 0;
// 	expected->shape.any->z = -10;
// 	expected->shape.any->material.color = fill_color(0, 0, 1);
// 	t_lst				*result;

// 	result = define_shape(fd, &result);

// 	cr_assert(eq(result.type, (t_object_type)plane));
// 	cr_assert(cr_object_eq(expected.point, result.point));
// 	cr_assert(cr_object_eq(expected.vector, result.vector));
// 	cr_assert(cr_color_eq(expected.rgb, result.rgb));
// 	delete_file_test(&fd, file_name);
// }