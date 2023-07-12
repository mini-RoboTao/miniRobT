/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:19:10 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/12 20:34:57 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_TRANSFORMATIONS_H
# define MATRIX_TRANSFORMATIONS_H

# include "minirt.h"

int	translation(t_matrix *matrix, double x, double y, double z);
int	scaling(t_matrix *matrix, double x, double y, double z);
int	rotation_x(t_matrix *matrix, double r);
int	rotation_y(t_matrix *matrix, double r);

#endif