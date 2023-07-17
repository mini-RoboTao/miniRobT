/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_feature.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:37:44 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/17 13:20:57 by dapaulin         ###   ########.fr       */
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
t_intersect		intersect(t_sphere *s, t_ray *r);
t_intersection	*intersection(double t, t_sphere *s);

#endif