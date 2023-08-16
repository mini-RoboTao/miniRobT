#include "unit_test.h"

# define __PATH_TEST_ "fd_test/%s.test"
# define COLOUR_PERCNT 1.0 / 256.0

void	file_test(int *fd, char *name)
{
	char	path[300] = {0};
	// Create the file and input the text.
	sprintf(path, __PATH_TEST_, name);
	*fd = open(path, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO);
}

void	set_world(t_world *w)
{
	file_test(&w->fd, "test_define_cam");
}

void	set_output(int *fd, char *name)
{
	char	path[300] = {0};
	sprintf(path, __PATH_TEST_, name);
	*fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO);
	dup2(*fd, 2);
}

void	unset_output(int *fd, int *bkp)
{
	dup2(*bkp, 2);
	close(*fd);
}

Test(define_sphere, test_a_valid_sphere)
{
	t_world			world = (t_world){0};
	t_define_sphere	result;
	char			*params[] = {
					"sp",
					"0.0,0.0,20.6",
					"12.6",
					"10,0,255",
					NULL		};
	t_define_sphere	expected = {
					.point = (t_obj){0.0, 0.0, 20.6, 1},
					.diameter = 12.6,
					.material = {
						.color = (t_color){ COLOUR_PERCNT * 10, COLOUR_PERCNT * 0, COLOUR_PERCNT * 255} }};

	result = define_sphere(params, &world);

	cr_assert(cr_object_eq(expected.point, result.point));
	cr_assert(epsilon_eq(flt, expected.diameter, result.diameter, EPSILON));
	cr_assert(epsilon_eq(flt, expected.material.color.red, result.material.color.red, EPSILON));
	cr_assert(epsilon_eq(flt, expected.material.color.green, result.material.color.green, EPSILON));
	cr_assert(epsilon_eq(flt, expected.material.color.blue, result.material.color.blue, EPSILON));
}

