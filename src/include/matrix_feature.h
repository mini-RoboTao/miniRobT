/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_feature.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:20:25 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/28 05:07:36 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_FEATURE_H
# define MATRIX_FEATURE_H

# include "minirt.h"

// handle matrix
t_matrix	*alloc_matrix(int col, int row);
t_matrix	*create_matrix(char **values, int x, int y);
t_matrix	*create_identity_matrix(void);
int			matrix_cmp(t_matrix *a, t_matrix *b);

// Matrix operations
t_matrix	*multiply_matrix(t_matrix *ma, t_matrix *mb, int nrow, int ncol);
t_obj		multiply_matrix_by_obj(t_matrix *m, t_obj obj, int col, int row);
t_matrix	*transpose_matrix(t_matrix *ma);

// Inverting Matrix
t_matrix	*find_submatrix(t_matrix *m, int row, int col);
t_matrix	*inverse_matrix(t_matrix *m);

// Matrix utils
double		determinant(t_matrix *m);
double		minor(t_matrix *m, int row, int col);
double		cofactor(t_matrix *m, int row, int col);
int			matrix_is_invertible(t_matrix *m);

#endif