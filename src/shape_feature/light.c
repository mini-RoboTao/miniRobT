/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:08:19 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/16 21:34:50 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_a_light(t_world *world, t_define_a_light al)
{
	world->a_light = multiply_scalar_colors(al.color, al.intensity);
}

void	fill_light(t_world *world, t_define_light l)
{
	world->light = point_light(l.position, l.color);
}
