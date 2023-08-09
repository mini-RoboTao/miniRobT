#include "unit_test.h"

Test(cube_shape, a_ray_intersects_a_cube)
{
	t_ray				ray;
	t_shape				shape = new_cube();
	t_intersections		xs;
	t_ray				ray_sent[7] = {
		{.position = (t_obj){5, 0.5, 0, 1}, .direction = (t_obj){-1, 0, 0, 0}}, // +x
		{.position = (t_obj){-5, 0.5, 0, 1},.direction = (t_obj){1, 0, 0, 0}}, // -x
		{.position = (t_obj){0.5, 5, 0, 1}, .direction = (t_obj){0, -1, 0, 0}}, // +y
		{.position = (t_obj){0.5, -5, 0, 1},.direction = (t_obj){0, 1, 0, 0}}, // -y
		{.position = (t_obj){0.5, 0, 5, 1}, .direction = (t_obj){0, 0, -1, 0}}, // +z
		{.position = (t_obj){0.5, 0, -5, 1},.direction = (t_obj){0, 0, 1, 0}}, // -z
		{.position = (t_obj){0, 0.5, 0, 1}, .direction = (t_obj){0, 0, 1, 0}}, // inside
	};

	for (int i = 0; i < 6; i++) {
		ray = create_ray(ray_sent[i].position, ray_sent[i].direction);
		xs = (t_intersections){0};
		shape.intersect(&xs, shape, ray);

		// Assert +x, -x, +y, -y, +z, -z
		cr_assert(epsilon_eq(flt, xs.i->t, 4, EPSILON));
		cr_assert(epsilon_eq(flt, xs.i->next->t, 6, EPSILON));

		clean_intersection_lst(&xs.i);
	}
	ray = create_ray(ray_sent[6].position, ray_sent[6].direction);
	xs = (t_intersections){0};
	shape.intersect(&xs, shape, ray);

	// Assert inside
	cr_assert(epsilon_eq(flt, xs.i->t, -1, EPSILON));
	cr_assert(epsilon_eq(flt, xs.i->next->t, 1, EPSILON));

	clean_intersection_lst(&xs.i);
	clean_shape(&shape);
}


Test(cube_shape, a_ray_misses_a_cube)
{
	t_ray				ray;
	t_shape				shape = new_cube();
	t_intersections		xs;
	t_ray				ray_sent[6] = {
			{.position = (t_obj){-2, 0, 0, 1},.direction = (t_obj){0.2673, 0.5345, 0.8018, 0}},
			{.position = (t_obj){0, -2, 0, 1},.direction = (t_obj){0.8018, 0.2673, 0.5345, 0}},
			{.position = (t_obj){0, 0, -2, 1},.direction = (t_obj){0.5345, 0.8018, 00.2673, 0}},
			{.position = (t_obj){2, 0, 2, 1}, .direction = (t_obj){0, 0, -1, -1}},
			{.position = (t_obj){0, 2, 2, 1}, .direction = (t_obj){0, -1, 0, 0}},
			{.position = (t_obj){2, 2, 0, 1}, .direction = (t_obj){-1, 0, 0, 0}},
	};

	for (int i = 0; i < 6; i++) {
		ray = create_ray(ray_sent[i].position, ray_sent[i].direction);
		xs = (t_intersections){0};
		shape.intersect(&xs, shape, ray);

		// Assert
		cr_assert(eq(xs.i, NULL));
	}
	clean_shape(&shape);
}

Test(cube_shape, the_normal_on_the_surface_of_a_cube)
{
	t_shape				shape = new_cube();
	t_obj				normal_result;
	t_obj				point_sent[8] = {
						{1, 0.5, -0.8, 1},
						{-1, -0.2, 0.9, 1},
						{-0.4, 1, -0.1, 1},
						{0.3, -1, -0.7, 1},
						{-0.6, 0.3, 1, 1},
						{0.4, 0.4, -1, 1},
						{1, 1, 1, 1},
						{-1, -1, -1, 1}
	};
	t_obj				expected_normal[8] = {
						{1, 0, 0, 0},
						{-1, 0, 0, 0},
						{0, 1, 0, 0},
						{0, -1, 0, 0},
						{0, 0, 1, 0},
						{0, 0, -1, 0},
						{1, 0, 0, 0},
						{-1, 0, 0, 0}
	};

	for (int i = 0; i < 8; i++) {
		normal_result = shape.normal_at(shape, point_sent[i]);
		// Assert
		cr_assert(cr_object_eq(normal_result, expected_normal[i]));
	}
	clean_shape(&shape);
}
