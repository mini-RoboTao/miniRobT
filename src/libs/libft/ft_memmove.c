/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:00:12 by rotakesh          #+#    #+#             */
/*   Updated: 2022/01/19 15:06:38 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (str1 > str2)
	{
		while (n > 0)
		{
			((char *)str1)[n - 1] = ((char *)str2)[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			((char *)str1)[i] = ((char *)str2)[i];
			i++;
		}
	}
	return (str1);
}