Test(define_sphere, test_pass_a_incorrect_param_of_xyz_point_should_be_exit, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_sphere	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("sp -50.0,0 12.6 10,0,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_sphere_error_01");
	result = define_sphere(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_sphere, test_pass_a_incorrect_number_of_params_should_be_exit, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_sphere	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("sp -50.0,0,10 12.6 10,0,255 0", ' ');

	set_world(&world);
	set_output(&fd, "test_define_sphere_error_02");
	result = define_sphere(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_sphere, test_pass_a_green_color_with_a_value_minor_than_0, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_sphere	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("sp -50.0,0,10 12.6 10,-42,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_sphere_error_03");
	result = define_sphere(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_sphere, test_pass_a_green_color_with_a_value_bigger_than_255, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_sphere	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("sp -50.0,0,10 12.6 422,52,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_sphere_error_04");
	result = define_sphere(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_sphere, test_pass_a_incorrect_diameter_param, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_sphere	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("sp -50.0,0,10 A.6 10,0,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_sphere_error_05");
	result = define_sphere(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_plane, test_a_valid_plane)
{
	t_world			world = (t_world){0};
	t_define_plane	result;
	char			*params[] = {
					"pl",
					"0.0,0.0,-10.0",
					"0,1,0",
					"10,0,255",
					NULL		};
	t_define_plane	expected = {
					.point = (t_obj){0.0, 0.0, -10.0, 1},
					.vector = (t_obj){0, 1, 0, 0},
					.material = {
						.color = (t_color){ COLOUR_PERCNT * 10, COLOUR_PERCNT * 0, COLOUR_PERCNT * 255} }};

	result = define_plane(params, &world);

	cr_assert(cr_object_eq(expected.point, result.point));
	cr_assert(cr_object_eq(expected.vector, result.vector));
	cr_assert(epsilon_eq(flt, expected.material.color.red, result.material.color.red, EPSILON));
	cr_assert(epsilon_eq(flt, expected.material.color.green, result.material.color.green, EPSILON));
	cr_assert(epsilon_eq(flt, expected.material.color.blue, result.material.color.blue, EPSILON));
}

Test(define_plane, test_pass_a_incorrect_param_of_xyz_point_should_be_exit, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_plane	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("pl -50.0,,0 0,1,0 10,0,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_plane_error_01");
	result = define_plane(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_plane, test_pass_a_green_color_with_a_value_minor_than_0, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_plane	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("pl -50.0,0,0 0,1,0 10,-42,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_plane_error_02");
	result = define_plane(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_plane, test_pass_a_green_color_with_a_value_bigger_than_255, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_plane	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("pl -50.0,0,0 0,1,0 10,256,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_plane_error_03");
	result = define_plane(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_plane, test_pass_a_vector_with_a_param_x_minor_than_minus_1, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_plane	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("pl -50.0,0,0 -1.1,0,0 10,253,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_plane_error_04");
	result = define_plane(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_plane, test_pass_a_vector_with_a_param_x_bigger_than_1, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_plane	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("pl -50.0,0,0 1.1,0,0 10,253,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_plane_error_05");
	result = define_plane(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_plane, test_pass_a_vector_with_a_param_y_minor_than_minus_1, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_plane	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("pl -50.0,0,0 0,-1.1,0 10,253,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_plane_error_06");
	result = define_plane(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_plane, test_pass_a_vector_with_a_param_y_bigger_than_1, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_plane	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("pl -50.0,0,0 0,1.1,0 10,253,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_plane_error_07");
	result = define_plane(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_plane, test_pass_a_vector_with_a_param_z_minor_than_minus_1, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_plane	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("pl -50.0,0,0 0,0,-1.2 10,253,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_plane_error_08");
	result = define_plane(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_plane, test_pass_a_vector_with_a_param_z_bigger_than_1, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_plane	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("pl -50.0,0,0 0,0,1.2 10,253,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_plane_error_09");
	result = define_plane(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_cylinder, test_a_valid_cylinder)
{
	t_world				world = (t_world){0};
	t_define_cylinder	result;
	char				*params[] = {
						"cy",
						"50.0,0.0,20.6",
						"0,0,1.0",
						"14.2",
						"21.42",
						"10,0,255",
						NULL		};
	t_define_cylinder	expected = {
						.point = (t_obj){50.0, 0.0, 20.6, 1},
						.vector = (t_obj){0, 0, 1, 0},
						.diameter = 14.2,
						.height = 21.42,
						.material = {
							.color = (t_color){ COLOUR_PERCNT * 10, COLOUR_PERCNT * 0, COLOUR_PERCNT * 255} }};

	result = define_cylinder(params, &world);

	cr_assert(cr_object_eq(expected.point, result.point));
	cr_assert(cr_object_eq(expected.vector, result.vector));
	cr_assert(epsilon_eq(flt, expected.height, result.height, EPSILON));
	cr_assert(epsilon_eq(flt, expected.diameter, result.diameter, EPSILON));
	cr_assert(epsilon_eq(flt, expected.material.color.red, result.material.color.red, EPSILON));
	cr_assert(epsilon_eq(flt, expected.material.color.green, result.material.color.green, EPSILON));
	cr_assert(epsilon_eq(flt, expected.material.color.blue, result.material.color.blue, EPSILON));
}

Test(define_cylinder, test_pass_a_incorrect_param_of_xyz_point_should_be_exit, .exit_code = 42)
{
	int					fd;
	int					fd_bkp = dup(2);
	t_define_cylinder	result;
	t_world				world = (t_world){0};
	char				**params = ft_split("pl -50.0,,0 0,1,0 14.2 21.42 10,0,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cylinder_error_01");
	result = define_cylinder(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_cylinder, test_pass_a_green_color_with_a_value_minor_than_0, .exit_code = 42)
{
	int					fd;
	int					fd_bkp = dup(2);
	t_define_cylinder	result;
	t_world				world = (t_world){0};
	char				**params = ft_split("pl -50.0,0,0 0,1,0 14.2 21.42 10,-42,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cylinder_error_02");
	result = define_cylinder(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_cylinder, test_pass_a_green_color_with_a_value_bigger_than_255, .exit_code = 42)
{
	int					fd;
	int					fd_bkp = dup(2);
	t_define_cylinder	result;
	t_world				world = (t_world){0};
	char				**params = ft_split("pl -50.0,0,0 0,1,0 14.2 21.42 10,256,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cylinder_error_03");
	result = define_cylinder(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_cylinder, test_pass_a_vector_with_a_param_x_minor_than_minus_1, .exit_code = 42)
{
	int					fd;
	int					fd_bkp = dup(2);
	t_define_cylinder	result;
	t_world				world = (t_world){0};
	char				**params = ft_split("pl -50.0,0,0 -1.1,0,0 14.2 21.42 10,253,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cylinder_error_04");
	result = define_cylinder(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_cylinder, test_pass_a_vector_with_a_param_x_bigger_than_1, .exit_code = 42)
{
	int					fd;
	int					fd_bkp = dup(2);
	t_define_cylinder	result;
	t_world				world = (t_world){0};
	char				**params = ft_split("pl -50.0,0,0 1.1,0,0 14.2 21.42 10,253,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cylinder_error_05");
	result = define_cylinder(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_cylinder, test_pass_a_vector_with_a_param_y_minor_than_minus_1, .exit_code = 42)
{
	int					fd;
	int					fd_bkp = dup(2);
	t_define_cylinder	result;
	t_world				world = (t_world){0};
	char				**params = ft_split("pl -50.0,0,0 0,-1.1,0 14.2 21.42 10,253,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cylinder_error_06");
	result = define_cylinder(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_cylinder, test_pass_a_vector_with_a_param_y_bigger_than_1, .exit_code = 42)
{
	int					fd;
	int					fd_bkp = dup(2);
	t_define_cylinder	result;
	t_world				world = (t_world){0};
	char				**params = ft_split("pl -50.0,0,0 0,1.1,0 14.2 21.42 10,253,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cylinder_error_07");
	result = define_cylinder(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_cylinder, test_pass_a_vector_with_a_param_z_minor_than_minus_1, .exit_code = 42)
{
	int					fd;
	int					fd_bkp = dup(2);
	t_define_cylinder	result;
	t_world				world = (t_world){0};
	char				**params = ft_split("pl -50.0,0,0 0,0,-1.2 14.2 21.42 10,253,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cylinder_error_08");
	result = define_cylinder(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_cylinder, test_pass_a_vector_with_a_param_z_bigger_than_1, .exit_code = 42)
{
	int					fd;
	int					fd_bkp = dup(2);
	t_define_cylinder	result;
	t_world				world = (t_world){0};
	char				**params = ft_split("pl -50.0,0,0 0,0,1.2 14.2 21.42 10,253,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cylinder_error_09");
	result = define_cylinder(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_plane, test_pass_more_params_thats_need, .exit_code = 42)
{
	int					fd;
	int					fd_bkp = dup(2);
	t_define_cylinder	result;
	t_world				world = (t_world){0};
	char				**params = ft_split("pl -50.0,0,0 0,0,1 14.2 21.42 10,253,255 8", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cylinder_error_10");
	result = define_cylinder(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_plane, test_pass_a_incorrect_param_for_diameter, .exit_code = 42)
{
	int					fd;
	int					fd_bkp = dup(2);
	t_define_cylinder	result;
	t_world				world = (t_world){0};
	char				**params = ft_split("pl -50.0,0,0 0,0,1 A.2 21.42 10,253,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cylinder_error_11");
	result = define_cylinder(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_plane, test_pass_a_incorrect_param_for_height, .exit_code = 42)
{
	int					fd;
	int					fd_bkp = dup(2);
	t_define_cylinder	result;
	t_world				world = (t_world){0};
	char				**params = ft_split("pl -50.0,0,0 0,0,1 14.2 B.42 10,253,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cylinder_error_12");
	result = define_cylinder(params, &world);
	unset_output(&fd, &fd_bkp);
}