/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:20:58 by dapaulin          #+#    #+#             */
/*   Updated: 2023/08/07 23:08:41 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	glass_sphere(void)
{
	t_shape	shape;

	shape = new_sphere();
	shape.sphere->material.transparency = 1.0;
	shape.sphere->material.refractive_index = 1.5;
	return (shape);
}
