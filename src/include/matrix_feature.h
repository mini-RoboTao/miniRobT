/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_feature.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:20:25 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/06 03:41:05 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_FEATURE_H
# define MATRIX_FEATURE_H

# include "minirt.h"

// handle matrix
t_matrix	*alloc_matrix(int col, int row);
t_matrix	*create_matrix(char **values, int x, int y);
int			matrix_cmp(t_matrix *a, t_matrix *b);

// Matrix operations
t_matrix	*multiply_matrix(t_matrix *ma, t_matrix *mb, int nrow, int ncol);
t_obj		*multiply_matrix_by_obj(t_matrix *m, t_obj *obj, int col, int row);
t_matrix	*transpose_matrix(t_matrix *ma);

#endif