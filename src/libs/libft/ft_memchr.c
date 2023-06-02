/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:00:18 by rotakesh          #+#    #+#             */
/*   Updated: 2022/01/19 14:41:12 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*result;
	size_t	i;

	i = 0;
	result = (char *)str;
	while (i < n)
	{
		if (result[i] == (char)c)
			return (&result[i]);
		i++;
	}
	return (0);
}
