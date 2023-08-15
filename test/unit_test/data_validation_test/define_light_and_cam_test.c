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

Test(define_camera, test_pass_a_correct_cam)
{
	t_define_cam	result;
	t_world			world = (t_world){0};
	char			*params[] = {
					"C",
					"-50.0,0,20",
					"0,0,1",
					"70",
					NULL		};
	t_define_cam	expected = {
					.point = (t_obj){-50, 0, 20, 1},
					.vector = (t_obj){0, 0, 1, 0},
					.fov = 70	};

	result = define_camera(params, &world);

	cr_assert(cr_object_eq(expected.point, result.point));
	cr_assert(epsilon_eq(flt, expected.fov, result.fov, EPSILON));
	cr_assert(cr_object_eq(expected.vector, result.vector));
}

Test(define_camera, test_pass_a_incorrect_param_of_xyz_point_should_be_exit, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_cam	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("C -50.0,0 0,0,1 70", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_01");
	result = define_camera(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_camera, test_pass_a_param_fov_with_a_minor_value_should_be_exit, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_cam	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("C -50.0,0,0 0,0,1 -1", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_02");
	result = define_camera(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_camera, test_pass_a_param_fov_with_a_bigger_value_should_be_exit, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_cam	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("C -50.0,0,0 0,0,1 181", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_03");
	result = define_camera(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_camera, test_pass_a_param_vector_with_a_x_bigger_them_1_value_should_be_exit, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_cam	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("C -50.0,0,0 3,0,0 70", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_04");
	result = define_camera(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_camera, test_pass_a_param_vector_with_a_x_minor_them_minus_1_value_should_be_exit, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_cam	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("C -50.0,0,0 -3,0,0 70", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_05");
	result = define_camera(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_camera, test_pass_a_param_vector_with_a_y_bigger_them_1_value_should_be_exit, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_cam	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("C -50.0,0,0 0,2,0 70", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_06");
	result = define_camera(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_camera, test_pass_a_param_vector_with_a_y_minor_them_minus_1_value_should_be_exit, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_cam	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("C -50.0,0,0 0,-2,0 70", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_07");
	result = define_camera(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_camera, test_pass_a_param_vector_with_a_z_bigger_them_1_value_should_be_exit, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_cam	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("C -50.0,0,0 0,0,5 70", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_08");
	result = define_camera(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_camera, test_pass_a_param_vector_with_a_z_minor_them_minus_1_value_should_be_exit, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_cam	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("C -50.0,0,0 0,0,-5 70", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_09");
	result = define_camera(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_camera, test_pass_a_invalid_number_of_params_value_should_be_exit, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_cam	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("C -50.0,0,0 0,0,-5", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_10");
	result = define_camera(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_light, test_pass_a_correct_light)
{
	t_define_light	result;
	t_world			world = (t_world){0};
	char			*params[] = {
					"L",
					"-40.0,50.0,0.0",
					"0.6",
					"10,0,255",
					NULL		};
	t_define_light	expected = {
					.color = {COLOUR_PERCNT * 10, COLOUR_PERCNT * 0, COLOUR_PERCNT * 255},
					.intensity = 0.6,
					.position = {-40, 50, 0, 1} };

	result = define_light(params, &world);

	cr_assert(cr_object_eq(expected.position, result.position));
	cr_assert(epsilon_eq(flt, expected.intensity, result.intensity, EPSILON));
	cr_assert(epsilon_eq(flt, expected.color.red, result.color.red, EPSILON));
	cr_assert(epsilon_eq(flt, expected.color.green, result.color.green, EPSILON));
	cr_assert(epsilon_eq(flt, expected.color.blue, result.color.blue, EPSILON));
}

Test(define_light, test_pass_a_incorrect_param_to_point, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_light	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("L -40.0,50.0, 0.6 10,0,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_11");
	result = define_light(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_light, test_pass_a_brightness_bigger_them_1, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_light	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("L -40.0,50.0,0.0 1.5 10,0,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_12");
	result = define_light(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_light, test_pass_a_brightness_minor_them_0, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_light	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("L -40.0,50.0,0.0 1.5 10,0,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_13");
	result = define_light(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_light, test_pass_a_rgb_value_minor_them_0, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_light	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("L -40.0,50.0,0.0 0.5 10,0,-42", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_14");
	result = define_light(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_light, test_pass_a_rgb_value_bigger_them_255, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_light	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("L -40.0,50.0,0.0 0.5 10,0,256", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_15");
	result = define_light(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_light, test_pass_a_rgb_without_color_green, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_light	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("L -40.0,50.0,0.0 0.5 10,,254", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_16");
	result = define_light(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_light, test_without_one_param_of_light, .exit_code = 42)
{
	int				fd;
	int				fd_bkp = dup(2);
	t_define_light	result;
	t_world			world = (t_world){0};
	char			**params = ft_split("L -40.0,50.0,0.0 0.5", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_17");
	result = define_light(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_ambient_light, test_pass_a_correct_ambient_light)
{
	t_define_a_light	result;
	t_world				world = (t_world){0};
	char				*params[] = {
						"A",
						"0.6",
						"10,0,255",
						NULL		};
	t_define_a_light	expected = {
						.color = {COLOUR_PERCNT * 10, COLOUR_PERCNT * 0, COLOUR_PERCNT * 255},
						.intensity = 0.6 };

	result = define_ambient_light(params, &world);

	cr_assert(epsilon_eq(flt, expected.intensity, result.intensity, EPSILON));
	cr_assert(epsilon_eq(flt, expected.color.red, result.color.red, EPSILON));
	cr_assert(epsilon_eq(flt, expected.color.green, result.color.green, EPSILON));
	cr_assert(epsilon_eq(flt, expected.color.blue, result.color.blue, EPSILON));
}

Test(define_ambient_light, test_pass_intensity_bigger_them_1, .exit_code = 42)
{
	int					fd;
	int					fd_bkp = dup(2);
	t_define_a_light	result;
	t_world				world = (t_world){0};
	char				**params = ft_split("A 1.5 10,0,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_18");
	result = define_ambient_light(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_ambient_light, test_pass_intensity_minor_them_0, .exit_code = 42)
{
	int					fd;
	int					fd_bkp = dup(2);
	t_define_a_light	result;
	t_world				world = (t_world){0};
	char				**params = ft_split("A -1.5 10,0,255", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_19");
	result = define_ambient_light(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_ambient_light, test_pass_a_rgb_value_minor_them_0, .exit_code = 42)
{
	int					fd;
	int					fd_bkp = dup(2);
	t_define_a_light	result;
	t_world				world = (t_world){0};
	char				**params = ft_split("A 0.5 10,-42,123", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_20");
	result = define_ambient_light(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_ambient_light, test_pass_a_rgb_value_bigger_them_255, .exit_code = 42)
{
	int					fd;
	int					fd_bkp = dup(2);
	t_define_a_light	result;
	t_world				world = (t_world){0};
	char				**params = ft_split("A 0.5 10,256,0", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_21");
	result = define_ambient_light(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_ambient_light, test_pass_a_rgb_without_color_red, .exit_code = 42)
{
	int					fd;
	int					fd_bkp = dup(2);
	t_define_a_light	result;
	t_world				world = (t_world){0};
	char				**params = ft_split("A 0.5 ,0,254", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_22");
	result = define_ambient_light(params, &world);
	unset_output(&fd, &fd_bkp);
}

Test(define_ambient_light, test_without_one_param_of_light, .exit_code = 42)
{
	int					fd;
	int					fd_bkp = dup(2);
	t_define_a_light	result;
	t_world				world = (t_world){0};
	char				**params = ft_split("A 0.5", ' ');

	set_world(&world);
	set_output(&fd, "test_define_cam_error_23");
	result = define_ambient_light(params, &world);
	unset_output(&fd, &fd_bkp);
}