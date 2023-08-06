#include "unit_test.h"

Test(Patterns, Creating_a_stripe_pattern)
{
	t_color	black = fill_color(0, 0, 0);
	t_color	white = fill_color(1, 1, 1);

	t_pattern pattern = stripe_pattern(white, black);
	cr_assert(cr_color_eq(pattern.a, white));
	cr_assert(cr_color_eq(pattern.b, black));
}

Test(Patterns, A_stripe_pattern_is_constant_in_y)
{
	t_color	black = fill_color(0, 0, 0);
	t_color	white = fill_color(1, 1, 1);

	t_pattern pattern = stripe_pattern(white, black);

	cr_assert(cr_color_eq(stripe_at(pattern, create_point(0, 0, 0)), white));
	cr_assert(cr_color_eq(stripe_at(pattern, create_point(0, 1, 0)), white));
	cr_assert(cr_color_eq(stripe_at(pattern, create_point(0, 2, 0)), white));
}

Test(Patterns, A_stripe_pattern_is_constant_in_z)
{
	t_color	black = fill_color(0, 0, 0);
	t_color	white = fill_color(1, 1, 1);

	t_pattern pattern = stripe_pattern(white, black);

	cr_assert(cr_color_eq(stripe_at(pattern, create_point(0, 0, 0)), white));
	cr_assert(cr_color_eq(stripe_at(pattern, create_point(0, 0, 1)), white));
	cr_assert(cr_color_eq(stripe_at(pattern, create_point(0, 0, 2)), white));
}

Test(Patterns, A_stripe_pattern_alternates_in_x)
{
	t_color	black = fill_color(0, 0, 0);
	t_color	white = fill_color(1, 1, 1);

	t_pattern pattern = stripe_pattern(white, black);

	cr_assert(cr_color_eq(stripe_at(pattern, create_point(0, 0, 0)), white));
	cr_assert(cr_color_eq(stripe_at(pattern, create_point(0.9, 0, 0)), white));
	cr_assert(cr_color_eq(stripe_at(pattern, create_point(1, 0, 0)), black));
	cr_assert(cr_color_eq(stripe_at(pattern, create_point(-0.1, 0, 0)), black));
	cr_assert(cr_color_eq(stripe_at(pattern, create_point(-1, 0, 0)), black));
	cr_assert(cr_color_eq(stripe_at(pattern, create_point(-1.1, 0, 0)), white));
}

Test(Patterns, Lighting_with_a_pattern_applied)
{
	t_color		black = fill_color(0, 0, 0);
	t_color		white = fill_color(1, 1, 1);
	t_pattern	pattern = stripe_pattern(white, black);
	t_material	material = new_material();
	t_obj		eyev = create_vector(0, 0, -1);
	t_obj		normalv = create_vector(0, 0, -1);
	t_light		light = point_light(create_point(0, 0, -10), fill_color(1, 1, 1));
	t_lighting	lig1;
	t_lighting	lig2;

	material.pattern = pattern;
	material.ambient = 1;
	material.diffuse = 0;
	material.specular = 0;

	lig1.material = material;
	lig1.light = light;
	lig1.point = create_point(0.9, 0, 0);
	lig1.eyev = eyev;
	lig1.normalv = normalv;
	lig1.in_shadow = false;
	lig1.shape = new_sphere();

	lig2.material = material;
	lig2.light = light;
	lig2.point = create_point(1.1, 0, 0);
	lig2.eyev = eyev;
	lig2.normalv = normalv;
	lig2.in_shadow = false;
	lig2.shape = new_sphere();

	t_color		c1 = lighting(lig1);
	t_color		c2 = lighting(lig2);

	cr_expect(cr_color_eq(c1, white));
	cr_expect(cr_color_eq(c2, black));

	clean_shape(&lig1.shape);
	clean_shape(&lig2.shape);
}

Test(Patterns, Stripes_with_an_object_transformation)
{
	t_shape		sphere = new_sphere();
	t_pattern	pattern = stripe_pattern(fill_color(1, 1, 1), fill_color(0, 0, 0));

	set_transform(&sphere, scaling(2, 2, 2));

	t_color		c = stripe_at_object(&pattern, sphere, create_point(1.5, 0, 0));

	cr_assert(cr_color_eq(c, fill_color(1, 1, 1)));
	clean_shape(&sphere);
}

Test(Patterns, Stripes_with_a_pattern_transformation)
{
	t_shape		sphere = new_sphere();
	t_pattern	pattern = stripe_pattern(fill_color(1, 1, 1), fill_color(0, 0, 0));

	set_pattern_transform(&pattern, scaling(2, 2, 2));

	t_color		c = stripe_at_object(&pattern, sphere, create_point(1.5, 0, 0));

	cr_assert(cr_color_eq(c, fill_color(1, 1, 1)));
	clean_shape(&sphere);
}

Test(Patterns, Stripes_with_both_an_object_and_a_pattern_transformation)
{
	t_shape		sphere = new_sphere();
	t_pattern	pattern = stripe_pattern(fill_color(1, 1, 1), fill_color(0, 0, 0));

	set_transform(&sphere, scaling(2, 2, 2));
	set_pattern_transform(&pattern, translation(0.5, 0, 0));

	t_color		c = stripe_at_object(&pattern, sphere, create_point(2.5, 0, 0));

	cr_assert(cr_color_eq(c, fill_color(1, 1, 1)));
	clean_shape(&sphere);
}