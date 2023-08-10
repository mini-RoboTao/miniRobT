/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_pattern.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:45:22 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/10 03:58:10 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pattern	checkers_pattern(t_color a, t_color b)
{
	t_pattern	pattern;

	pattern.a = a;
	pattern.b = b;
	pattern.validate = true;
	pattern.type = checkers;
	pattern.transform = create_identity_matrix();
	return (pattern);
}

t_color	checkers_at(t_pattern pattern, t_obj point)
{
	int	mod;

	mod = floor(point.x) + floor(point.y) + floor(point.z);
	if ((mod % 2) == 0)
		return (pattern.a);
	return (pattern.b);
}

t_pattern	alt_checkers_pattern(t_color a, t_color b)
{
	t_pattern	pattern;

	pattern.a = a;
	pattern.b = b;
	pattern.validate = true;
	pattern.type = alt_checkers;
	pattern.transform = create_identity_matrix();
	return (pattern);
}

t_color	alt_checkers_at(t_pattern pattern, t_obj point)
{
	int	mod;

	mod = fabs(point.x) + fabs(point.y) + fabs(point.z);
	if ((mod % 2) == 0)
		return (pattern.a);
	return (pattern.b);
}
