/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 01:51:41 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/03 15:43:05 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

const t_matrix	empty_matrix	=	(t_matrix){.node = { 					\
									{0, 0, 0, 0},							\
									{0, 0, 0, 0},							\
									{0, 0, 0, 0},							\
									{0, 0, 0, 0},							\
									}, .x = 0, .y = 0};

const t_matrix 	mult4x4			=	(t_matrix){.node = { 					\
									{20, 22, 50, 48},						\
									{44, 54, 114, 108},						\
									{40, 58, 110, 102},						\
									{16, 26, 46, 42},						\
									}, .x = 4, .y = 4};

Test(matrix_operations, multiply_two_matrix4x4_should_be_matrix_mult4x4)
{
	t_matrix	ma				=	(t_matrix){.node = { 					\
									{1, 2, 3, 4},							\
									{5, 6, 7, 8},							\
									{9, 8, 7, 6},							\
									{5, 4, 3, 2},							\
									}, .x = 4, .y = 4};
	t_matrix	mb				=	(t_matrix){.node = { 					\
									{-2, 1, 2, 3},							\
									{3, 2, 1, -1},							\
									{4, 3, 6, 5},							\
									{1, 2, 7, 8},							\
									}, .x = 4, .y = 4};
	t_matrix	result;

	result = multiply_matrix(ma, mb, 4, 4);
	cr_assert(cr_matrix_eq(mult4x4, result));
}

Test(matrix_operations, multiply_a_matrix4x4_by_a_obj_should_be_exp_obj)
{
	t_obj		exp_obj		=	(t_obj){.x=18, .y=24, .z=33, .w=1};
	t_obj		obj			=	(t_obj){.x=1, .y=2, .z=3, .w=1};
	t_matrix	ma			=	(t_matrix){.node = { 		\
								{1, 2, 3, 4},				\
								{2, 4, 4, 2},				\
								{8, 6, 4, 1},				\
								{0, 0, 0, 1},				\
								}, .x = 4, .y = 4};
	t_obj		result;

	result = multiply_matrix_by_obj(ma, obj, 4, 4);
	cr_assert(cr_object_eq(exp_obj, result));
}

// Multiply a matrix by a identity matrix should be itself
Test(matrix_operations, multiply_a_matrix4x4_by_a_identity_matrix_should_be_itself)
{
	t_matrix	ma			=	(t_matrix){.node = { 		\
								{0, 1, 2, 4},				\
								{1, 2, 4, 8},				\
								{2, 4, 8, 16},				\
								{4, 8, 16, 32},				\
								}, .x = 4, .y = 4};
	t_matrix	result;

	result = multiply_matrix(ma, create_identity_matrix(), 4, 4);
	cr_assert(cr_matrix_eq(ma, result));
}

Test(matrix_operations, transposing_a_matrix4x4_col_should_row_and_row_should_col)
{
	t_matrix	ma			=	(t_matrix){.node = { 		\
								{0, 9, 3, 0},				\
								{9, 8, 0, 8},				\
								{1, 8, 5, 3},				\
								{0, 0, 5, 8},				\
								}, .x = 4, .y = 4};
	t_matrix	expt		=	(t_matrix){.node = { 		\
								{0, 9, 1, 0},				\
								{9, 8, 8, 0},				\
								{3, 0, 5, 5},				\
								{0, 8, 3, 8},				\
								}, .x = 4, .y = 4};
	t_matrix	result;

	result = transpose_matrix(ma);
	cr_assert(cr_matrix_eq(expt, result));
}

Test(matrix_operations, transposing_a_matrix4x4_identity_should_be_a_identity_matrix)
{
	t_matrix	result;

	result = transpose_matrix(create_identity_matrix());
	cr_assert(cr_matrix_eq(create_identity_matrix(), result));
}

Test(matrix_operations, transposing_a_NULL_should_be_NULL)
{
	t_matrix	result;

	result = transpose_matrix(empty_matrix);
	cr_assert(cr_matrix_eq(empty_matrix, result));
}

/* // Test(matrix_operations, multiply_a_null_matrix4x4_and_another_with_values_should_be_empty_matrix)
// {
// 	t_matrix	m		=	(t_matrix){.node = {{-2, 1, 2, 3},{3, 2, 1, -1},{4, 3, 6, 5},{1, 2, 7, 8},},.x = 4, .y = 4};
// 	t_matrix	exp		=	(t_matrix)empty_matrix;
// 	t_matrix	result;

// 	result = multiply_matrix(empty_matrix, m, 4, 4);
// 	cr_assert(cr_matrix_eq(empty_matrix , result));
// 	result = multiply_matrix(m, empty_matrix, 4, 4);
// 	cr_assert(cr_matrix_eq(empty_matrix, result));
// } */

// Test(matrix_operations, multiply_a_null_matrix4x4_by_a_obj_should_be_NULL)
// {
// 	t_obj		exp_obj	=	NULL;
// 	t_obj		obj		=	(t_obj){.x=1, .y=2, .z=3, .w=1};
// 	t_matrix	*ma			=	NULL;
// 	t_obj		result;

// 	result = multiply_matrix_by_obj(ma, obj, 4, 4);
// 	cr_assert(eq(exp_obj, result));
// }

// Test(matrix_operations, multiply_a_matrix4x4_by_a_null_obj_should_be_NULL)
// {
// 	t_obj		*exp_obj	=	NULL;
// 	t_obj		*obj		=	NULL;
// 	t_matrix	*ma			=	&(t_matrix){.node = {{1, 2, 3, 4}, {2, 4, 4, 2}, {8, 6, 4, 1}, {0, 0, 0, 1}, }, .x = 4, .y = 4};
// 	t_obj		*result;

// 	result = multiply_matrix_by_obj(ma, obj, 4, 4);
// 	cr_assert(eq(exp_obj, result));
// }