#include "unit_test.h"

Test(Making_a_striped_pattern, Creating_a_stripe_pattern)
{
	t_color	black = fill_color(0, 0, 0);
	t_color	white = fill_color(1, 1, 1);

	t_pattern pattern = stripe_pattern(white, black);
	cr_assert(cr_color_eq(pattern.a, white));
	cr_assert(cr_color_eq(pattern.b, black));
}

Test(Making_a_striped_pattern, A_stripe_pattern_is_constant_in_y)
{
	t_color	black = fill_color(0, 0, 0);
	t_color	white = fill_color(1, 1, 1);

	t_pattern pattern = stripe_pattern(white, black);

	cr_assert(cr_color_eq(stripe_at(pattern, create_point(0, 0, 0)), white));
	cr_assert(cr_color_eq(stripe_at(pattern, create_point(0, 1, 0)), white));
	cr_assert(cr_color_eq(stripe_at(pattern, create_point(0, 2, 0)), white));
}

Test(Making_a_striped_pattern, A_stripe_pattern_is_constant_in_z)
{
	t_color	black = fill_color(0, 0, 0);
	t_color	white = fill_color(1, 1, 1);

	t_pattern pattern = stripe_pattern(white, black);

	cr_assert(cr_color_eq(stripe_at(pattern, create_point(0, 0, 0)), white));
	cr_assert(cr_color_eq(stripe_at(pattern, create_point(0, 0, 1)), white));
	cr_assert(cr_color_eq(stripe_at(pattern, create_point(0, 0, 2)), white));
}

Test(Making_a_striped_pattern, A_stripe_pattern_alternates_in_x)
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

Test(Making_a_striped_pattern, Lighting_with_a_pattern_applied)
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
