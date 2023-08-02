/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 01:19:18 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/02 00:25:12 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clean_world(t_world w)
{
	clean_sphere(w.sphere[0]);
	clean_sphere(w.sphere[1]);
	if (w.sphere)
		free(w.sphere);
}
