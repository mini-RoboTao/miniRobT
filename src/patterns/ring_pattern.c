/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_pattern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:45:22 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/10 03:36:05 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pattern	ring_pattern(t_color a, t_color b)
{
	t_pattern	pattern;

	pattern.a = a;
	pattern.b = b;
	pattern.validate = true;
	pattern.type = ring;
	pattern.transform = create_identity_matrix();
	return (pattern);
}

t_color	ring_at(t_pattern pattern, t_obj point)
{
	int	mod;

	mod = floor(sqrt(pow(point.x, 2) + pow(point.z, 2)));
	if ((mod % 2) == 0)
		return (pattern.a);
	return (pattern.b);
}
