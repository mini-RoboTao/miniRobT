/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:19:10 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/02 17:33:29 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_TRANSFORMATIONS_H
# define MATRIX_TRANSFORMATIONS_H

# include "minirt.h"

// TRANSLATION
t_matrix	translation(double x, double y, double z);

// SCALING
t_matrix	scaling(double x, double y, double z);

// ROTATION
t_matrix	rotation_x(double r);
t_matrix	rotation_y(double r);
t_matrix	rotation_z(double r);

// SHEARING
t_matrix	shearing(t_shearing shearing_points);

#endif