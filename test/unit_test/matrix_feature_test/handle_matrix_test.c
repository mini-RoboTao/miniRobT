/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_matrix_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:31:37 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/31 23:34:59 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

const t_matrix	*exp4x4		=	&(t_matrix){.node = (double *[]){ 	\
							(double []){1, 2, 3, 4},				\
							(double []){5.5, 6.5, 7.5, 8.5},		\
							(double []){9, 10, 11, 12},				\
							(double []){13.5, 14.5, 15.5, 16.5},	\
							}, .x = 4, .y = 4};

const t_matrix	*exp2x2		=	&(t_matrix){.node = (double *[]){ 	\
							(double []){-3, 5},						\
							(double []){1, -2},						\
							}, .x = 2, .y = 2};

const t_matrix	*exp3x3		=	&(t_matrix){.node = (double *[]){ 	\
							(double []){-3, 5, 0},					\
							(double []){1, -2, -7},					\
							(double []){0, 1, 1},					\
							}, .x = 3, .y = 3};

const t_matrix	*nexp3x3	=	&(t_matrix){.node = (double *[]){ 	\
							(double []){-3, 5, 0},					\
							(double []){1, -2, -7},					\
							(double []){0, 1, 20},					\
							}, .x = 3, .y = 3};

const char		*values4x4[]	= (const char *[]){STRITEM("1", "2", "3", "4"), \
										STRITEM("5.5", "6.5", "7.5", "8.5"), \
										STRITEM("9", "10", "11", "12"), \
										STRITEM("13.5", "14.5", "15.5", "16.5"), NULL};

const char		*values2x2[]	= (const char *[]){STRITEM("-3", "5", "1", "-2"), NULL};

const char		*values3x3[]	= (const char *[]){STRITEM("-3", "5", "0", "1"), \
										STRITEM("-2", "-7", "0", "1"), (char []){"1"}, NULL};

Test(matrix, create_a_matrix4x4_should_be_sucess)
{
	t_matrix	*result;
	int			rows		= 4;
	int			colums		= 4;

	result = create_matrix((char **)values4x4, colums, rows);
	cr_assert(cr_matrix_eq((t_matrix *)exp4x4, result));
	clean_matrix(result);
}

Test(matrix, create_a_matrix4x4_and_pass_values_pointer_NULL_should_be_NULL)
{
	t_matrix	*result;
	int			rows		= 4;
	int			colums		= 4;
	char		**list		= NULL;
	t_matrix	*exp		= NULL;

	result = create_matrix(list, colums, rows);
	cr_assert(eq(exp, result));
	result = create_matrix((char **){NULL}, colums, rows);
	cr_assert(eq(exp, result));
}

Test(matrix, create_a_matrix2x2_should_be_sucess)
{
	t_matrix	*result;
	int			rows		= 2;
	int			colums		= 2;

	result = create_matrix((char **)values2x2, colums, rows);
	cr_assert(cr_matrix_eq((t_matrix *)exp2x2, result));
	clean_matrix(result);
}

Test(matrix, create_a_matrix3x3_should_be_sucess)
{
	t_matrix	*result;
	int			rows		= 3;
	int			colums		= 3;

	result = create_matrix((char **)values3x3, colums, rows);
	cr_assert(cr_matrix_eq((t_matrix *)exp3x3, result));
	clean_matrix(result);
}

Test(matrix, compare_a_matrix3x3_with_eq_values_should_be_true)
{
	t_matrix	*ma			= (t_matrix *)exp3x3;
	t_matrix	*mb			= (t_matrix *)exp3x3;
	int			expected	= 1;
	int			result;

	result = matrix_cmp(ma, mb);
	cr_assert(eq(expected, result));
}

Test(matrix, compare_a_matrix3x3_with_neq_values_should_be_false)
{
	t_matrix	*ma			= (t_matrix *)exp3x3;
	t_matrix	*mb			= (t_matrix *)nexp3x3;
	int			expected	= 0;
	int			result;

	result = matrix_cmp(ma, mb);
	cr_assert(eq(expected, result));
}

Test(matrix, compare_a_matrix3x3_with_NULL_values_should_be_false)
{
	t_matrix	*ma			= NULL;
	t_matrix	*mb			= (t_matrix *)exp3x3;
	int			expected	= 0;
	int			result;

	result = matrix_cmp(ma, mb);
	cr_assert(eq(expected, result));
	result = matrix_cmp(mb, ma);
	cr_assert(eq(expected, result));
	result = matrix_cmp(ma, ma);
	cr_assert(eq(1, result));
}
