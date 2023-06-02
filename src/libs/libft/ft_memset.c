/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:00:10 by rotakesh          #+#    #+#             */
/*   Updated: 2022/01/19 14:44:50 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int value, size_t len)
{
	char				*pointer;
	unsigned long		i;

	i = 0;
	pointer = dest;
	while (i < len)
	{
		pointer[i] = value;
		i++;
	}
	return (dest);
}
