#include "unit_test.h"

Test(inverting_matrix, test_apply_determine_in_a_matrix2x2)
{
	t_matrix *m2x2		=	&(t_matrix){.node = (double *[]){ 	\
						(double []){1, 5},					\
						(double []){-3, 2},					\
						}, .x = 2, .y = 2};
	double	expected	= 17;
	double	result;

	result = determinant(m2x2);
	cr_assert(eq(expected, result));
}

Test(inverting_matrix, test_apply_determine_in_a_null_matrix)
{
	t_matrix *m2x2		=	NULL;
	double	expected	= 0;
	double	result;

	result = determinant(m2x2);
	cr_assert(eq(expected, result));
}

Test(inverting_matrix, test_calculate_a_minor_of_a_matrix4x4)
{
	t_matrix *m3x3		=	&(t_matrix){.node = (double *[]){ 	\
						(double []){3, 5, 0},					\
						(double []){2, -1, -7},					\
						(double []){6, -1, 5},					\
						}, .x = 3, .y = 3};
	t_matrix	*m2x2;
	double		exp1	= 25;
	double		result;

	m2x2 = find_submatrix(m3x3, 1, 0);
	result = determinant(m2x2);
	cr_assert(eq(exp1, result));
	result = minor(m3x3, 1, 0);
	cr_assert(eq(exp1, result));
	clean_matrix(m2x2);
}

Test(inverting_matrix, test_calculate_a_cofactor_of_a_matrix3x3)
{
	t_matrix *m3x3		=	&(t_matrix){.node = (double *[]){ 	\
						(double []){3, 5, 0},					\
						(double []){2, -1, -7},					\
						(double []){6, -1, 5},					\
						}, .x = 3, .y = 3};

	cr_assert(epsilon_eq(flt, -12, minor(m3x3, 0, 0), EPSILON));
	cr_assert(epsilon_eq(flt, -12, cofactor(m3x3, 0, 0), EPSILON));
	cr_assert(epsilon_eq(flt, 25, minor(m3x3, 1, 0), EPSILON));
	cr_assert(epsilon_eq(flt, -25, cofactor(m3x3, 1, 0), EPSILON));
}

Test(inverting_matrix, test_calculate_the_determinat_of_a_matrix3x3)
{
	t_matrix *m3x3		=	&(t_matrix){.node = (double *[]){ 	\
						(double []){1, 2, 6},					\
						(double []){-5, 8, -4},					\
						(double []){2, 6, 4},					\
						}, .x = 3, .y = 3};

	cr_assert(epsilon_eq(flt, 56, cofactor(m3x3, 0, 0), EPSILON));
	cr_assert(epsilon_eq(flt, 12, cofactor(m3x3, 0, 1), EPSILON));
	cr_assert(epsilon_eq(flt, -46, cofactor(m3x3, 0, 2), EPSILON));
	cr_assert(epsilon_eq(flt, -196, determinant(m3x3), EPSILON));
}

Test(inverting_matrix, test_calculate_the_determinat_of_a_matrix4x4)
{
	t_matrix *m3x3		=	&(t_matrix){.node = (double *[]){ 	\
						(double []){-2, -8, 3, 5},					\
						(double []){-3, 1, 7, 3},					\
						(double []){1, 2, -9, 6},					\
						(double []){-6, 7, 7, -9},					\
						}, .x = 4, .y = 4};

	cr_assert(epsilon_eq(flt, 690, cofactor(m3x3, 0, 0), EPSILON));
	cr_assert(epsilon_eq(flt, 447, cofactor(m3x3, 0, 1), EPSILON));
	cr_assert(epsilon_eq(flt, 210, cofactor(m3x3, 0, 2), EPSILON));
	cr_assert(epsilon_eq(flt, 51, cofactor(m3x3, 0, 3), EPSILON));
	cr_assert(epsilon_eq(flt, -4071, determinant(m3x3), EPSILON));
}

Test(inverting_matrix, check_the_invertibily_of_a_matrix4x4_should_be_invertible)
{
	t_matrix *m4x4		=	&(t_matrix){.node = (double *[]){ 	\
						(double []){6, 4, 4, 4},					\
						(double []){5, 5, 7, 6},					\
						(double []){4, -9, 3, -7},					\
						(double []){9, 1, 7, -6},					\
						}, .x = 4, .y = 4};


	cr_assert(eq(1, matrix_is_invertible(m4x4)));
}

Test(inverting_matrix, check_the_invertibily_of_a_matrix4x4_should_be_noninvertible)
{
	t_matrix *m4x4		=	&(t_matrix){.node = (double *[]){ 	\
						(double []){-4, 2, -2, -3},					\
						(double []){9, 6, 2, 6},					\
						(double []){0, -5, 1, -5},					\
						(double []){0, 0, 0, -0},					\
						}, .x = 4, .y = 4};


	cr_assert(eq(0, matrix_is_invertible(m4x4)));
}
