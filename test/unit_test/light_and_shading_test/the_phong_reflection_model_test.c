#include "unit_test.h"

Test(The_Phong_Reflection, A_point_has_a_position_and_intensity)
{
	t_color	intensity = fill_color(1, 1, 1);
	t_obj	position = create_point(0, 0, 0);
	t_light	light = point_light(position, intensity);

	cr_assert(cr_object_eq(light.position, position));
	cr_assert(light.intensity.red == 1);
	cr_assert(light.intensity.green == 1);
	cr_assert(light.intensity.blue == 1);
}

Test(The_Phong_Reflection, The_default_material)
{
	t_material	material = new_material();
	t_color		color = fill_color(1, 1, 1);
	cr_assert(cr_color_eq(material.color, color));
	cr_assert(material.ambient == 0.1);
	cr_assert(material.diffuse == 0.9);
	cr_assert(material.specular == 0.9);
	cr_assert(material.shininess == 200.0);
}

Test(The_Phong_Reflection, A_sphere_has_a_default_material)
{
	t_shape		shape = new_sphere();
	t_material	material = new_material();

	cr_assert(cr_material_eq(shape.any->material, material));

	clean_shape(&shape);
}

Test(The_Phong_Reflection, A_sphere_may_be_assigned_a_material)
{
	t_shape		shape = new_sphere();
	t_material	material = new_material();

	material.ambient = 1;
	shape.any->material = material;

	cr_assert(cr_material_eq(shape.any->material, material));
	cr_assert(shape.any->material.ambient == 1);

	clean_shape(&shape);
}

Test(The_Phong_Reflection, Lighting_with_the_eye_between_the_light_and_the_surface)
{
	t_lighting	lighting_s = (t_lighting){0};
	lighting_s.material = new_material();
	lighting_s.point = create_point(0, 0, 0);
	lighting_s.eyev = create_vector(0, 0, -1);
	lighting_s.normalv = create_vector(0, 0, -1);
	lighting_s.shape = new_sphere();
	t_color		color = fill_color(1, 1, 1);
	t_obj		point = create_point(0, 0, -10);
	lighting_s.light = point_light(point, color);
	t_color		res_color = fill_color(1.9, 1.9, 1.9);

	t_color	res = lighting(lighting_s);

	cr_assert(cr_color_eq(res, res_color));
	clean_shape(&lighting_s.shape);
}

Test(The_Phong_Reflection, Lighting_with_the_eye_between_light_and_surface__eye_offset_45)
{
	t_lighting	lighting_s = (t_lighting){0};
	lighting_s.material = new_material();
	lighting_s.point = create_point(0, 0, 0);
	lighting_s.eyev = create_vector(0, sqrt(2)/2, sqrt(2)/2 * -1);
	lighting_s.normalv = create_vector(0, 0, -1);
	lighting_s.shape = new_sphere();
	t_color		color = fill_color(1, 1, 1);
	t_obj		point = create_point(0, 0, -10);
	lighting_s.light = point_light(point, color);
	t_color		res_color = fill_color(1, 1, 1);

	t_color	res = lighting(lighting_s);

	cr_assert(cr_color_eq(res, res_color));
	clean_shape(&lighting_s.shape);
}

Test(The_Phong_Reflection, Lighting_with_eye_opposite_surface__light_offset_45)
{
	t_lighting	lighting_s = (t_lighting){0};
	lighting_s.material = new_material();
	lighting_s.point = create_point(0, 0, 0);
	lighting_s.eyev = create_vector(0, 0, -1);
	lighting_s.normalv = create_vector(0, 0, -1);
	lighting_s.shape = new_sphere();
	t_color		color = fill_color(1, 1, 1);
	t_obj		point = create_point(0, 10, -10);
	lighting_s.light = point_light(point, color);
	t_color		res_color = fill_color(0.7364, 0.7364, 0.7364);

	t_color	res = lighting(lighting_s);

	cr_assert(cr_color_eq(res, res_color));
	clean_shape(&lighting_s.shape);
}

Test(The_Phong_Reflection, Lighting_with_eye_in_the_path_of_the_reflection_vector)
{
	t_lighting	lighting_s = (t_lighting){0};
	lighting_s.material = new_material();
	lighting_s.point = create_point(0, 0, 0);
	lighting_s.eyev = create_vector(0, sqrt(2)/2 * -1, sqrt(2)/2 * -1);
	lighting_s.normalv = create_vector(0, 0, -1);
	lighting_s.shape = new_sphere();
	t_color		color = fill_color(1, 1, 1);
	t_obj		point = create_point(0, 10, -10);
	lighting_s.light = point_light(point, color);
	t_color		res_color = fill_color(1.6364, 1.6364, 1.6364);

	t_color	res = lighting(lighting_s);

	cr_assert(cr_color_eq(res, res_color));
	clean_shape(&lighting_s.shape);
}

Test(The_Phong_Reflection, Lighting_with_the_light_behind_the_surface)
{
	t_lighting	lighting_s = (t_lighting){0};
	lighting_s.material = new_material();
	lighting_s.point = create_point(0, 0, 0);
	lighting_s.eyev = create_vector(0, 0, -1);
	lighting_s.normalv = create_vector(0, 0, -1);
	lighting_s.shape = new_sphere();
	t_color		color = fill_color(1, 1, 1);
	t_obj		point = create_point(0, 0, 10);
	lighting_s.light = point_light(point, color);
	t_color		res_color = fill_color(0.1, 0.1, 0.1);

	t_color	res = lighting(lighting_s);

	cr_assert(cr_color_eq(res, res_color));
	clean_shape(&lighting_s.shape);
}
