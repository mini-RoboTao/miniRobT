/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_feature.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:17:03 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/02 16:28:16 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_FEATURE_H
# define CLEAN_FEATURE_H

# include "minirt.h"

// free feature
// void	clean_obj(t_obj *o);
void	clean_canvas(t_canvas *c);
// void	clean_env(t_environment *c);
// void	clean_proj(t_projectile *c);
void	*clean_matrix(t_matrix *m);
// void	clean_ray(t_ray *r);
void	clean_shape(union u_shape *s);
void	clean_sphere(t_sphere *s);
void	clean_ray_inter_shape(t_intersection **i, void **shape);
void	clean_world(t_world w);

#endif