// #include "unit_test.h"

// Test(transforming_rays, translating_a_ray)
// {
// 	t_obj		origin = (t_obj){.x=1, .y=2, .z=3, .w=1};
// 	t_obj		direction = (t_obj){.x=0, .y=1, .z=0, .w=0};
// 	t_ray		*r = create_ray(&origin, &direction);
// 	t_matrix	*m = translation(3, 4, 5);

// 	t_ray		*r2 = transform(r, m);
// 	cr_assert(cr_object_eq(r2->position, &(t_obj){.x=4, .y=6, .z=8, .w=1}));
// 	cr_assert(cr_object_eq(r2->direction, &(t_obj){.x=0, .y=1, .z=0, .w=0}));
// 	if (r)
// 		free(r);
// 	clean_ray(r2);
// 	clean_matrix(m);
// }

// Test(transforming_rays, scaling_a_ray)
// {
// 	t_obj		origin = (t_obj){.x=1, .y=2, .z=3, .w=1};
// 	t_obj		direction = (t_obj){.x=0, .y=1, .z=0, .w=0};
// 	t_ray		*r = create_ray(&origin, &direction);
// 	t_matrix	*m = scaling(2, 3, 4);

// 	t_ray		*r2 = transform(r, m);
// 	cr_assert(cr_object_eq(r2->position, &(t_obj){.x=2, .y=6, .z=12, .w=1}));
// 	cr_assert(cr_object_eq(r2->direction, &(t_obj){.x=0, .y=3, .z=0, .w=0}));
// 	if (r)
// 		free(r);
// 	clean_ray(r2);
// 	clean_matrix(m);
// }

// t_matrix	*m_identity		=	&(t_matrix){.node = (double *[]){ 		\
// 							(double []){1, 0, 0, 0},				\
// 							(double []){0, 1, 0, 0},				\
// 							(double []){0, 0, 1, 0},				\
// 							(double []){0, 0, 0, 1},				\
// 							}, .x = 4, .y = 4};

// Test(transforming_rays, a_sphere_is_default_transformation)
// {
// 	t_sphere	*s = new_sphere();
// 	cr_assert(cr_matrix_eq(s->transform, m_identity));
// 	clean_sphere(s);
// }

// Test(transforming_rays, changing_a_sphere_is_transformation)
// {
// 	t_sphere	*s = new_sphere();
// 	t_matrix	*t = translation(2, 3, 4);

// 	set_transform(s, t);
// 	cr_assert(cr_matrix_eq(s->transform, t));
// 	clean_sphere(s);
// }

// Test(transforming_rays, intersecting_a_scaled_sphere_with_a_ray)
// {
// 	t_obj		origin = (t_obj){.x=0, .y=0, .z=-5, .w=1};
// 	t_obj		direction = (t_obj){.x=0, .y=0, .z=1, .w=0};
// 	t_ray		*r = create_ray(&origin, &direction);
// 	t_sphere	*s = new_sphere();
// 	set_transform(s, scaling(2, 2, 2));

// 	t_intersections	xs = intersect(s, r);
// 	cr_assert(eq(xs.amount, 2));
// 	cr_assert(epsilon_eq(flt, xs.i->t, 3, EPSILON));
// 	cr_assert(epsilon_eq(flt, xs.i->next->t, 7, EPSILON));
// 	clean_matrix(s->transform);
// 	if (r)
// 		free(r);
// 	clean_intersection_lst(&xs.i);
// 	if (s)
// 		free(s);
// 	if (xs.shape)
// 		free(xs.shape);
// }

// Test(transforming_rays, intersecting_a_translation_sphere_with_a_ray)
// {
// 	t_obj		origin = (t_obj){.x=0, .y=0, .z=-5, .w=1};
// 	t_obj		direction = (t_obj){.x=0, .y=0, .z=1, .w=0};
// 	t_ray		*r = create_ray(&origin, &direction);
// 	t_sphere	*s = new_sphere();
// 	set_transform(s, translation(5, 0, 0));

// 	t_intersections	xs = intersect(s, r);
// 	cr_assert(eq(xs.amount, 0));
// 	clean_matrix(s->transform);
// 	if (r)
// 		free(r);
// 	clean_intersection_lst(&xs.i);
// 	if (s)
// 		free(s);
// }