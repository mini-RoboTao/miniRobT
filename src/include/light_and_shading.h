/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_and_shading.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:50:03 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/20 20:39:04 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_AND_SHADING_H
# define LIGHT_AND_SHADING_H

# include "minirt.h"

// t_obj	*normal_at(t_sphere *sphere, t_obj *point);
t_obj	*normal_at(t_sphere *sphere, t_obj *world_point);

#endif