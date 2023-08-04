/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 01:19:18 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/03 02:13:27 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clean_world(t_world w)
{
	clean_shape(&w.shapes[0]);
	clean_shape(&w.shapes[1]);
	if (w.shapes)
		free(w.shapes);
}
