/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_feature.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:11:05 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/17 22:50:55 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_FEATURE_H
# define SHAPE_FEATURE_H

# include "minirt.h"

t_shape		test_shape(void);

// Light
void		fill_a_light(t_world *world, t_define_a_light al);
void		fill_light(t_world *world, t_define_light l);
t_camera	new_camera(t_define_cam define);

// Sphere
void		intersect_sphere(t_intersections *xs, t_shape shape, t_ray ray);
t_obj		normal_at_sphere(t_shape shape, t_obj world_point);
void		fill_sphere(t_world *world, t_define_sphere s);
t_shape		new_sphere(void);
t_shape		glass_sphere(void);

//Plane
void		intersect_plane(t_intersections *xs, t_shape shape, t_ray ray);
t_obj		normal_at_plane(t_shape shape, t_obj world_point);
void		fill_plane(t_world *world, t_define_plane p);
t_shape		new_plane(void);

// Cube
double		*check_axis(double origin, double direction);
void		intersect_cube(t_intersections *xs, t_shape cube, t_ray ray);
t_obj		normal_at_cube(t_shape cube, t_obj point);
t_shape		new_cube(void);

// Cylinder
void		intersect_cylinder(t_intersections *xs, t_shape cylinder, \
			t_ray ray);
t_obj		normal_at_cylinder(t_shape cylinder, t_obj point);
void		fill_cylinder(t_world *world, t_define_cylinder c);
t_shape		new_cylinder(void);

// Cap cylinder
double		check_cap(t_ray ray, double t);
void		intersect_caps(t_intersections *xs, t_shape cylinder, t_ray ray);

// Cone
t_shape		new_cone(void);
void		intersect_cone(t_intersections *xs, t_shape cone, t_ray ray);
t_obj		normal_at_cone(t_shape cone, t_obj point);

// Cap cone
double		check_cone_cap(t_ray ray, double t, double minmax);
void		intersect_cone_caps(t_intersections *xs, t_shape cone, t_ray ray);

#endif