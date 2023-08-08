#include "unit_test.h"

Test(transparency_and_refraction, transparency_and_refractive_index_for_the_default_material)
{
	t_material	m = new_material();
	cr_assert(epsilon_eq(flt, m.transparency, 0.0, EPSILON));
	cr_assert(epsilon_eq(flt, m.refractive_index, 1.0, EPSILON));
}

Test(transparency_and_refraction, a_helper_for_producing_a_sphere_with_a_glassy_material)
{
	t_shape		shape = glass_sphere();
	cr_assert(cr_matrix_eq(shape.sphere->transform, create_identity_matrix()));
	cr_assert(epsilon_eq(flt, shape.sphere->material.transparency, 1.0, EPSILON));
	cr_assert(epsilon_eq(flt, shape.sphere->material.refractive_index, 1.5, EPSILON));
	clean_shape(&shape);
}

typedef struct s_n
{
	double		n1;
	double		n2;
}				t_ns;

t_ns	expected_ns[6] = (t_ns[6]){
								{.n1 = 1.0, .n2 = 1.5},
								{.n1 = 1.5, .n2 = 2.0},
								{.n1 = 2.0, .n2 = 2.5},
								{.n1 = 2.5, .n2 = 2.5},
								{.n1 = 2.5, .n2 = 1.5},
								{.n1 = 1.5, .n2 = 1.0},
};

Test(transparency_and_refraction, finding_n1_and_n2_at_various_intersections)
{
	int				i = 0;
	t_precomp		comps;
	t_shape			A = glass_sphere();
	t_shape			B = glass_sphere();
	t_shape			C = glass_sphere();
	t_ray			ray = create_ray(create_point(0, 0, -4), create_vector(0, 0, 1));
	t_intersections	xs = (t_intersections){0};
	set_transform(&A, scaling(2, 2, 2));
	A.sphere->material.refractive_index = 1.5;
	set_transform(&B, translation(0, 0, -0.25));
	B.sphere->material.refractive_index = 2.0;
	set_transform(&C, translation(0, 0, 0.25));
	C.sphere->material.refractive_index = 2.5;

	intersections(&xs, intersection(2, A, &xs), intersection(2.75, B, &xs), 0);
	intersections(&xs, intersection(3.25, C, &xs), intersection(4.75, B, &xs), 0);
	intersections(&xs, intersection(5.25, C, &xs), intersection(6, A, &xs), 0);

	t_intersections list = xs;
	while (xs.i && i < 6)
	{
		comps = prepare_computations(xs.i, ray, &list);
		cr_assert(epsilon_eq(flt, comps.n1, expected_ns[i].n1, EPSILON));
		cr_assert(epsilon_eq(flt, comps.n2, expected_ns[i].n2, EPSILON));
		comps = (t_precomp){0};
		xs.i = xs.i->next;
		i++;
	}

	clean_intersection_lst(&list.i);
	clean_shape(&A);
	clean_shape(&B);
	clean_shape(&C);
}