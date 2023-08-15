/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_feature.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:12:23 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/15 15:29:49 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_FEATURE_H
# define WORLD_FEATURE_H

# include "minirt.h"

t_world			world(void);
t_world			default_world(void);
t_intersections	intersect_world(t_world *w, t_ray ray);
t_precomp		prepare_computations(t_intersection *i, t_ray r, \
				t_intersections *xs);
t_color			shade_hit(t_world *w, t_precomp *comps, int remaining);

// view transformation
t_color			color_at(t_world *w, t_ray r, int remaining);
t_matrix		view_transformation(t_obj from, t_obj to, t_obj up);

// camera
t_camera		camera(int hsize, int vsize, double fov);
t_camera		new_camera(t_define_cam define);
t_ray			ray_for_pixel(t_camera *c, double px, double py);
t_canvas		*render(t_world *w);
t_matrix		set_transform_cam(t_camera *cam, t_matrix t);

#endif