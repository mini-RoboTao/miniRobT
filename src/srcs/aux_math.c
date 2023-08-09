/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 06:37:00 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/09 06:41:00 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	min_three(double a, double b, double c)
{
	double	res;

	if (a < b)
		res = a;
	else
		res = b;
	if (c < res)
		res = c;
	return (res);
}

double	max_three(double a, double b, double c)
{
	double	res;

	if (a > b)
		res = a;
	else
		res = b;
	if (c > res)
		res = c;
	return (res);
}

void	swap_double(double *min, double *max)
{
	double	temp;

	temp = *min;
	*min = *max;
	*max = temp;
}
