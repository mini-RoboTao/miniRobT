#include "unit_test.h"

t_ray	*s_ray = &(t_ray){.position = &(t_obj){.x= 0, .y= 0, .z= -5, .w= 1}, \
						.direction = &(t_obj){.x= 0, .y= 0, .z= 1, .w= 0}};

Test(intersections, a_ray_intersects_a_sphere_at_two_points)
{
	t_sphere	*s = new_sphere();
	t_intersect	xs = intersect(s, s_ray);

	cr_assert(eq(xs.amount, 2));
	cr_assert(epsilon_eq(flt, xs.collision[0], 4.0, EPSILON));
	cr_assert(epsilon_eq(flt, xs.collision[1], 6.0, EPSILON));
	if (s)
		free(s);
}

Test(intersections, a_ray_intersects_a_sphere_at_a_tangent)
{
	s_ray->position->y = 1;
	t_sphere	*s = new_sphere();
	t_intersect	xs = intersect(s, s_ray);

	cr_assert(eq(xs.amount, 2));
	cr_assert(epsilon_eq(flt, xs.collision[0], 5.0, EPSILON));
	cr_assert(epsilon_eq(flt, xs.collision[1], 5.0, EPSILON));
	s_ray->position->y = 0;
	if (s)
		free(s);
}

Test(intersections, a_ray_misses_a_sphere)
{
	s_ray->position->y = 2;
	t_sphere	*s = new_sphere();
	t_intersect	xs = intersect(s, s_ray);

	cr_assert(eq(xs.amount, 0));
	s_ray->position->y = 0;
	if (s)
		free(s);
}

Test(intersections, a_ray_originates_inside_a_sphere)
{
	s_ray->position->y = 0;
	s_ray->position->z = 0;
	t_sphere	*s = new_sphere();
	t_intersect	xs = intersect(s, s_ray);

	cr_assert(eq(xs.amount, 2));
	cr_assert(epsilon_eq(flt, xs.collision[0], -1.0, EPSILON));
	cr_assert(epsilon_eq(flt, xs.collision[1], 1.0, EPSILON));
	s_ray->position->y = 0;
	s_ray->position->z = -5;
	if (s)
		free(s);
}

Test(intersections, a_sphere_is_behind_a_ray)
{
	s_ray->position->z = 5;
	t_sphere	*s = new_sphere();
	t_intersect	xs = intersect(s, s_ray);

	cr_assert(eq(xs.amount, 2));
	cr_assert(epsilon_eq(flt, xs.collision[0], -6.0, EPSILON));
	cr_assert(epsilon_eq(flt, xs.collision[1], -4.0, EPSILON));
	s_ray->position->z = -5;
	if (s)
		free(s);
}

Test(intersections, an_intersection_encapsulates_t_and_shape)
{
	t_sphere		*s = new_sphere();
	t_intersection	*i = intersection(3.5, s);

	cr_assert(epsilon_eq(flt, i->t, 3.5, EPSILON));
	cr_assert(cr_sphere_eq(i->sphere, s));
	if (s)
		free(s);
	if (i)
		free(i);
}

// Test(intersections, an_intersection_encapsulates_t_and_shape)
// {
// 	t_sphere		*s = new_sphere();
// 	t_intersection	*i1 = intersection(1, s);
// 	t_intersection	*i2 = intersection(2, s);
// 	t_intersect		xs = intersections(i1, i2);

// 	cr_assert(eq(xs.amount, 2));
// 	cr_assert(epsilon_eq(flt, xs.collision[0], 5.0, EPSILON));
// 	cr_assert(epsilon_eq(flt, xs.collision[1], 5.0, EPSILON));
// }