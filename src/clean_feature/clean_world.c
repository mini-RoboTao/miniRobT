/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 01:19:18 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/28 05:20:50 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clean_world(t_world w)
{
	// clean_obj(w.light->position);
	if (w.light)
		free(w.light);
	clean_sphere(w.sphere[0]);
	clean_sphere(w.sphere[1]);
	if (w.sphere)
		free(w.sphere);
}
