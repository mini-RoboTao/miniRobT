/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 06:37:00 by rotakesh          #+#    #+#             */
/*   Updated: 2023/08/09 14:55:09 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	min_three(double a, double b, double c)
{
	double	res;

	res = b;
	if (a < res)
		res = a;
	if (c < res)
		res = c;
	return (res);
}

double	max_three(double a, double b, double c)
{
	double	res;

	res = b;
	if (a > res)
		res = a;
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
