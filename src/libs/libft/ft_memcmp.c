/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotakesh <rotakesh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:00:17 by rotakesh          #+#    #+#             */
/*   Updated: 2022/01/19 14:42:22 by rotakesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				count;
	const unsigned char	*s1;
	const unsigned char	*s2;

	count = 0;
	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	if (s1 == s2 || n == 0)
		return (0);
	while (count < n)
	{
		if (s1[count] == s2[count])
			count++;
		else if (s1[count] != s2[count])
			return (s1[count] - s2[count]);
	}
	return (0);
}
