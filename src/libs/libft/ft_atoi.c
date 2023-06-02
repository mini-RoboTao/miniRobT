/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:48:29 by rotakesh          #+#    #+#             */
/*   Updated: 2022/01/19 20:39:40 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_neg(int number, int nbr)
{
	if (number % 2 == 1)
		nbr *= -1;
	return (nbr);
}

int	ft_atoi(const char *str)
{
	int	nbr;
	int	i;
	int	negative;

	i = 0;
	nbr = 0;
	negative = 0;
	while ((str[i] > 6 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' && str[i + 1] > 47 && str[i + 1] < 58)
	{
		negative++;
		i++;
	}
	if (str[i] == '+' && str[i + 1] > 47 && str[i + 1] < 58)
		i++;
	while (str[i] != '\0' && (str[i] > 47 && str[i] < 58))
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	return (ft_is_neg(negative, nbr));
}
