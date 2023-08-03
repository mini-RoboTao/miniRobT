#include "unit_test.h"

Test(inverting_matrix, test_submatrix_of_a_matrix3x3)
{
	t_matrix	m3x3		=	(t_matrix){.node = { 		\
								{1, 5, 0},					\
								{-3, 2, 7},					\
								{0, 6, -3},					\
								}, .x = 3, .y = 3};
	t_matrix	expected	=	(t_matrix){.node = { 		\
								{-3, 2},					\
								{0, 6},						\
								}, .x = 2, .y = 2};
	t_matrix	result;

	result = find_submatrix(m3x3, 0, 2);
	cr_assert(cr_matrix_eq(expected, result));
}

Test(inverting_matrix, test_submatrix_of_a_matrix4x4)
{
	t_matrix 	m4x4		=	(t_matrix){.node = { 		\
								{-6, 1, 1, 6},				\
								{-8, 5, 8, 6},				\
								{-1, 0, 8, 2},				\
								{-7, 1, -1, 1},				\
								}, .x = 4, .y = 4};
	t_matrix	expected	=	(t_matrix){.node = {		\
								{-6, 1, 6},					\
								{-8, 8, 6},					\
								{-7, -1, 1},				\
								}, .x = 3, .y = 3};
	t_matrix	result;

	result = find_submatrix(m4x4, 2, 1);
	cr_assert(cr_matrix_eq(expected, result));
}

// Test(inverting_matrix, test_submatrix_of_a_null_should_be_NULL)
// {
// 	t_matrix *m			=	NULL;
// 	t_matrix *expected	=	NULL;
// 	t_matrix	*result;

// 	result = find_submatrix(m, 2, 1);
// 	cr_assert(eq(expected, result));
// }

Test(inverting_matrix, calculating_the_inverse_of_a_matrix)
{
	t_matrix	m4x4	=	(t_matrix){.node = { 						\
						{-5, 2, 6, -8},								\
						{1, -5, 1, 8},								\
						{7, 7, -6, -7},								\
						{1, -3, 7, 4},								\
						}, .x = 4, .y = 4};
	t_matrix	exp	=	(t_matrix){.node = { 						\
						{0.21805, 0.45113, 0.24060, -0.04511},		\
						{-0.80827, -1.45677, -0.44361, 0.52068},	\
						{-0.07895, -0.22368, -0.05263, 0.19737},	\
						{-0.52256, -0.81391, -0.30075, 0.30639},	\
						}, .x = 4, .y = 4};
	t_matrix 	mb;

	mb = inverse_matrix(m4x4);
	cr_assert(cr_matrix_eq(exp, mb));
}

Test(inverting_matrix, calculating_the_another_inverse_of_a_matrix)
{
	t_matrix	m4x4	=	(t_matrix){.node = { 					\
						{8, -5, 9, 2},								\
						{7, 5, 6, 1},								\
						{-6, 0, 9, 6},								\
						{-3, 0, -9, -4},							\
						}, .x = 4, .y = 4};
	t_matrix	exp		=	(t_matrix){.node = { 					\
						{-0.15385, -0.15385, -0.28205, -0.53846},	\
						{-0.07692, 0.12308, 0.02564, 0.03077},		\
						{0.35897, 0.35897, 0.43590, 0.92308},		\
						{-0.69231, -0.69231, -0.76923, -1.92308},	\
						}, .x = 4, .y = 4};
	t_matrix	mb;

	mb = inverse_matrix(m4x4);
	cr_assert(cr_matrix_eq(exp, mb));
}

Test(inverting_matrix, calculating_the_third_inverse_of_a_matrix)
{
	t_matrix	m4x4	=	(t_matrix){.node = { 	\
							{9, 3, 0, 9},					\
							{-5, -2, -6, -3},					\
							{-4, 9, 6, 4},					\
							{-7, 6, 6, 2},					\
							}, .x = 4, .y = 4};
	t_matrix	exp		=	(t_matrix){.node = { 	\
							{-0.04074, -0.07778, 0.14444, -0.22222},					\
							{-0.07778, 0.03333, 0.36667, -0.33333},					\
							{-0.02901, -0.14630, -0.10926, 0.12963},					\
							{0.17778, 0.06667, -0.26667, 0.33333},					\
							}, .x = 4, .y = 4};
	t_matrix 	mb;

	mb = inverse_matrix(m4x4);
	cr_assert(cr_matrix_eq(exp, mb));
}

Test(inverting_matrix, multiplying_a_product_by_its_inverse)
{
	t_matrix  ma	=	(t_matrix){.node = { 	\
						{3, -9, 7, 3},					\
						{3, -8, 2, -9},					\
						{-4, 4, 4, 1},					\
						{-6, 5, -1, 1},					\
						}, .x = 4, .y = 4};
	t_matrix  mb	=	(t_matrix){.node = { 	\
						{8, 2, 2, 2},					\
						{3, -1, 7, 0},					\
						{7, 0, 5, 4},					\
						{6, -2, 0, 5},					\
						}, .x = 4, .y = 4};
	t_matrix result;

	result = 	multiply_matrix(	\
				multiply_matrix(ma, mb, ma.x, ma.y), \
				inverse_matrix(mb), 4, 4);
	cr_assert(cr_matrix_eq(result, ma));
}
