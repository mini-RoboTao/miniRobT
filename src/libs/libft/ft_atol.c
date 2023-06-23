/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:33:34 by dapaulin          #+#    #+#             */
/*   Updated: 2023/06/18 16:36:37 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_signdetect(int c, int *pos)
{	
	if (c == '-')
		return (*pos += 1, -1);
	else if (c == '+')
		return (*pos += 1, 1);
	return (1);
}

long	ft_atol(const char *nptr)
{
	int			pos;
	long		nbr;
	int			sign;

	pos = 0;
	while (ft_isspace(nptr[pos]))
		pos++;
	sign = ft_signdetect(nptr[pos], &pos);
	nbr = 0;
	while (ft_isdigit(nptr[pos]))
	{
		nbr *= 10;
		nbr += (nptr[pos] - '0');
		pos++;
	}
	return (nbr * sign);
}
