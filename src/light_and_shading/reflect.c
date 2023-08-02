/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 02:17:04 by rotakesh          #+#    #+#             */
/*   Updated: 2023/07/28 05:30:34 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	reflect(t_obj in, t_obj normal)
{
	double	dot_times_two;
	t_obj	normal_multiplied;
	t_obj	res;

	dot_times_two = 2 * object_dot(in, normal);
	normal_multiplied = multiply_object(normal, dot_times_two);
	res = subtract_objects(in, normal_multiplied);
	return (res);
}
