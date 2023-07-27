#include "unit_test.h"

Test(view_transformation, the_transformation_matrix_for_the_default_orientation)
{
	t_obj		*from	=	create_point(0, 0, 0);
	t_obj		*to		=	create_point(0, 0, -1);
	t_obj		*up		=	create_vector(0, 1, 0);

	t_matrix	*t		=	view_transformation(from, to, up);
	cr_assert(cr_matrix_eq(t, IDENTITY_MATRIX));
	clean_obj(to);
	clean_obj(from);
	clean_matrix(t);
}

Test(view_transformation, a_view_trsnformation_matrix_looking_in_positive_z_direction)
{
	t_obj		*from			=	create_point(0, 0, 0);
	t_obj		*to				=	create_point(0, 0, 1);
	t_obj		*up				=	create_vector(0, 1, 0);
	t_matrix	*expected		= 	scaling(-1, 1, -1);

	t_matrix	*t		=	view_transformation(from, to, up);
	cr_assert(cr_matrix_eq(t, expected));
	clean_obj(to);
	clean_obj(from);
	clean_matrix(expected);
	clean_matrix(t);
}

Test(view_transformation, the_view_transformation_moves_the_world)
{
	t_obj		*from				=	create_point(0, 0, 8);
	t_obj		*to					=	create_point(0, 0, 0);
	t_obj		*up					=	create_vector(0, 1, 0);
	t_matrix	*expected		= 	translation(0, 0, -8);

	t_matrix	*t		=	view_transformation(from, to, up);
	cr_assert(cr_matrix_eq(t, expected));
	clean_obj(to);
	clean_obj(from);
	clean_matrix(expected);
	clean_matrix(t);
}

Test(view_transformation, an_arbitrary_view_transformation)
{
	t_obj		*from				=	create_point(1, 3, 2);
	t_obj		*to					=	create_point(4, -2, 8);
	t_obj		*up					=	create_vector(1, 1, 0);
	t_matrix	*expected			=	&(t_matrix){.node = (double *[]){ 		\
										(double []){-0.50709, 0.50709, 0.67612, -2.36643},				\
										(double []){0.76772, 0.60609, 0.12122, -2.82843},		\
										(double []){-0.35857, 0.59761, -0.71714, 0.00000},				\
										(double []){0.00000, 0.00000, 0.00000, 1.00000},	\
										}, .x = 4, .y = 4};

	t_matrix	*t					=	view_transformation(from, to, up);
	cr_assert(cr_matrix_eq(t, expected));
	clean_obj(to);
	clean_obj(from);
	clean_matrix(t);
}