/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 22:03:19 by dapaulin          #+#    #+#             */
/*   Updated: 2023/07/05 22:11:14 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_atof(t_atof *data)
{
	data->nbr = 0;
	data->j = 10.0;
	data->negative = 0;
}

static double	ft_is_neg(int number, double nbr)
{
	if (number % 2 == 1)
		nbr *= -1;
	return (nbr);
}

double	ft_atof(const char *s)
{
	int			i;
	t_atof		data;

	i = 0;
	ft_init_atof(&data);
	if (s[i] == '-' && ((s[i + 1] > 47 && s[i + 1] < 58) || s[i + 1 == 46]))
	{
		data.negative++;
		i++;
	}
	while (s[i] != '\0' && (s[i] > 47 && s[i] < 58))
	{
		data.nbr = data.nbr * 10 + s[i] - 48;
		i++;
	}
	if (s[i] == 46)
		i++;
	while (s[i] != '\0' && (s[i] > 47 && s[i] < 58))
	{
		data.nbr = data.nbr + (s[i] - 48) / data.j;
		data.j = data.j * 10.0;
		i++;
	}
	return (ft_is_neg(data.negative, data.nbr));
}
