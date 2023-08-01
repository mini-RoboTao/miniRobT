#include "unit_test.h"

Test(camera, constructing_a_camera)
{
	int			hsize = 160;
	int			vsize = 120;
	double		field_of_view = M_PI_2;
	t_camera	c;

	c = camera(hsize, vsize, field_of_view);
	cr_assert(eq(c.hsize, 160));
	cr_assert(eq(c.vsize, 120));
	cr_assert(epsilon_eq(flt, c.field_of_view, M_PI_2, EPSILON));
	cr_assert(cr_matrix_eq(c.transform, IDENTITY_MATRIX));
	clean_matrix(c.transform);
}

Test(camera, the_pixel_size_for_a_horizontal_canvas)
{
	t_camera	c = camera(200, 125, M_PI_2);
	cr_assert(epsilon_eq(flt, c.pixel_size, 0.01, EPSILON));
	clean_matrix(c.transform);
}

Test(camera, the_pixel_size_for_a_vertical_canvas)
{
	t_camera	c = camera(125, 200, M_PI_2);
	cr_assert(epsilon_eq(flt, c.pixel_size, 0.01, EPSILON));
	clean_matrix(c.transform);
}

Test(camera, constructing_a_ray_through_the_center_of_the_canvas)
{
	t_camera	c = camera(201, 101, M_PI_2);
	t_ray		*r = ray_for_pixel(&c, 100, 50);
	cr_assert(cr_object_eq(r->position, (t_obj){0, 0, 0, 1}));
	cr_assert(cr_object_eq(r->direction, (t_obj){0, 0, -1, 0}));
	clean_matrix(c.transform);
	// clean_ray(r);
}

Test(camera, constructing_a_ray_through_a_corner_of_the_canvas)
{
	t_camera	c = camera(201, 101, M_PI_2);
	t_ray		*r = ray_for_pixel(&c, 0, 0);
	cr_assert(cr_object_eq(r->position, (t_obj){0, 0, 0, 1}));
	cr_assert(cr_object_eq(r->direction, (t_obj){0.66519, 0.33259, -0.66851, 0}));
	clean_matrix(c.transform);
	// clean_ray(r);
}

Test(camera, constructing_a_ray_when_the_camera_is_transformed)
{
	t_camera	c		= camera(201, 101, M_PI_2);
	t_matrix	*mt		= translation(0, -2, 5);
	t_matrix	*mry	= rotation_y(M_PI_4);
	clean_matrix(c.transform);
	c.transform 		= multiply_matrix(mry, mt, 4, 4);
	t_ray		*r 		= ray_for_pixel(&c, 100, 50);
	cr_assert(cr_object_eq(r->position, (t_obj){0, 2, -5, 1}));
	cr_assert(cr_object_eq(r->direction, (t_obj){sqrt(2)/2, 0, -(sqrt(2)/2), 0}));
	clean_matrix(c.transform);
	clean_matrix(mt);
	clean_matrix(mry);
	// clean_ray(r);
}

Test(camera, rendering_a_world_with_a_camera)
{
	t_world		w = default_world();
	t_camera	c = camera(11, 11, M_PI_2);
	t_obj		from = create_point(0, 0, -5);
	t_obj		to = create_point(0, 0, 0);
	t_obj		up = create_vector(0, 1, 0);
	clean_matrix(c.transform);
	c.transform = view_transformation(from, to, up);
	t_canvas	*image = render(&c, &w);
	cr_assert(cr_color_eq(image->canvas[5][5], fill_color(0.38066, 0.47583, 0.2855)));
	clean_matrix(c.transform);
	// clean_obj(from);
	// clean_obj(to);
	clean_world(w);
	clean_canvas(image);
}