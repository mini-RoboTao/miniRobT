#include "unit_test.h"

// Test(inverting_matrix, test_submatrix_of_a_matrix3x3)
// {
// 	t_matrix *m3x3		=	&(t_matrix){.node = (double *[]){ 	\
// 						(double []){1, 5, 0},					\
// 						(double []){-3, 2, 7},					\
// 						(double []){0, 6, -3},					\
// 						}, .x = 3, .y = 3};
// 	t_matrix *expected	=	&(t_matrix){.node = (double *[]){ 	\
// 						(double []){-3, 2},					\
// 						(double []){0, 6},					\
// 						}, .x = 2, .y = 2};
// 	t_matrix	*result;

// 	result = find_submatrix(m3x3, 0, 2);
// 	cr_assert(cr_matrix_eq(expected, result));
// 	clean_matrix(result);
// }

// Test(inverting_matrix, test_submatrix_of_a_matrix4x4)
// {
// 	t_matrix *m4x4		=	&(t_matrix){.node = (double *[]){ 	\
// 						(double []){-6, 1, 1, 6},					\
// 						(double []){-8, 5, 8, 6},					\
// 						(double []){-1, 0, 8, 2},					\
// 						(double []){-7, 1, -1, 1},					\
// 						}, .x = 4, .y = 4};
// 	t_matrix *expected	=	&(t_matrix){.node = (double *[]){ 	\
// 						(double []){-6, 1, 6},					\
// 						(double []){-8, 8, 6},					\
// 						(double []){-7, -1, 1},					\
// 						}, .x = 3, .y = 3};
// 	t_matrix	*result;

// 	result = find_submatrix(m4x4, 2, 1);
// 	cr_assert(cr_matrix_eq(expected, result));
// 	clean_matrix(result);
// }

// Test(inverting_matrix, test_submatrix_of_a_null_should_be_NULL)
// {
// 	t_matrix *m			=	NULL;
// 	t_matrix *expected	=	NULL;
// 	t_matrix	*result;

// 	result = find_submatrix(m, 2, 1);
// 	cr_assert(eq(expected, result));
// }

// Test(inverting_matrix, calculating_the_inverse_of_a_matrix)
// {
// 	t_matrix *m4x4	=	&(t_matrix){.node = (double *[]){ 	\
// 					(double []){-5, 2, 6, -8},					\
// 					(double []){1, -5, 1, 8},					\
// 					(double []){7, 7, -6, -7},					\
// 					(double []){1, -3, 7, 4},					\
// 					}, .x = 4, .y = 4};
// 	t_matrix *exp	=	&(t_matrix){.node = (double *[]){ 	\
// 					(double []){0.21805, 0.45113, 0.24060, -0.04511},					\
// 					(double []){-0.80827, -1.45677, -0.44361, 0.52068},					\
// 					(double []){-0.07895, -0.22368, -0.05263, 0.19737},					\
// 					(double []){-0.52256, -0.81391, -0.30075, 0.30639},					\
// 					}, .x = 4, .y = 4};
// 	t_matrix *mb;

// 	mb = inverse_matrix(m4x4);
// 	cr_assert(cr_matrix_eq(exp, mb));
// 	clean_matrix(mb);
// }

// Test(inverting_matrix, calculating_the_another_inverse_of_a_matrix)
// {
// 	t_matrix *m4x4	=	&(t_matrix){.node = (double *[]){ 	\
// 					(double []){8, -5, 9, 2},					\
// 					(double []){7, 5, 6, 1},					\
// 					(double []){-6, 0, 9, 6},					\
// 					(double []){-3, 0, -9, -4},					\
// 					}, .x = 4, .y = 4};
// 	t_matrix *exp	=	&(t_matrix){.node = (double *[]){ 	\
// 					(double []){-0.15385, -0.15385, -0.28205, -0.53846},					\
// 					(double []){-0.07692, 0.12308, 0.02564, 0.03077},					\
// 					(double []){0.35897, 0.35897, 0.43590, 0.92308},					\
// 					(double []){-0.69231, -0.69231, -0.76923, -1.92308},					\
// 					}, .x = 4, .y = 4};
// 	t_matrix *mb;

// 	mb = inverse_matrix(m4x4);
// 	cr_assert(cr_matrix_eq(exp, mb));
// 	clean_matrix(mb);
// }

// Test(inverting_matrix, calculating_the_third_inverse_of_a_matrix)
// {
// 	t_matrix *m4x4	=	&(t_matrix){.node = (double *[]){ 	\
// 					(double []){9, 3, 0, 9},					\
// 					(double []){-5, -2, -6, -3},					\
// 					(double []){-4, 9, 6, 4},					\
// 					(double []){-7, 6, 6, 2},					\
// 					}, .x = 4, .y = 4};
// 	t_matrix *exp	=	&(t_matrix){.node = (double *[]){ 	\
// 					(double []){-0.04074, -0.07778, 0.14444, -0.22222},					\
// 					(double []){-0.07778, 0.03333, 0.36667, -0.33333},					\
// 					(double []){-0.02901, -0.14630, -0.10926, 0.12963},					\
// 					(double []){0.17778, 0.06667, -0.26667, 0.33333},					\
// 					}, .x = 4, .y = 4};
// 	t_matrix *mb;

// 	mb = inverse_matrix(m4x4);
// 	cr_assert(cr_matrix_eq(exp, mb));
// 	clean_matrix(mb);
// }

// Test(inverting_matrix, multiplying_a_product_by_its_inverse)
// {
// 	t_matrix *ma	=	&(t_matrix){.node = (double *[]){ 	\
// 					(double []){3, -9, 7, 3},					\
// 					(double []){3, -8, 2, -9},					\
// 					(double []){-4, 4, 4, 1},					\
// 					(double []){-6, 5, -1, 1},					\
// 					}, .x = 4, .y = 4};
// 	t_matrix *mb	=	&(t_matrix){.node = (double *[]){ 	\
// 					(double []){8, 2, 2, 2},					\
// 					(double []){3, -1, 7, 0},					\
// 					(double []){7, 0, 5, 4},					\
// 					(double []){6, -2, 0, 5},					\
// 					}, .x = 4, .y = 4};
// 	t_matrix *mc;
// 	t_matrix *tmp[2];

// 	mc = multiply_matrix(ma, mb, ma->x, ma->y);
// 	tmp[0] = inverse_matrix(mb);
// 	tmp[1] = multiply_matrix(mc, tmp[0], mc->x, mc->y);
// 	cr_assert(cr_matrix_eq(tmp[1], ma));
// 	clean_matrix(tmp[0]);
// 	clean_matrix(tmp[1]);
// 	clean_matrix(mc);
// }
