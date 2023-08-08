/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_feature.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:11:05 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/08 12:49:06 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_FEATURE_H
# define SHAPE_FEATURE_H

# include "minirt.h"

t_shape			test_shape(void);

// Sphere
t_intersections	intersect_sphere(t_shape shape, t_ray ray);
t_obj			normal_at_sphere(t_shape shape, t_obj world_point);
t_shape			new_sphere(void);
t_shape			glass_sphere(void);

//Plane
t_intersections	intersect_plane(t_shape shape, t_ray ray);
t_obj			normal_at_plane(t_shape shape, t_obj world_point);
t_shape			new_plane(void);

// Sphere

#endif