/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:59:33 by rotakesh          #+#    #+#             */
/*   Updated: 2022/01/19 14:56:23 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	lenght;
	size_t	count;

	count = 0;
	lenght = ft_strlen(dest) + ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size <= dest_len)
	{
		return (size + ft_strlen(src));
	}
	while ((dest_len + count < size - 1) && src[count] != '\0')
	{
		dest[dest_len + count] = src[count];
		count++;
	}
	dest[dest_len + count] = '\0';
	return (lenght);
}
