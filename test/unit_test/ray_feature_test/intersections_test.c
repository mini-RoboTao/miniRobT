#include "unit_test.h"

static t_ray	create_ray_res(void)
{
	t_ray	res;

	res.position = create_object(0, 0, -5, 1);
	res.direction = create_object(0, 0, 1, 0);
	return (res);
}

// t_ray	*s_ray = create_ray_res();
// t_ray	*s_ray = &(t_ray){.position = (t_obj){.x= 0, .y= 0, .z= -5, .w= 1}, .direction = (t_obj){.x= 0, .y= 0, .z= 1, .w= 0}};

Test(intersections, a_ray_intersects_a_sphere_at_two_points)
{
	t_ray	s_ray = create_ray_res();
	t_sphere		*s = new_sphere();
	t_intersections	xs = intersect(s, s_ray);

	cr_assert(eq(xs.amount, 2));
	cr_assert(epsilon_eq(flt, xs.i->t, 4.0, EPSILON));
	cr_assert(epsilon_eq(flt, xs.i->next->t, 6.0, EPSILON));
	clean_intersection_lst(&xs.i);
	clean_sphere(s);
	if (xs.shape)
		free(xs.shape);
}

Test(intersections, a_ray_intersects_a_sphere_at_a_tangent)
{
	t_ray	s_ray = create_ray_res();
	s_ray.position.y = 1;
	t_sphere		*s = new_sphere();
	t_intersections	xs = intersect(s, s_ray);

	cr_assert(eq(xs.amount, 2));
	cr_assert(epsilon_eq(flt, xs.i->t, 5.0, EPSILON));
	cr_assert(epsilon_eq(flt, xs.i->next->t, 5.0, EPSILON));
	s_ray.position.y = 0;
	clean_intersection_lst(&xs.i);
	clean_sphere(s);
	if (xs.shape)
		free(xs.shape);
}

Test(intersections, a_ray_misses_a_sphere)
{
	t_ray	s_ray = create_ray_res();
	s_ray.position.y = 2;
	t_sphere		*s = new_sphere();
	t_intersections	xs = intersect(s, s_ray);

	cr_assert(eq(xs.amount, 0));
	cr_assert(eq(xs.i, NULL));
	s_ray.position.y = 0;
	clean_sphere(s);
	if (xs.shape)
		free(xs.shape);
}

Test(intersections, a_ray_originates_inside_a_sphere)
{
	t_ray	s_ray = create_ray_res();
	s_ray.position.y = 0;
	s_ray.position.z = 0;
	t_sphere		*s = new_sphere();
	t_intersections	xs = intersect(s, s_ray);

	cr_assert(eq(xs.amount, 2));
	cr_assert(epsilon_eq(flt, xs.i->t, -1.0, EPSILON));
	cr_assert(epsilon_eq(flt, xs.i->next->t, 1.0, EPSILON));
	s_ray.position.y = 0;
	s_ray.position.z = -5;
	clean_intersection_lst(&xs.i);
	clean_sphere(s);
	if (xs.shape)
		free(xs.shape);
}

Test(intersections, a_sphere_is_behind_a_ray)
{
	t_ray	s_ray = create_ray_res();
	s_ray.position.z = 5;
	t_sphere	*s = new_sphere();
	t_intersections	xs = intersect(s, s_ray);

	cr_assert(eq(xs.amount, 2));
	cr_assert(epsilon_eq(flt, xs.i->t, -6.0, EPSILON));
	cr_assert(epsilon_eq(flt, xs.i->next->t, -4.0, EPSILON));
	s_ray.position.z = -5;
	clean_intersection_lst(&xs.i);
	clean_sphere(s);
	if (xs.shape)
		free(xs.shape);
}

