/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_feature.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:11:05 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/09 13:33:25 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_FEATURE_H
# define SHAPE_FEATURE_H

# include "minirt.h"

t_shape	test_shape(void);

// Sphere
void	intersect_sphere(t_intersections *xs, t_shape shape, t_ray ray);
t_obj	normal_at_sphere(t_shape shape, t_obj world_point);
t_shape	new_sphere(void);
t_shape	glass_sphere(void);

//Plane
void	intersect_plane(t_intersections *xs, t_shape shape, t_ray ray);
t_obj	normal_at_plane(t_shape shape, t_obj world_point);
t_shape	new_plane(void);

// Cube
t_shape	new_cube(void);
void	intersect_cube(t_intersections *xs, t_shape cube, t_ray ray);
double	*check_axis(double origin, double direction);
t_obj	normal_at_cube(t_shape cube, t_obj point);

// Cylinder
t_shape	new_cylinder(void);
void	intersect_cylinder(t_intersections *xs, t_shape cylinder, t_ray ray);
t_obj	normal_at_cylinder(t_shape cylinder, t_obj point);

// Cap cylinder
double	check_cap(t_ray ray, double t);
void	intersect_caps(t_intersections *xs, t_shape cylinder, t_ray ray);

#endif