/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:08:19 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/17 21:24:58 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_a_light(t_world *world, t_define_a_light al)
{
	world->a_light = al;
}

void	fill_light(t_world *world, t_define_light l)
{
	world->light = point_light(l.position, multiply_scalar_colors(l.color, l.intensity));
	// world->light = point_light(l.position, l.color);
}