Test(intersections, intersect_sets_the_object_on_the_intersection)
{
	t_ray	s_ray = create_ray_res();
	t_sphere		*s = new_sphere();
	t_intersections	xs = intersect(s, s_ray);

	cr_assert(eq(xs.amount, 2));
	cr_assert(cr_sphere_eq(xs.i->v, s));
	cr_assert(cr_sphere_eq(xs.i->next->v, s));
	clean_intersection_lst(&xs.i);
	clean_sphere(s);
	if (xs.shape)
		free(xs.shape);
}

Test(intersections, an_intersection_encapsulates_t_and_shape)
{
	t_sphere		*s = new_sphere();
	t_intersection	*i = intersection(3.5, s);

	cr_assert(epsilon_eq(flt, i->t, 3.5, EPSILON));
	cr_assert(cr_sphere_eq(i->v, s));
	clean_sphere(s);
	if (i)
		free(i);
}

Test(intersections, aggregating_intersections)
{
	t_sphere		*s = new_sphere();
	t_intersection	*i1 = intersection(1, s);
	t_intersection	*i2 = intersection(2, s);
	t_intersections	xs	=	(t_intersections){0};
	xs.shape = malloc(sizeof(void *));
	intersections(&xs, i1, i2, 0);

	cr_assert(eq(xs.amount, 2));
	cr_assert(epsilon_eq(flt, xs.i->t, 1, EPSILON));
	cr_assert(epsilon_eq(flt, xs.i->next->t, 2, EPSILON));
	clean_intersection_lst(&xs.i);
	clean_sphere(s);
	if (xs.shape)
		free(xs.shape);
}

Test(the_hit, when_all_intersections_have_positive_t_)
{
	t_sphere		*s = new_sphere();
	t_intersection	*i1 = intersection(1, s);
	t_intersection	*i2 = intersection(2, s);
	t_intersections	xs = (t_intersections){0};

	xs.shape = malloc(sizeof(void *));
	intersections(&xs, i2, i1, 0);
	t_intersection	*i = hit(xs);
	cr_assert(cr_intersection_eq(i, i1));
	clean_intersection_lst(&xs.i);
	clean_sphere(s);
	if (xs.shape)
		free(xs.shape);
}

Test(the_hit, when_some_intersections_have_negative_t_)
{
	t_sphere		*s = new_sphere();
	t_intersection	*i1 = intersection(-1, s);
	t_intersection	*i2 = intersection(1, s);
	t_intersections	xs = (t_intersections){0};

	xs.shape = malloc(sizeof(void *));
	intersections(&xs, i2, i1, 0);
	t_intersection	*i = hit(xs);
	cr_assert(cr_intersection_eq(i, i2));
	clean_intersection_lst(&xs.i);
	clean_sphere(s);
	if (xs.shape)
		free(xs.shape);
}

Test(the_hit, when_all_intersections_have_negative_t_)
{
	t_sphere		*s = new_sphere();
	t_intersection	*i1 = intersection(-2, s);
	t_intersection	*i2 = intersection(-1, s);
	t_intersections	xs = (t_intersections){0};

	xs.shape = malloc(sizeof(void *));
	intersections(&xs, i2, i1, 0);
	t_intersection	*i = hit(xs);
	cr_assert(eq(i, NULL));
	clean_intersection_lst(&xs.i);
	clean_sphere(s);
	if (xs.shape)
		free(xs.shape);
}

Test(the_hit, the_hit_is_always_the_lowest_nonnegative_intersection)
{
	t_sphere		*s = new_sphere();
	t_intersection	*i1 = intersection(5, s);
	t_intersection	*i2 = intersection(7, s);
	t_intersection	*i3 = intersection(-3, s);
	t_intersection	*i4 = intersection(2, s);
	t_intersections	xs = (t_intersections){0};

	xs.shape = malloc(sizeof(void *));
	intersections(&xs, i2, i1, 0);
	intersections(&xs, i3, i4, 0);
	t_intersection	*i = hit(xs);
	cr_assert(cr_intersection_eq(i, i4));
	clean_intersection_lst(&xs.i);
	clean_sphere(s);
	if (xs.shape)
		free(xs.shape);
}