/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:19:10 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/13 00:15:27 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_TRANSFORMATIONS_H
# define MATRIX_TRANSFORMATIONS_H

# include "minirt.h"

// TRANSLATION
int	translation(t_matrix *matrix, double x, double y, double z);

// SCALING
int	scaling(t_matrix *matrix, double x, double y, double z);

// ROTATION
int	rotation_x(t_matrix *matrix, double r);
int	rotation_y(t_matrix *matrix, double r);
int	rotation_z(t_matrix *matrix, double r);

// SHEARING
int	shearing(t_matrix *matrix, t_shearing shearing_points);

#endif