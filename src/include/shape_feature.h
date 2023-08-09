/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_feature.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:11:05 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/09 06:39:11 by rotakesh         ###   ########.fr       */
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

// Cube

t_shape			new_cube(void);
t_intersections	intersect_cube(t_shape cube, t_ray ray);
double			*check_axis(double origin, double direction);
t_obj			normal_at_cube(t_shape cube, t_obj point);

#endif