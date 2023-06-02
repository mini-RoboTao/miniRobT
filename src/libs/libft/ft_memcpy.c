/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:00:15 by rotakesh          #+#    #+#             */
/*   Updated: 2022/01/19 14:43:00 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*temp;
	size_t		i;

	temp = dest;
	i = 0;
	s = src;
	while (i < n)
	{
		temp[i] = s[i];
		i++;
	}
	return (dest);
}
