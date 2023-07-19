/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_feature.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:37:44 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/18 01:29:37 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_FEATURE_H
# define RAY_FEATURE_H

# include "minirt.h"

// handle ray
t_ray			*create_ray(t_obj *point, t_obj *vector);
t_obj			*cat_position(t_ray *ray, double t);

// intersections
t_sphere		*new_sphere(void);
t_intersections	intersect(t_sphere *s, t_ray *r);
t_intersection	*intersection(double t, void *s);
void			intersections(t_intersections *xs, \
				t_intersection *i1, t_intersection *i2);
t_intersection	*hit(t_intersections xs);

// Transforming
t_ray			*transform(t_ray *r, t_matrix *m);
void			set_transform(t_sphere *s, t_matrix *t);

#endif