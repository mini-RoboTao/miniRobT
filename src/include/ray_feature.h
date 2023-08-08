/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_feature.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:37:44 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/08 11:45:59 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_FEATURE_H
# define RAY_FEATURE_H

# include "minirt.h"

// handle ray
t_ray			create_ray(t_obj point, t_obj vector);
t_obj			cat_position(t_ray ray, double t);

// intersections
double			calculate_discriminat(double *abc, t_ray ray);
t_intersections	intersect(t_shape shape, t_ray r);
t_intersection	*intersection(double t, t_shape shape, t_intersections *xs);
void			intersections(t_intersections *xs, \
				t_intersection *i1, t_intersection *i2, int index);
t_intersection	*hit(t_intersections xs);

// Transforming
t_ray			transform(t_ray r, t_matrix m);
void			set_transform(t_shape *s, t_matrix t);

#endif