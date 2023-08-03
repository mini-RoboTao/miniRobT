#include "unit_test.h"

Test(Shadows, Lighting_with_the_surface_in_shadow)
{
	t_lighting		data;
	t_obj			point		= create_point(0, 0, -10);
	t_color			color		= fill_color(1, 1, 1);
	t_color			res_color	= fill_color(0.1, 0.1, 0.1);

	data.material 	= new_material();
	data.point		= create_point(0, 0, 0);
	data.eyev		= create_vector(0, 0, -1);
	data.normalv	= create_vector(0, 0, -1);
	data.light		= point_light(point, color);
	data.in_shadow	= true;

	t_color result = lighting(data);
	cr_assert(cr_color_eq(result, res_color));
}

Test(Shadows, There_is_no_shadow_when_nothing_is_collinear_with_point_and_light)
{
	t_obj		point		= create_point(0, 10, 0);
	t_world		world		= default_world();
	t_bool		shadowed	= is_shadowed(&world, point);

	cr_expect(eq(shadowed, F));
	clean_world(world);
}

Test(Shadows, The_shadow_when_an_object_is_between_the_point_and_the_light)
{
	t_obj	point = create_point(10, -10, 10);
	t_world	world = default_world();
	t_bool	shadowed = is_shadowed(&world, point);

	cr_assert(eq(shadowed, T));
	clean_world(world);
}

Test(Shadows, There_is_no_shadow_when_an_object_is_behind_the_light)
{
	t_obj	point = create_point(-20, 20, -20);
	t_world	world = default_world();
	t_bool	shadowed = is_shadowed(&world, point);

	cr_assert(eq(shadowed, F));
	clean_world(world);
}

Test(Shadows, There_is_no_shadow_when_an_object_is_behind_the_point)
{
	t_obj	point = create_point(-2, 2, -2);
	t_world	world = default_world();
	t_bool	shadowed = is_shadowed(&world, point);

	cr_assert(eq(shadowed, F));
	clean_world(world);
}

Test(Rendering_shadows, Shade_hit_is_given_an_intersection_in_shadow)
{
	t_world			world	= default_world();
	t_obj			point	= create_point(0, 0, -10);
	t_color			color 	= fill_color(1, 1, 1);
	world.light 			= point_light(point, color);

	t_matrix	transformation = translation(0, 0, 10);
	set_transform(world.shape[1].sphere, transformation);

	t_obj	point2 = create_point(0, 0, 5);
	t_obj	vector = create_vector(0, 0, 1);
	t_ray	ray = create_ray(point2, vector);

	t_intersection	*i = intersection(4, world.shape[1].v);

	t_precomp	comps = prepare_computations(i, ray);
	t_color	c = shade_hit(&world, &comps);

	t_color	color_res = fill_color(0.1, 0.1, 0.1);
	cr_assert(cr_color_eq(c, color_res));

	clean_intersection_lst(&i);
	clean_world(world);
}

Test(Rendering_shadows, The_hit_should_offset_the_point)
{
	t_obj	point = create_point(0, 0, -5);
	t_obj	vector = create_vector(0, 0, 1);
	t_ray	ray = create_ray(point, vector);
	t_sphere	*shape = new_sphere();
	t_matrix	transformation = translation(0, 0, 1);
	set_transform(shape, transformation);
	t_intersection	*i = intersection(5, shape);
	t_precomp	comps = prepare_computations(i, ray);
	cr_assert(comps.over_point.z < (-1 * (EPSILON / 2)));
	cr_assert(comps.point.z > comps.over_point.z);

	clean_intersection_lst(&i);
	clean_sphere(shape);
}
