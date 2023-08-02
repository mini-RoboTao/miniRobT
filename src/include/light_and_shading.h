/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_shading.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:50:03 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/01 23:27:15 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_AND_SHADING_H
# define LIGHT_AND_SHADING_H

# include "minirt.h"

t_obj		normal_at(t_sphere *sphere, t_obj world_point);
t_obj		reflect(t_obj in, t_obj normal);
t_light		point_light(t_obj position, t_color intensity);
t_material	new_material(void);
t_color		lighting(t_lighting lig);
t_bool		is_shadowed(t_world *world, t_obj point);

#endif